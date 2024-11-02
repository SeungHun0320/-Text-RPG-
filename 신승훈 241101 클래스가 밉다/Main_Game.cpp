#include "pch.h"
#include "Main_Game.h"

CMain_Game::CMain_Game() : m_pPlayer(nullptr), m_pDungeon(nullptr)
{
}

CMain_Game::~CMain_Game()
{
	Release();
}

void CMain_Game::Initialize()
{
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Select_Info();
	}
	if (m_pDungeon == nullptr)
	{
		m_pDungeon = new CDungeon;
		m_pDungeon->Set_Player_Info(m_pPlayer);
	}
}

void CMain_Game::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1. 던전  2. 여관  3. 상점  4. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case DUNGEON:
			if (m_pDungeon != nullptr)
				m_pDungeon->Update();
			break;
		case INN:
			break;
		case SHOP:
			break;
		case END2:
			return;
		}
	}
}

void CMain_Game::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pDungeon);
}

bool CMain_Game::Start_Menu()
{
	int iInput(0);
	system("cls");
	cout << "텍알" << endl;
	cout << "1. 새게임 2. 종료 : ";
	cin >> iInput;

	switch (iInput)
	{
	case NEW:
		Initialize();
		return true;
	case END:
		return false;
	default:
		cout << "잘못된 입력" << endl;
		return false;
	}
}


