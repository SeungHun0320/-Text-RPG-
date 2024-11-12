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
	cout << "\n추가할 학생수를 입력해 주세요  : ";
	cin >> m_iCount;

	for (int i = 0; i < m_iCount; i++)
	{
		cout << "학생 이름 입력 : ";
		cin >> m_tInfo.szName;

		cout << "국어 점수 입력 : ";
		cin >> m_tInfo.iKor;

		cout << "영어 점수 입력 : ";
		cin >> m_tInfo.iEng;

		cout << "수학 점수 입력 : ";
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
		cout << "============= 성 적 표 =============" << endl;
		cout << "이름 : " << m_vecInfo[i].szName << endl;
		cout << "국어 : " << m_vecInfo[i].iKor << endl;
		cout << "영어 : " << m_vecInfo[i].iEng << endl;
		cout << "수학 : " << m_vecInfo[i].iMath << endl;
		cout << "총점 : " << m_vecInfo[i].iTotal << endl;
		cout << "평균 : " << m_vecInfo[i].fAver << endl;
	}
	system("pause");
}

void CStudent::Search_Data()
{
	char szName[32] = "";

	cout << "\n학생 이름을 입력해주세요 : ";
	cin >> szName;

	for (size_t i = 0; i < m_vecInfo.size(); i++)
	{
		if (!strcmp(m_vecInfo[i].szName, szName))
		{
			cout << "============= 성 적 표 =============" << endl;
			cout << "이름 : " << m_vecInfo[i].szName << endl;
			cout << "국어 : " << m_vecInfo[i].iKor << endl;
			cout << "영어 : " << m_vecInfo[i].iEng << endl;
			cout << "수학 : " << m_vecInfo[i].iMath << endl;
			cout << "총점 : " << m_vecInfo[i].iTotal << endl;
			cout << "평균 : " << m_vecInfo[i].fAver << endl;
			
			continue;
		}	
	}
	system("pause");
}

void CStudent::Delete_Data()
{
	char szName[32] = "";

	vector<INFO>::iterator iter = m_vecInfo.begin();
	
	cout << "\n학생 이름을 입력해주세요 : ";
	cin >> szName;

	for (size_t i = 0; i < m_vecInfo.size(); i++)
	{
		if (!strcmp(m_vecInfo[i].szName, szName))
		{
			iter = m_vecInfo.erase(iter);
			cout << "삭제 완료" << endl;
			system("pause");
			return;
		}	
		iter++;
	}

	cout << "없는디? ㅋ" << endl;
	system("pause");
}
