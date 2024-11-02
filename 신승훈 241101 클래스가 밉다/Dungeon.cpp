#include "pch.h"
#include "Dungeon.h"

CDungeon::CDungeon() : m_pCpyPlayer(nullptr), m_pMob(nullptr)
{
}

CDungeon::~CDungeon()
{
}

void CDungeon::Initialize()
{
}

void CDungeon::Update()
{
	int iInput(0), iResult(0);
	while (true)
	{
		system("cls");
		m_pCpyPlayer->Render();
		cout << "1. 쉬움  2. 보통  3. 어려움  4. 이전 메뉴 : ";
		cin >> iInput;

		switch (iInput)
		{
		case EASY:
			if(m_pMob == nullptr)
			m_pMob = new CMonster("하급이", 30, 3);
			break;
		case NORMAL:
			if (m_pMob == nullptr)
			m_pMob = new CMonster("중급이", 60, 6);
			break;
		case HARD:
			if (m_pMob == nullptr)
			m_pMob = new CMonster("상급이", 90, 9);
			break;
		case BACK:
			return;
		}

		if (m_pMob != nullptr && m_pCpyPlayer != nullptr)
		{
			iResult = Fight();
			if (0 >= iResult)
			{
				//m_pCpyPlayer->Get_This().Set_Full_Hp();
				//m_pCpyPlayer->Set_Full_Hp();
			}
			else
			{
				//m_pCpyPlayer->Set_Exp();
				//m_pCpyPlayer->Set_iGold();
			}
			SAFE_DELETE(m_pMob)
		}
	}
}

void CDungeon::Release()
{
	SAFE_DELETE(m_pMob);
}

void CDungeon::Set_Player_Info(CLife* pPlayer)
{
	m_pCpyPlayer = pPlayer;
}

int CDungeon::Fight()
{
	int iInput(0), iPHp(0), iMHp(0);
	while (true)
	{
		system("cls");
		m_pCpyPlayer->Render();
		m_pMob->Render();
		cout << "1. 싸우다  2. 도망가다  : ";
		cin >> iInput;

		switch (iInput)
		{
		case ATTACK:
			iPHp = m_pCpyPlayer->Get_Damage(m_pMob->Get_Info().iAtk);
			m_pCpyPlayer->Set_Hp(iPHp);

			if (0 >= m_pCpyPlayer->Get_Info().iHp)
			{
				cout << "패배" << endl;
				system("pause");
				return 0;
			}

			iMHp = m_pMob->Get_Damage(m_pCpyPlayer->Get_Info().iAtk);
			m_pMob->Set_Hp(iMHp);

			if (0 >= m_pMob->Get_Info().iHp)
			{
				cout << "승리" << endl;
				system("pause");
				return 1;
			}

			break;
		case RUN:
			return 1;
		default:
			continue;
		}
	}
}
