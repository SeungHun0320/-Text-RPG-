#include "pch.h"
#include "Dungeon.h"

CDungeon::CDungeon() : m_pCpyPlayer(nullptr), m_pMob(nullptr)
{
}

CDungeon::~CDungeon()
{
	Release();
}

void CDungeon::Initialize()
{
	if (m_pMob == nullptr)
	{
		m_pMob = new CMonster;
	}
}

void CDungeon::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pCpyPlayer->Render();
		cout << "1. 하급 2. 중급 3. 고급 4. 이전메뉴 : ";
		cin >> iInput;

		switch (iInput)
		{
		case EASY:
			if(m_pMob != nullptr)
			    m_pMob->Set_Info("하급이", 30, 3);
			break;
		case NORMAL:
			if (m_pMob != nullptr)
				m_pMob->Set_Info("중급이", 60, 6);
			break;
		case HARD:
			if (m_pMob != nullptr)
				m_pMob->Set_Info("상급이", 90, 9);
			break;
		case BACK:
			return;
		default:
			continue;
		}

		if (m_pMob != nullptr && m_pCpyPlayer != nullptr)
		{
			Fight();
		}
		
	}
}

void CDungeon::Release()
{
	SAFE_DELETE(m_pMob);
}

void CDungeon::Get_Player_Info(CPlayer* pPlayer)
{
	m_pCpyPlayer = pPlayer;
}

void CDungeon::Fight()
{
	int iInput(0), iPHp(0), iMHp(0);
	while (true)
	{
		system("cls");
		m_pCpyPlayer->Render();
		m_pMob->Render();
		cout << "1. 싸우다  2. 도망가다 : ";
		cin >> iInput;

		switch (iInput)
		{
		case ATTACK:
			iMHp = m_pMob->Get_Damage(m_pCpyPlayer->Get_Info().iAtk);
			m_pMob->Set_Hp(iMHp);

			if (0 >= m_pMob->Get_Info().iHp)
			{
				cout << "승리" << endl;
				system("pause");
				return;
			}

			iPHp = m_pCpyPlayer->Get_Damage(m_pMob->Get_Info().iAtk);
			m_pCpyPlayer->Set_Hp(iPHp);

			if (0 >= m_pCpyPlayer->Get_Info().iHp)
			{
				cout << "패배" << endl;
				system("pause");
				m_pCpyPlayer->Set_FullHp();
				return;
			}
			break;
		case RUN:
			return;
		default:
			continue;
		}
	}
}

