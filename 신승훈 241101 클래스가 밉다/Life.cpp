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
	cout << "이름 : " <<  m_tInfo.szName << endl;
	cout << "체력 : " << m_tInfo.iHp << "/" << m_tInfo.iFullHp << endl;
	cout << "공격력 : " << m_tInfo.iAtk << endl;
}

//void CLife::Set_Full_Hp()
//{
//	cout << "이게 맞나?" << endl;
//}
//
//void CLife::Set_Exp()
//{
//	cout << "양이 이게 맞아?" << endl;
//}
//
//void CLife::Set_iGold()
//{
//	cout << "용량이 이게 맞아???" << endl;
//}

CLife CLife::Get_This()
{
	cout << " 부모 " << endl;
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
		cout << "이름을 입력해 주세요." << endl;
		cin >> szName;

		cout << "직업을 선택해 주세요." << endl;
		cout << "1. 전사  2. 마법사  3. 도적  : ";
		cin >> iInput;

		switch (iInput)
		{
		case WARRIOR:
			Set_Info(szName, "전사", 100, 10);
			return;
		case MAGE:
			Set_Info(szName, "마법사", 100, 10);
			return;
		case THIEF:
			Set_Info(szName, "도적", 100, 10);
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
