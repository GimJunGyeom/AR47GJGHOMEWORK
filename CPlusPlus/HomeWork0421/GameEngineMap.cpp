// GameEngineMap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "GameEngineMap.h"

int main()
{
    GameEngineDebug::LeckCheck();
    {
        GameEngineMap<int, int> Test;
        Test.insert(GameEnginePair<int, int>(10, rand()));
        Test.insert(GameEnginePair<int, int>(7, rand()));
        Test.insert(GameEnginePair<int, int>(15, rand()));
        Test.insert(GameEnginePair<int, int>(25, rand()));
        Test.insert(GameEnginePair<int, int>(17, rand()));
        Test.insert(GameEnginePair<int, int>(18, rand()));
        Test.insert(GameEnginePair<int, int>(2, rand()));
        Test.insert(GameEnginePair<int, int>(6, rand()));
        Test.insert(GameEnginePair<int, int>(5, rand()));
        Test.insert(GameEnginePair<int, int>(4, rand()));
        Test.insert(GameEnginePair<int, int>(9, rand()));
        Test.insert(GameEnginePair<int, int>(8, rand()));
        Test.insert(GameEnginePair<int, int>(1, rand()));

        GameEngineMap<int, int>::iterator StartIter = Test.begin();
        GameEngineMap<int, int>::iterator EndIter = Test.end();
        for (; StartIter != EndIter; ++StartIter)
        {
            std::cout << StartIter->first << std::endl;
        }

        Test.~GameEngineMap();
    }

    return 1;
}

