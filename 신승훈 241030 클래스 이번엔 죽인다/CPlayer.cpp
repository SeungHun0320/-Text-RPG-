#include "pch.h"
#include "CPlayer.h"

void CPlayer::Initialize()
{
}

void CPlayer::Update()
{
}

void CPlayer::Release()
{
}

void CPlayer::Set_Info(const char* _szName, int _iHp, int _iAtk)
{
	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), _szName);
	m_tInfo.iHp = _iHp;
	m_tInfo.iFullHp = m_tInfo.iHp;
	m_tInfo.iAtk = _iAtk;
	m_tInfo.iExp = 0;
}

void CPlayer::Select_Job()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "������ ������ �ּ���." << endl;
		cout << "1. ����  2. ������  3. ����  : ";
		cin >> iInput;

		switch (iInput)
		{
		case WARRIOR:
			Set_Info("����", 100, 10);
			return;
		case MAGE:
			Set_Info("������", 100, 10);
			return;
		case THIEF:
			Set_Info("����", 100, 10);
			return;
		default:
			continue;
		}
	}
}

void CPlayer::Render() const
{
	cout << "======================" << endl;
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "/" << m_tInfo.iFullHp << endl;
	cout << "���ݷ� : " << m_tInfo.iAtk << endl;
	cout << "����ġ : " << m_tInfo.iExp << endl;
}

INFO CPlayer::Get_Info() const
{
	return m_tInfo;
}

int CPlayer::Get_Damage(int _iMobAtk) const
{
	int iHp(0);
	return iHp = m_tInfo.iHp - _iMobAtk;
}

void CPlayer::Set_Hp(int _iHp)
{
	m_tInfo.iHp = _iHp;
}

void CPlayer::Set_FullHp()
{
	m_tInfo.iHp = m_tInfo.iFullHp;
}
