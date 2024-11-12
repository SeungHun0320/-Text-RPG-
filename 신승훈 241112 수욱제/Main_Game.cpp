#include "pch.h"
#include "Main_Game.h"

CMain_Game::CMain_Game() : m_pStudent(nullptr)
{
}

CMain_Game::~CMain_Game()
{
	Release();
}

void CMain_Game::Initialize()
{
	if (m_pStudent == nullptr)
	{
		m_pStudent = new CStudent;
	}
}

void CMain_Game::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "성적표 프로그램" << endl;
		cout << "1. 추가  2. 출력  3. 검색  4. 삭제  5. 종료  : ";
		cin >> iInput;

		switch (iInput)
		{
		case ADD:
			m_pStudent->Add_Data();
			break;
		case PRINT:
			m_pStudent->Print_Data();
			break;
		case SEARCH:
			m_pStudent->Search_Data();
			break;
		case DELETE:
			m_pStudent->Delete_Data();
			break;
		case END:
			Release();
			return;
		default:
			continue;
		}
	}
}

void CMain_Game::Release()
{
	Safe_Delete<CStudent*>(m_pStudent);
}
