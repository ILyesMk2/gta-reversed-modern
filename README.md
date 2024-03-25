## Grand Theft Auto San Andreas Reverse Engineering Project:

**Build Status: [https://github.com/gta-reversed/gta-reversed-modern/actions?query=workflow%3ABuild](https://github.com/gta-reversed/gta-reversed-modern/actions?query=workflow%3ABuild)**

This project aims to fully reverse engineer Grand Theft Auto: San Andreas, ultimately creating a standalone executable by rewriting and documenting every game function.

### Project Overview

Building this project generates a DLL file that injects into GTA:SA using a compatible ASI loader. The injected code replaces in-game functions, allowing modifications through the reversed code. The ultimate goal is to achieve a complete reverse engineering of the game. 

**Current Progress:**

* Reversed Classes: Track progress here: docs/ReversedClasses.MD (**Note:** This documentation may require an update.)
* Estimated TBA

### Getting Started

**Prerequisites:**

* Visual Studio 2022/20 (Community Edition is sufficient)
* CMake {DEPRECATED}

**Development Environment Setup:**

1. **Clone the Repository:**
   ```bash
   git clone --recurse-submodules https://github.com/gta-reversed/gta-reversed-modern.git
   ```

2. **Choose Your Build Tool:**

   - **Premake5:**
     1. Run `premake5.bat`.
     2. Open the generated `gta_reversed.sln` and build using `CTRL + SHIFT + B`.

   - **CMake (Requires VS22):**
   - {DEPRECATED}

### Game Setup

**Required Files:**

* GTA San Andreas (Compact EXE)
* ASI Loader ([https://gtaforums.com/topic/523982-relopensrc-silents-asi-loader/](https://gtaforums.com/topic/523982-relopensrc-silents-asi-loader/))
* III.VC.SA.WindowedMode.asi ([https://github.com/ThirteenAG/III.VC.SA.WindowedMode/blob/master/README.md](https://github.com/ThirteenAG/III.VC.SA.WindowedMode/blob/master/README.md)), **dont install using Modloader**.!
* Mouse Fix (dinput8.dll) (included in the project's `contrib` folder)

**Installation:**

1. Run `install.py` with **administrator privileges** in the project's root directory (creates symbolic links on Windows).
2. Alternatively, install the files manually.
   - Download all required files in a single archive: [https://github.com/gta-reversed/gta-reversed-modern](https://github.com/gta-reversed/gta-reversed-modern)

**Important Note:** Using other plugins is strongly discouraged as they are not officially supported.

**Optional Environment Preparation:**

If you didn't run `install.py`, you can create symbolic links for `.asi` files to avoid copying them on every compilation.

1. Open a console with **administrator privileges** in the project directory.
2. Run `contrib\link_asi.bat` or right-click the file and choose "Run as administrator."
3. Follow the instructions provided in the command window.

### Contributing

For ideas on where to contribute, see this discussion: [https://github.com/gta-reversed](https://github.com/gta-reversed)

### Credits

**ILyesMk2 who implemented most of the Dev tools from GTA 5's recent src code leak... me :) !**

* Original project contributors ([https://github.com/gta-reversed](https://github.com/gta-reversed))
* Contributors to gtaforums.com discussions ([https://gtaforums.com/topic/194199-documenting-gta-sa-memory-addresses/page/49/](https://gtaforums.com/topic/194199-documenting-gta-sa-memory-addresses/page/49/))
* re3 team ([https://github.com/halpz/re3](https://github.com/halpz/re3))
* Everyone who has contributed to GTA:SA reverse engineering

**currently waiting pullrequest approval from the RE3 team**
