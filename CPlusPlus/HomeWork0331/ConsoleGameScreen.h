#pragma once
#include "ConsoleGameMath.h"


class ConsoleGameScreen
{
public:

	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}
	
	static bool CheckMonsterWall()                                 //이 화면의 벽에 몬스터가 있는지 검사
	{
		int BoundryX = ConsoleGameScreen::ScreenXSize;
		int BoundryY = ConsoleGameScreen::ScreenYSize;


		for (int j = 0; j < BoundryY; j++)
		{
			//왼쪽 오른쪽 벽들의 충돌검사
			if (Arr[j][0] == 'M' || Arr[j][BoundryX - 1] == 'M')
			{
				return true;
			}

		}

		return false;
	}

	static bool ReturnMonsterWallCollision()                      //현재 벽과 몬스터의 충돌 상태를 반환
	{
		return MonsterWallCollision;
	}

	static void SetMonsterWallCollisionTrue()                     //화면의 벽이 충돌상태로 전환됨
	{
		MonsterWallCollision = true;
	}

	static void SetMonsterWallCollisionFalse()                    //화면의 벽이 충돌이 아닌 상태로 전환됨
	{
		MonsterWallCollision = false;
	}


	static int2 GetScreenSize();

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);


protected:

private:
	static char Arr[ScreenYSize][ScreenXSize];
	static bool MonsterWallCollision;                           //벽과 몬스터의 충돌상태

	ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;
};