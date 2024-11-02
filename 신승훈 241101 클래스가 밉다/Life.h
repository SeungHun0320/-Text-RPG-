#pragma once

enum JOB {WARRIOR = 1, MAGE, THIEF};

typedef struct tagInfo
{
	char szName[32] = "";
	int iHp, iFullHp, iAtk;
}INFO;

class CLife
{
public:
	CLife();
	CLife(const char* _szName, int _iHp, int _iAtk);
	~CLife();
public:
	void Initialize();
	void Update();
	void Release();
public:
	void Select_Info();
public:
	void Set_Hp(int _iHp);
	int Get_Damage(int _iAttack) const;
	INFO Get_Info() const;
public:
	virtual void Render(); // 이놈은 큰 문제 x 같이 쓰니까
	virtual void Set_Info(const char* _szName, const char* _szJob, int _iHp, int _iAtk);
	//virtual void Set_Full_Hp(); // 이놈들 우짬??
	//virtual void Set_Exp();
	//virtual void Set_iGold();
	virtual CLife Get_This();
protected:
	INFO m_tInfo;
};

