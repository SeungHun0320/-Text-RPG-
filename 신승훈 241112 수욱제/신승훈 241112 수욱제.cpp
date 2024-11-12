#include "pch.h"
#include "Main_Game.h" 


// vector 를 이용하여 성적표 프로그램 만들기
// 1. 추가 2. 출력 3. 검색 4. 삭제 5. 종료


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    CMain_Game Main;

    Main.Initialize();
    Main.Update();

    return 0;
}

