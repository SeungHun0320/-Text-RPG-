#pragma once
#include "Life.h"

enum JOB {WARRIOR = 1, MAGE, THIEF};

class CPlayer : public CLife
{
public:
	CPlayer(); 
	~CPlayer();
public:
	void Select_Job();
	void Set_FullHp();
};

