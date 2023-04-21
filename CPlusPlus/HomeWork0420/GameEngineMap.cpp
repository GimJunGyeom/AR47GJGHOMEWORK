// GameEngineMap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <list>
#include "GameEngineMap.h"

int main()
{
    {
        GameEngineMap Test;
        Test.insert(GameEnginePair(10, rand()));
        Test.insert(GameEnginePair(7, rand()));
        Test.insert(GameEnginePair(15, rand()));
        Test.insert(GameEnginePair(25, rand()));
        Test.insert(GameEnginePair(17, rand()));
        Test.insert(GameEnginePair(15, rand()));
        Test.insert(GameEnginePair(18, rand()));
        Test.insert(GameEnginePair(2, rand()));
        Test.insert(GameEnginePair(6, rand()));
        Test.insert(GameEnginePair(5, rand()));
        Test.insert(GameEnginePair(4, rand()));
        Test.insert(GameEnginePair(9, rand()));
        Test.insert(GameEnginePair(8, rand()));
        Test.insert(GameEnginePair(1, rand()));

        GameEngineMap::iterator MaxStartIter = Test.MaxStarter();
        GameEngineMap::iterator MinEndIter = GameEngineMap::iterator();

        for (; MaxStartIter != MinEndIter; --MaxStartIter)
        {
            if (MaxStartIter == nullptr)
            {
                continue;
            }
            std::cout << MaxStartIter->first << std::endl;
        }
     

		/*{
			GameEngineMap::iterator FindIter = Test.find(7);
			GameEngineMap::iterator NextIter = Test.erase(FindIter);
		}

		GameEngineMap::iterator StartIter = Test.begin();
		GameEngineMap::iterator EndIter = Test.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			if (StartIter == nullptr)
			{
				continue;
			}
			std::cout << StartIter->first << std::endl;
		}*/
    }
}
