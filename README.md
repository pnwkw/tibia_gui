# Tibia GUI Bot

An old (2010-ish) project dedicated to reverse engineering of the GUI system used in Tibia for the purpose of extending the client's functionality via DLL injected into the game process.

The included code demonstrates how the game executable can be modified to show a mana bar above the player's character health bar, as well as how to add a checkbox in the in-game settings window to turn this new feature on or off.

Provided for educational purposes only.

Needs to be compiled with 32 bit compiler on Windows.

# Build

Configure CMake and create a build directory with:
```
cmake -A Win32 -B build -S .
```
CMake will generate build scripts for you. To compile the program, type:
```
cmake -B build
```