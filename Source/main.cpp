#include <iostream>
#ifdef __WIN32
    #define _WIN32_WINNT 0x0500 //For getting console window
#endif // __WIN32

#include "Utilities/windows_funcs.h"
#include "Game/game.h"

#include <ctime>

void
setupConsole();

int main()
{
    srand(time(NULL));

    setupConsole();

    Game_Main game;
    game.runLoop();

    return 0;
}

void setupConsole()
{
    #ifdef __WIN32
        constexpr short consoleWidth = 500;
        constexpr short consoleHeight = 700;

        HWND console = GetConsoleWindow();
        MoveWindow(console, 0, 0, consoleWidth, consoleHeight, TRUE);
        //MoveWindow(console, -1750, 0, consoleWidth, consoleHeight, TRUE);
    #endif // __WIN32
}
