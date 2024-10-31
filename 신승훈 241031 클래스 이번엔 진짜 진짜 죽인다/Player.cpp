#include "pch.h"
#include "Player.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{

}

void CPlayer::Select_Job()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "직업을 선택해 주세요" << endl;
		cout << "1. 전사 2. 마법사 3. 도적 : ";
		cin >> iInput;

		switch (iInput)
		{
		case WARRIOR:
			Set_Info("전사", 100, 10);
			return;
		case MAGE:
			Set_Info("마법사", 100, 10);
			return;
		case THIEF:
			Set_Info("도적", 100, 10);
			return;
		default:
			continue;
		}
	}
}

void CPlayer::Set_FullHp()
{
	m_tInfo.iHp = m_tInfo.iFullHp;
}
