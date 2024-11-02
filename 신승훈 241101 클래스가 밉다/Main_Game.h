#pragma once
#include "define.h"
#include "Player.h"
#include "Dungeon.h"

enum START {NEW = 1, END};
enum MAIN {DUNGEON = 1, INN, SHOP, END2};
class CMain_Game
{
public:
	CMain_Game();
	~CMain_Game();
public:
	void Initialize();
	void Update();
	void Release();
public:
	bool Start_Menu();
private:
	CLife* m_pPlayer;
	CDungeon* m_pDungeon;
};

