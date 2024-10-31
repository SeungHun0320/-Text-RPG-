#pragma once
#include "define.h"

typedef struct tagInfo
{
	char szName[32] = "";
	int iHp, iFullHp, iAtk;
}INFO;

class CLife
{
public:
	CLife(); 
	~CLife();
public:
	void Render();
public:
	void Set_Info(const char* _szName, int _iHp, int _iAtk);
	void Set_Hp(int _iHp);
	int Get_Damage(int _iAtk);
	INFO Get_Info();

protected:
	INFO m_tInfo;
};

