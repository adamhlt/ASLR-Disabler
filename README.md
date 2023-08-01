```
                     ___   _____ __    ____     ____  _            __    __       
                    /   | / ___// /   / __ \   / __ \(_)________ _/ /_  / /__  _____
                   / /| | \__ \/ /   / /_/ /  / / / / / ___/ __ `/ __ \/ / _ \/ ___/
                  / ___ |___/ / /___/ _, _/  / /_/ / (__  ) /_/ / /_/ / /  __/ / 
                 /_/  |_/____/_____/_/ |_|  /_____/_/____/\__,_/_.___/_/\___/_/  
                                                                       
                                                                      
                                      ASLR Disabler (x86 / x64)
                         Little utility for disabling the ASLR on PE files
```
<p align="center">
    <img src="https://img.shields.io/badge/language-C%2B%2B-%23f34b7d.svg?style=for-the-badge&logo=appveyor" alt="C++">
    <img src="https://img.shields.io/badge/platform-Windows-0078d7.svg?style=for-the-badge&logo=appveyor" alt="Windows">
    <img src="https://img.shields.io/badge/arch-x86-red.svg?style=for-the-badge&logo=appveyor" alt="x86">
    <img src="https://img.shields.io/badge/arch-x64-green.svg?style=for-the-badge&logo=appveyor" alt="x64">
</p>

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
