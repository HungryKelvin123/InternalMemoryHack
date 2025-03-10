# InternalMemoryHack

a .dll file to be injected into wesnoth 1.14.9
pressing rshift adds 999999 gold

# How to use?
# USE A DLL INJECTOR, FIND ONE OR MAKE YOUR OWN. IF YOU CAN'T, HERES A MUCH MORE RISKY WAY TO USE THE CHEAT:
1. Go into regedit.exe and go to Computer\HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Microsoft\Windows NT\CurrentVersion\Windows
2. Set the value of AppInit_DLLs to the directory of the .dll file
3. Set LoadAppInit_DLLs value to 1
4. Open The Battle For Wesnoth - 1.14.9
5. Get into a game and press right shift
6. When finished, go back to regedit.exe and set LoadAppInit_DLLs back to 0.
# WARNING: OPENING ANY PROCESS WHILE LOADAPPINIT_DLLS VALUE IS 1 WILL INJECT THE CHEAT AND POTENTIALLY CRASH THE PROCESS
