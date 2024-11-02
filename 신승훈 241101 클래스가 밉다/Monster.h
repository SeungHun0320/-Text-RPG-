#pragma once
#include "Life.h"

class CMonster : public CLife
{
public:
	CMonster();
	CMonster(const char* _szName, int _iHp, int _iAtk);
	~CMonster();
public:
	void Initialize();
	void Update();
	void Release();

};

