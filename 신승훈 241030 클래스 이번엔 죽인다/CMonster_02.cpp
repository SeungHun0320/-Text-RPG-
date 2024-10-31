#include "pch.h"
#include "CMonster_02.h"

CMonster_02::CMonster_02() : m_pCpyPlayer02(nullptr)
{
	memset(&m_tInfo, 0, sizeof(MOBINFO));
}

CMonster_02::CMonster_02(const char* _szName, int _iHp, int _iAtk)
{
	m_pCpyPlayer02 = nullptr; // �� �� ������ ��� �����ϱ�, Ȥ�� �𸣴ϱ�

	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), _szName);
	m_tInfo.iHp = _iHp;
	m_tInfo.iFullHp = m_tInfo.iHp;
	m_tInfo.iAtk = _iAtk;
}

CMonster_02::~CMonster_02()
{
	Release();
}

void CMonster_02::Initialize()
{
}

void CMonster_02::Update()
{
}

void CMonster_02::Release()
{
}

void CMonster_02::Render()const
{
	cout << "======================" << endl;
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "/" << m_tInfo.iFullHp << endl;
	cout << "���ݷ� : " << m_tInfo.iAtk << endl;
}

void CMonster_02::Get_Player_Info(CPlayer* _pPlayer)
{
	m_pCpyPlayer02 = _pPlayer;
}

MOBINFO CMonster_02::Get_Info()const
{
	return m_tInfo;
}

int CMonster_02::Get_Damage(int _iPlayerAtk)const
{
	int iHp(0);
	return iHp = m_tInfo.iHp - _iPlayerAtk;
}

void CMonster_02::Set_Hp(int _iHp)
{
	m_tInfo.iHp = _iHp;
}

int CMonster_02::Fight()
{
	int iInput(0), iPlayerHp(0), iMobHp(0);
	while (true)
	{
		system("cls");
		m_pCpyPlayer02->Render();
		Render();
		cout << "1. ����  2. �������� : ";
		cin >> iInput;

		switch (iInput)
		{
		case ATTACK:
			iMobHp = Get_Damage(m_pCpyPlayer02->Get_Info().iAtk);
			Set_Hp(iMobHp);

			if (0 >= Get_Info().iHp)
			{
				return 1;
			}

			iPlayerHp = m_pCpyPlayer02->Get_Damage(Get_Info().iAtk);
			m_pCpyPlayer02->Set_Hp(iPlayerHp);

			if (0 >= m_pCpyPlayer02->Get_Info().iHp)
			{
				return 0;
			}
			continue;
		case RUN:
			return 2;
		}
	}
}