#include "pch.h"
#include "Player.h"

CPlayer::CPlayer() : iExp(0), iGold(0)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Render()
{
	cout << "================" << endl;
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "���� : " << szJob << endl;
	cout << "ü�� : " << m_tInfo.iHp << "/" << m_tInfo.iFullHp << endl;
	cout << "���ݷ� : " << m_tInfo.iAtk << endl;
	cout << "���� : " << iExp << "\t��� : " << iGold << endl;
}
void CPlayer::Set_Info(const char* _szName, const char* _szJob, int _iHp, int _iAtk)
{
	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), _szName);
	strcpy_s(szJob, sizeof(szJob), _szJob);
	m_tInfo.iHp = _iHp;
	m_tInfo.iFullHp = m_tInfo.iHp;
	m_tInfo.iAtk = _iAtk;
}
void CPlayer::Set_Full_Hp()
{
	m_tInfo.iHp = m_tInfo.iFullHp;
}

void CPlayer::Set_Exp()
{
	++iExp;
}

void CPlayer::Set_Gold()
{
	iGold += rand() % (200 - 100 + 1) + 100;
}

CLife CPlayer::Get_This()
{
	cout << "�ڽ�" << endl;
	system("pause");
	return *this;
}
