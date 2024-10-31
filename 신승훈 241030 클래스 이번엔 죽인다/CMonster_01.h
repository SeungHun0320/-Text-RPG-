#pragma once
#include "define.h"
#include "CPlayer.h"

class CMonster_01
{
public:
	CMonster_01();
	CMonster_01(const char* _szName, int _iHp, int _iAtk);
	~CMonster_01();
public:
	void Initialize();
	void Update();
	void Release();
public:
	void Render()const;
	int Fight();
	
public:
	void Get_Player_Info(CPlayer* _pPlayer);
	MOBINFO Get_Info()const;
	int Get_Damage(int _iPlayerAtk)const;
	void Set_Hp(int _iHp);

private:
	MOBINFO m_tInfo;
	CPlayer* m_pCpyPlayer01;
};

