#pragma once
#include "Player.h"
#include "Monster.h"

enum DUNGEON {EASY = 1, NORMAL, HARD, BACK};
enum Fight {ATTACK = 1, RUN};

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
	void Get_Player_Info(CPlayer* pPlayer);
	void Fight();
private:
	CPlayer* m_pCpyPlayer;
	CMonster* m_pMob;
};

