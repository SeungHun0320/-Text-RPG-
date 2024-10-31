#include "pch.h"
#include "CMain_Game.h"


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
		if (m_pPlayer != nullptr)
		{
			m_pPlayer->Select_Job();
		}
	}
	if (m_pDungeon == nullptr)
	{
		m_pDungeon = new CDungeon;
		if (m_pDungeon != nullptr)
		{
			m_pDungeon->Get_Player_Info(m_pPlayer);
		}
	}

}

void CMain_Game::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1. 던전  2. 종료  : ";
		cin >> iInput;

		switch (iInput)
		{
		case DUNGEON:
			if(m_pDungeon != nullptr)
			m_pDungeon->Update();
			break;
		case END:
			return;
		}
	}
}

void CMain_Game::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pDungeon);
}
