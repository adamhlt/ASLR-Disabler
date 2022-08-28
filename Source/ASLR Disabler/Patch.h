#ifndef PATCH_H
#define PATCH_H

#include <Windows.h>
#include <ImageHlp.h>

class Patch
{
public:
	static void FileDropHandler(WPARAM wParam);
private:
	static HANDLE hFile;

	static HANDLE GetFileContent(const char* lpFilePath);
	static DWORD ComputeChecksum(LPVOID lpImage, DWORD dwBufferSize);
	static int DisableASLR(const HANDLE hFileContent);
	static void PatchFile(const HANDLE hFileContent);
};

#endif