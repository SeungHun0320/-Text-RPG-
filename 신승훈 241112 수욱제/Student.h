#pragma once

typedef struct tagInfo
{
	char szName[32] = "";
	int iKor, iEng, iMath, iTotal;
	float fAver;

}INFO;

class CStudent
{
public:
	CStudent();
	~CStudent();
public:
	void Initialize();
	void Update();
	void Release();
public:
	void Add_Data();
	void Print_Data();
	void Search_Data();
	void Delete_Data();

private:
	vector<INFO> m_vecInfo;
	INFO m_tInfo;
	int m_iCount;
};

