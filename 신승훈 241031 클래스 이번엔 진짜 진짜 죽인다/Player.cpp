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
		cout << "������ ������ �ּ���" << endl;
		cout << "1. ���� 2. ������ 3. ���� : ";
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

void CPlayer::Set_FullHp()
{
	m_tInfo.iHp = m_tInfo.iFullHp;
}
