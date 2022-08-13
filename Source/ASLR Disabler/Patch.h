#ifndef PATCH_H
#define PATCH_H

#include <Windows.h>
#include <shellapi.h>

class Patch
{
public:
	static void FileDropHandler(WPARAM wParam);
private:
	static HANDLE hFile;

	static HANDLE GetFileContent(const char* lpFilePath);
	static void DisableASLR(const HANDLE hFileContent);
	static void PatchFile(const HANDLE hFileContent);
};

#endif