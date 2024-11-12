#include "pch.h"
#include "Student.h"

CStudent::CStudent() : m_iCount(0)
{
	memset(&m_tInfo, 0, sizeof(INFO));
}

CStudent::~CStudent()
{
}

void CStudent::Initialize()
{
}

void CStudent::Update()
{
}

void CStudent::Release()
{
}

void CStudent::Add_Data()
{
	cout << "\n�߰��� �л����� �Է��� �ּ���  : ";
	cin >> m_iCount;

	for (int i = 0; i < m_iCount; i++)
	{
		cout << "�л� �̸� �Է� : ";
		cin >> m_tInfo.szName;

		cout << "���� ���� �Է� : ";
		cin >> m_tInfo.iKor;

		cout << "���� ���� �Է� : ";
		cin >> m_tInfo.iEng;

		cout << "���� ���� �Է� : ";
		cin >> m_tInfo.iMath;

		m_tInfo.iTotal = m_tInfo.iKor + m_tInfo.iEng + m_tInfo.iMath;
		m_tInfo.fAver = (float)m_tInfo.iTotal / 3.f;

		m_vecInfo.push_back(m_tInfo);
	}
}

void CStudent::Print_Data()
{
	for (size_t i = 0; i < m_vecInfo.size(); i++)
	{
		cout << "============= �� �� ǥ =============" << endl;
		cout << "�̸� : " << m_vecInfo[i].szName << endl;
		cout << "���� : " << m_vecInfo[i].iKor << endl;
		cout << "���� : " << m_vecInfo[i].iEng << endl;
		cout << "���� : " << m_vecInfo[i].iMath << endl;
		cout << "���� : " << m_vecInfo[i].iTotal << endl;
		cout << "��� : " << m_vecInfo[i].fAver << endl;
	}
	system("pause");
}

void CStudent::Search_Data()
{
	char szName[32] = "";

	cout << "\n�л� �̸��� �Է����ּ��� : ";
	cin >> szName;

	for (size_t i = 0; i < m_vecInfo.size(); i++)
	{
		if (!strcmp(m_vecInfo[i].szName, szName))
		{
			cout << "============= �� �� ǥ =============" << endl;
			cout << "�̸� : " << m_vecInfo[i].szName << endl;
			cout << "���� : " << m_vecInfo[i].iKor << endl;
			cout << "���� : " << m_vecInfo[i].iEng << endl;
			cout << "���� : " << m_vecInfo[i].iMath << endl;
			cout << "���� : " << m_vecInfo[i].iTotal << endl;
			cout << "��� : " << m_vecInfo[i].fAver << endl;
			
			continue;
		}	
	}
	system("pause");
}

void CStudent::Delete_Data()
{
	char szName[32] = "";

	vector<INFO>::iterator iter = m_vecInfo.begin();
	
	cout << "\n�л� �̸��� �Է����ּ��� : ";
	cin >> szName;

	for (size_t i = 0; i < m_vecInfo.size(); i++)
	{
		if (!strcmp(m_vecInfo[i].szName, szName))
		{
			iter = m_vecInfo.erase(iter);
			cout << "���� �Ϸ�" << endl;
			system("pause");
			return;
		}	
		iter++;
	}

	cout << "���µ�? ��" << endl;
	system("pause");
}
