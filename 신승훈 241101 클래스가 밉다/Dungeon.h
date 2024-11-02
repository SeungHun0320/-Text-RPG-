#pragma once
#include "Life.h"
#include "Monster.h"
#include "define.h"
enum DUNGEON {EASY = 1, NORMAL, HARD, BACK};
enum FIGHT {ATTACK = 1, RUN};
class CDungeon
{
public:
	CDungeon();
	~CDungeon();
public:
	void Initialize();
	void Update();
	void Release();
public:
	void Set_Player_Info(CLife* pPlayer);
	int Fight();
protected:
	CLife* m_pCpyPlayer;
	CLife* m_pMob;
};

