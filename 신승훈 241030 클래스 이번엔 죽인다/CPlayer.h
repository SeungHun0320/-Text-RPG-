#pragma once

typedef struct tagInfo
{
	char szName[32] = "";
	int iHp, iFullHp, iAtk, iExp;
}INFO;

enum JOB {WARRIOR = 1, MAGE, THIEF};

class CPlayer
{
public:
	CPlayer()
	{
		memset(&m_tInfo, 0, sizeof(INFO));
	}
	~CPlayer()
	{
		Release();
	}
public:
	void Initialize();
	void Update();
	void Release();
public:
	void Set_Info(const char* _szName, int _iHp, int _iAtk);
	void Select_Job();
	void Render() const;
public:
	INFO Get_Info()const;
	int Get_Damage(int _iMobAtk)const;
	void Set_Hp(int _iHp);
	void Set_FullHp();
private:
	INFO m_tInfo;
	
};

