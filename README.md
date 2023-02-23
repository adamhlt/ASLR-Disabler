![Project Banner](https://user-images.githubusercontent.com/48086737/184554623-7075f004-1dc8-4661-afa9-387c327973f5.jpg)
# ASLR Disabler
[![C++](https://img.shields.io/badge/language-C%2B%2B-%23f34b7d.svg?style=for-the-badge&logo=appveyor)](https://en.wikipedia.org/wiki/C%2B%2B) [![Windows](https://img.shields.io/badge/platform-Windows-0078d7.svg?style=for-the-badge&logo=appveyor)](https://en.wikipedia.org/wiki/Microsoft_Windows) [![x86](https://img.shields.io/badge/arch-x86-red.svg?style=for-the-badge&logo=appveyor)](https://en.wikipedia.org/wiki/X86) [![x64](https://img.shields.io/badge/arch-x64-green.svg?style=for-the-badge&logo=appveyor)](https://en.wikipedia.org/wiki/X64)
## :open_book: Project Overview :
ASLR Disabler is a little utility to disable PE ASLR by just drag and drop the PE file.  
The UI of ASLR Disabler is based on one of my other project, [ImGUI Standalone](https://github.com/adamhlt/ImGui-Standalone).

The start of goal of this project was to easily disable ASLR on PE dumps, to make them run.

ASLR Disabler works with x86 and x64 PE.

## :rocket: Getting Started

> **Note** <br>
> Make sure that **DXSDK_DIR** is declared in your environment variables.

To see your environment variables :

> **Settings --> System --> About --> System Advanced Settings --> Environment Variables**

### Visual Studio :

1. Open the solution file (.sln).
2. Build the project in Release (x86 or x64)

Every configuration in x86 / x64 (Debug and Realese) are already configured with librairies and includes.

> **Warning** <br>
> If you have any linking error when compiling make sure that you have correctly install DirectX SDK.
## 🧪 Demonstration :

https://user-images.githubusercontent.com/48086737/184556007-c7513c8c-c89c-426a-b603-39db5f75fba3.mp4
