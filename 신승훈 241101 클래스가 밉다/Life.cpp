#include "pch.h"
#include "Life.h"

CLife::CLife()
{
}

CLife::CLife(const char* _szName, int _iHp, int _iAtk)
{
	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), _szName);
	m_tInfo.iHp = _iHp;
	m_tInfo.iFullHp = m_tInfo.iHp;
	m_tInfo.iAtk = _iAtk;
}

CLife::~CLife()
{
}

void CLife::Initialize()
{
}

void CLife::Update()
{
}

void CLife::Release()
{

}

void CLife::Render()
{
	cout << "================" << endl;
	cout << "�̸� : " <<  m_tInfo.szName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "/" << m_tInfo.iFullHp << endl;
	cout << "���ݷ� : " << m_tInfo.iAtk << endl;
}

//void CLife::Set_Full_Hp()
//{
//	cout << "�̰� �³�?" << endl;
//}
//
//void CLife::Set_Exp()
//{
//	cout << "���� �̰� �¾�?" << endl;
//}
//
//void CLife::Set_iGold()
//{
//	cout << "�뷮�� �̰� �¾�???" << endl;
//}

CLife CLife::Get_This()
{
	cout << " �θ� " << endl;
	system("pause");
	return CLife();
}

void CLife::Select_Info()
{
	int iInput(0);
	char szName[32] = "";
	while (true)
	{
		system("cls");
		cout << "�̸��� �Է��� �ּ���." << endl;
		cin >> szName;

		cout << "������ ������ �ּ���." << endl;
		cout << "1. ����  2. ������  3. ����  : ";
		cin >> iInput;

		switch (iInput)
		{
		case WARRIOR:
			Set_Info(szName, "����", 100, 10);
			return;
		case MAGE:
			Set_Info(szName, "������", 100, 10);
			return;
		case THIEF:
			Set_Info(szName, "����", 100, 10);
			return;
		default:
			continue;
		}
	}
}

void CLife::Set_Info(const char* _szName, const char* _szJob, int _iHp, int _iAtk)
{
	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), _szName);
	m_tInfo.iHp = _iHp;
	m_tInfo.iFullHp = m_tInfo.iHp;
	m_tInfo.iAtk = _iAtk;
}

INFO CLife::Get_Info() const
{
	return m_tInfo;
}

int CLife::Get_Damage(int _iAttack) const
{
	int iHp(0);
	return iHp = m_tInfo.iHp - _iAttack;
}

void CLife::Set_Hp(int _iHp)
{
	m_tInfo.iHp = _iHp;
}
