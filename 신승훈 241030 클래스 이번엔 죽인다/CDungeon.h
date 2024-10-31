#pragma once
#include "CPlayer.h"
#include "CMonster_01.h"
#include "CMonster_02.h"
#include "CMonster_03.h"
#include "define.h"

enum DUNGEON {EASY = 1, NORMAL, HARD, BACK};

class CDungeon
{
public:
	CDungeon();
	~CDungeon();
public:
	void Update();
	void Release();
public:
	void Get_Player_Info(CPlayer* _pPlayer);
	void Result();

private:
	CPlayer* m_pCpyPlayer;
	CMonster_01* m_pMob_01;
	CMonster_02* m_pMob_02;
	CMonster_03* m_pMob_03;
};

