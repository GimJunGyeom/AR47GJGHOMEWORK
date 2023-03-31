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
	
	static bool CheckMonsterWall()                                 //�� ȭ���� ���� ���Ͱ� �ִ��� �˻�
	{
		int BoundryX = ConsoleGameScreen::ScreenXSize;
		int BoundryY = ConsoleGameScreen::ScreenYSize;


		for (int j = 0; j < BoundryY; j++)
		{
			//���� ������ ������ �浹�˻�
			if (Arr[j][0] == 'M' || Arr[j][BoundryX - 1] == 'M')
			{
				return true;
			}

		}

		return false;
	}

	static bool ReturnMonsterWallCollision()                      //���� ���� ������ �浹 ���¸� ��ȯ
	{
		return MonsterWallCollision;
	}

	static void SetMonsterWallCollisionTrue()                     //ȭ���� ���� �浹���·� ��ȯ��
	{
		MonsterWallCollision = true;
	}

	static void SetMonsterWallCollisionFalse()                    //ȭ���� ���� �浹�� �ƴ� ���·� ��ȯ��
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
	static bool MonsterWallCollision;                           //���� ������ �浹����

	ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;
};