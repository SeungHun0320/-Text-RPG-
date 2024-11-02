#pragma once
#include "Life.h"

class CPlayer : public CLife
{
public:
	CPlayer();
	~CPlayer();
public:
	void Render();
	void Set_Info(const char* _szName, const char* _szJob, int _iHp, int _iAtk);
	void Set_Full_Hp();
	void Set_Exp();
	void Set_Gold();
	CLife Get_This();

private:
	int iExp;
	int iGold;
	char szJob[32] = "";
};


