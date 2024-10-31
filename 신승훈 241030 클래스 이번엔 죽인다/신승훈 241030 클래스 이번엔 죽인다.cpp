#include "pch.h"
#include "CMain_Game.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CMain_Game Main;

	Main.Initialize();
	Main.Update();

	return 0;
}

