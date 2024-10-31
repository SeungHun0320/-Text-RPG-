#pragma once
#include "Player.h"
#include "define.h"
#include "Dungeon.h"

enum MAIN {DUNGEON = 1, END};

class CMain_Game
{
public:
	CMain_Game();
	~CMain_Game();
public:
	void Initialize();
	void Update();
	void Release();
private:
	CPlayer* m_pPlayer;
	CDungeon* m_pDungeon;
};

