#pragma once
#include "define.h"
#include "Student.h"

enum MENU {ADD = 1, PRINT, SEARCH, DELETE, END};

class CMain_Game
{
public:
	CMain_Game();
	~CMain_Game();
public:
	void Initialize();
	void Update();
	void Release();
private:
	CStudent* m_pStudent;
};

