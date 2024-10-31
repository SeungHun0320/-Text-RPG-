#include "pch.h"
#include "CMonster_01.h"

CMonster_01::CMonster_01() : m_pCpyPlayer01(nullptr)
{
	memset(&m_tInfo, 0, sizeof(MOBINFO));
}

CMonster_01::CMonster_01(const char* _szName, int _iHp, int _iAtk)
{
	m_pCpyPlayer01 = nullptr; // �� �� ������ ��� �����ϱ�, Ȥ�� �𸣴ϱ�

	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), _szName);
	m_tInfo.iHp = _iHp;
	m_tInfo.iFullHp = m_tInfo.iHp;
	m_tInfo.iAtk = _iAtk;
}

CMonster_01::~CMonster_01()
{
	Release();
}

void CMonster_01::Initialize()
{
}

void CMonster_01::Update()
{
}

void CMonster_01::Release()
{
}

void CMonster_01::Render() const
{
	cout << "======================" << endl;
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "/" << m_tInfo.iFullHp << endl;
	cout << "���ݷ� : " << m_tInfo.iAtk << endl;
}

void CMonster_01::Get_Player_Info(CPlayer* _pPlayer)
{
	m_pCpyPlayer01 = _pPlayer;
}

MOBINFO CMonster_01::Get_Info() const
{
	return m_tInfo;
}

int CMonster_01::Get_Damage(int _iPlayerAtk) const
{
	int iHp(0);
	return iHp = m_tInfo.iHp - _iPlayerAtk;
}

void CMonster_01::Set_Hp(int _iHp)
{
	m_tInfo.iHp = _iHp;
}

int CMonster_01::Fight()
{
	int iInput(0), iPlayerHp(0), iMobHp(0);
	while (true)
	{
		system("cls");
		m_pCpyPlayer01->Render();
		Render();
		cout << "1. ����  2. �������� : ";
		cin >> iInput;

		switch (iInput)
		{
		case ATTACK:
			iMobHp = Get_Damage(m_pCpyPlayer01->Get_Info().iAtk);
			Set_Hp(iMobHp);

			if (0 >= Get_Info().iHp)
			{
				return 1;
			}

			iPlayerHp = m_pCpyPlayer01->Get_Damage(Get_Info().iAtk);
			m_pCpyPlayer01->Set_Hp(iPlayerHp);

			if (0 >= m_pCpyPlayer01->Get_Info().iHp)
			{
				return 0;
			}
			continue;
		case RUN:
			return 2;
		}
	}
}

