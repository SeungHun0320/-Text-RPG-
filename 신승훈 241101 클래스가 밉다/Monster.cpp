#include "pch.h"
#include "Monster.h"

CMonster::CMonster()
{
}

CMonster::CMonster(const char* _szName, int _iHp, int _iAtk)
	: CLife(_szName, _iHp, _iAtk)
{
}

CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
}

void CMonster::Update()
{
}

void CMonster::Release()
{
}
