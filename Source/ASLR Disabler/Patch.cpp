﻿#include "Patch.h"

HANDLE Patch::hFile = nullptr;

/**
 * Function to retrieve information about dropped file and patch it.
 * \param wParam : structure wich store information about the file.
 */
void Patch::FileDropHandler(WPARAM wParam)
{
    char lpFilePath[MAX_PATH];
    DragQueryFileA((HDROP)wParam, 0, lpFilePath, MAX_PATH);

    const HANDLE hFileContent = GetFileContent(lpFilePath);
    if (hFileContent == nullptr)
        return;

    DisableASLR(hFileContent);
    PatchFile(hFileContent);

    CloseHandle(hFile);
    HeapFree(GetProcessHeap(), 0, hFileContent);
}

/**
 * Function to retrieve the PE file content.
 * \param lpFilePath : path of the PE file.
 * \return : address of the content in the explorer memory.
 */
HANDLE Patch::GetFileContent(const char* lpFilePath)
{
    hFile = CreateFileA(lpFilePath, GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        MessageBoxA(nullptr, "An error occured when trying to open the PE file !", "Error", MB_ICONERROR);
        CloseHandle(hFile);
        return nullptr;
    }

    const DWORD dFileSize = GetFileSize(hFile, nullptr);
    if (dFileSize == INVALID_FILE_SIZE)
    {
        MessageBoxA(nullptr, "An error occured when trying to get the PE file size !", "Error", MB_ICONERROR);
        CloseHandle(hFile);
        return nullptr;
    }

    const HANDLE hFileContent = HeapAlloc(GetProcessHeap(), 0, dFileSize);
    if (hFileContent == INVALID_HANDLE_VALUE)
    {
        MessageBoxA(nullptr, "An error occured when trying to allocate memory for the PE file content !", "Error", MB_ICONERROR);
        CloseHandle(hFile);
        CloseHandle(hFileContent);
        return nullptr;
    }

    const BOOL bFileRead = ReadFile(hFile, hFileContent, dFileSize, nullptr, nullptr);
    if (!bFileRead)
    {
        MessageBoxA(nullptr, "An error occured when trying to read the PE file content !", "Error", MB_ICONERROR);
        CloseHandle(hFile);
        if (hFileContent != nullptr)
            CloseHandle(hFileContent);

        return nullptr;
    }

    return hFileContent;
}

/**
 * Function to modify the PE to disable ASLR.
 * \param hFileContent : handle to the PE image content.
 */
void Patch::DisableASLR(const HANDLE hFileContent)
{
    const auto lpImageDOSHeader = (PIMAGE_DOS_HEADER)hFileContent;
    const auto lpImageNTHeader = (PIMAGE_NT_HEADERS32)((DWORD_PTR)lpImageDOSHeader + lpImageDOSHeader->e_lfanew);

    //Patch x86 PE
    if (lpImageNTHeader->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR32_MAGIC)
        if (lpImageNTHeader->OptionalHeader.DllCharacteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE)
            lpImageNTHeader->OptionalHeader.DllCharacteristics &= ~IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE;

    //Patch x64 PE
    if (lpImageNTHeader->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC)
    {
        const auto lpImageNTHeader64 = (PIMAGE_NT_HEADERS64)((DWORD_PTR)lpImageDOSHeader + lpImageDOSHeader->e_lfanew);
        if (lpImageNTHeader64->OptionalHeader.DllCharacteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE)
            lpImageNTHeader64->OptionalHeader.DllCharacteristics &= ~IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE;
    }
}

/**
 * Function to write the new PE image in the file.
 * \param hFileContent : handle to the PE image content.
 */
void Patch::PatchFile(const HANDLE hFileContent)
{
    const auto sBufferSize = (DWORD)HeapSize(GetProcessHeap(), 0, hFileContent);
    SetFilePointer(hFile, 0, nullptr, FILE_BEGIN);
    if (WriteFile(hFile, hFileContent, sBufferSize, nullptr, nullptr))
        MessageBoxA(nullptr, "ASLR successfully disabled !", "Success", MB_ICONINFORMATION);
    else
        MessageBoxA(nullptr, "An error is occured when trying to write the file !", "Error", MB_ICONERROR);
}