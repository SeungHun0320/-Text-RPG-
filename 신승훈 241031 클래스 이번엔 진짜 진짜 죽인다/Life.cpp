#include "pch.h"
#include "Life.h"

CLife::CLife()
{
	memset(&m_tInfo, 0, sizeof(INFO));
}

CLife::~CLife()
{
}

void CLife::Render()
{
	cout << "====================" << endl;
	cout << "이름 : " << m_tInfo.szName << endl;
	cout << "체력 : " << m_tInfo.iHp << "/" << m_tInfo.iFullHp << endl;
	cout << "공격력 : " << m_tInfo.iAtk << endl;
}

void CLife::Set_Info(const char* _szName, int _iHp, int _iAtk)
{
	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), _szName);
	m_tInfo.iHp = _iHp;
	m_tInfo.iFullHp = m_tInfo.iHp;
	m_tInfo.iAtk = _iAtk;
}

void CLife::Set_Hp(int _iHp)
{
	m_tInfo.iHp = _iHp;
}

int CLife::Get_Damage(int _iAtk)
{
	int iHp(0);
	return iHp = m_tInfo.iHp - _iAtk;
}

INFO CLife::Get_Info()
{
	return m_tInfo;
}




