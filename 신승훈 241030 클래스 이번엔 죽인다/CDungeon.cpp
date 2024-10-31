#include "pch.h"
#include "CDungeon.h"

CDungeon::CDungeon() 
: m_pCpyPlayer(nullptr), m_pMob_01(nullptr),
  m_pMob_02(nullptr), m_pMob_03(nullptr)
{
}

CDungeon::~CDungeon()
{
	Release();
}

void CDungeon::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pCpyPlayer->Render();
		cout << "1. �ʱ�  2. �߱�  3. ���  4. �����޴�  : ";
		cin >> iInput;

		switch (iInput)
		{
		case EASY:
			m_pMob_01 = new CMonster_01("�ϱ���", 30, 3);
			if (m_pMob_01 != nullptr)
				m_pMob_01->Get_Player_Info(m_pCpyPlayer);
			break;
		case NORMAL:
			m_pMob_02 = new CMonster_02("�߱���", 60, 6);
			if (m_pMob_02 != nullptr)
				m_pMob_02->Get_Player_Info(m_pCpyPlayer);
			break;
		case HARD:
			m_pMob_03 = new CMonster_03("�����", 90, 9);
			if (m_pMob_03 != nullptr)
				m_pMob_03->Get_Player_Info(m_pCpyPlayer);
			break;
		case BACK:
			return;
		}
		Result();
	}
}

void CDungeon::Release()
{
	SAFE_DELETE(m_pMob_01);
	SAFE_DELETE(m_pMob_02);
	SAFE_DELETE(m_pMob_03);
}

void CDungeon::Get_Player_Info(CPlayer* _pPlayer)
{
	m_pCpyPlayer = _pPlayer;
}

void CDungeon::Result()
{
	if (m_pMob_01 != nullptr || m_pMob_02 != nullptr || m_pMob_03 != nullptr)
	{
		int iResult(0);
		if(m_pMob_01 != nullptr)
		    iResult = m_pMob_01->Fight();
		if(m_pMob_02 != nullptr)
			iResult = m_pMob_02->Fight();
		if (m_pMob_03 != nullptr)
			iResult = m_pMob_03->Fight();

		if (1 == iResult)
		{
			cout << "�¸�" << endl;
		}
		else if (0 == iResult)
		{
			cout << "�й�" << endl;
			m_pCpyPlayer->Set_FullHp();
		}
		else
		{
			cout << m_pCpyPlayer->Get_Info().szName << "��(��) �����ƴ� !" << endl;
		}
		SAFE_DELETE(m_pMob_01);
		SAFE_DELETE(m_pMob_02);
		SAFE_DELETE(m_pMob_03);
		system("pause");
	}
}
