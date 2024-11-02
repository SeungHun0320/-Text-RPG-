#pragma once

#ifdef _DEBUG            // �޸� ���� üũ ��ũ��

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

#define SAFE_DELETE(p) if(p != nullptr) {delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p != nullptr) {delete[] p; p = nullptr;}
