# GBADev

This repo is a test of GBA game development in the C language. To develop GBA games yourself you will need to install the following tools:

- Devkit Pro:  https://devkitpro.org/
- Programmer's Notepad:  https://www.pnotepad.org/
- VisualBoyAdvance : https://visualboyadvance.en.softonic.com/

## Setup
This setup guide is for the Windows Operating system and follows instructions given by `Jonathan Richards: GameBoy Advance Programming Initial Setup Tutorial` [YouTube Video](https://www.youtube.com/watch?v=2FZGD1i6QZY&ab_channel=JonathanRichards)

http://www.coranac.com/tonc/text/toc.htm

1. Create a working dir with a `source` and `include` folder
    - `include` will hold the `header (.h)` files.
    - `source` will hold the `source (.c / .cpp)` files.
2. Setup Programmer's Notepad Shortcuts
    - tools > options > Tools > Scheme > C/C++
    - Create the `make` and `clean` commands with the following parameters

        ```
        make: 
        {
            Name: make, 
            Command: make, 
            Folder: $(ProjectPath),
            Shortcut: Alt + 1,
            Save: All Files
        },
        clean: 
        {
            Name: clean, 
            Command: make, 
            Folder: $(ProjectPath),
            Parameters: clean,
            Shortcut: Alt + 2,
            Save: All Files
        }
        ```
3. Create a new project in Programmer's Notepad:
    - File > New > Project
    - Add `source` and `include` folder to project
4. Add the MakeFile
    - Navigate to `C:\devkitPro\examples\gba\template\Makefile` and copy the make file to the root of your working directory
    - Right click your project and select `Add Files`
5. Create the `first.c` file below and save it to your working directory

    ```C
    // First demo. You are not expected to understand it 
    // (don't spend too much time trying and read on).
    // But if you do understand (as a newbie): wow!

    int main()
    {
        *(unsigned int*)0x04000000 = 0x0403;

        ((unsigned short*)0x06000000)[120+80*240] = 0x001F;
        ((unsigned short*)0x06000000)[136+80*240] = 0x03E0;
        ((unsigned short*)0x06000000)[120+96*240] = 0x7C00;

        while(1);

        return 0;
    }
    ```
    - This file was given by the [Tonc: My first GBA demo](http://www.coranac.com/tonc/text/first.htm) chapter. This is a great resource for learning the inner workings of GBA dev.

6. Build the project
    - Alt + 1
    - New dir called `build` created and GBA file made
7. Test your game
    - Open the created `.gba` file in VisualBoyAdvance (VBA).
    - You should see three pixels of the color Red, Green, and Blue.
8. Setup Complete!
