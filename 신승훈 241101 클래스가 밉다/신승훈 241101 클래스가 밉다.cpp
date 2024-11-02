#include "pch.h"
#include "Main_Game.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    srand(unsigned(time(NULL)));

    CMain_Game Main;
    
    bool bSelect = Main.Start_Menu();
    if (bSelect == false)
        return 0;
    Main.Update();
    Main.Release();

    return 0;
}