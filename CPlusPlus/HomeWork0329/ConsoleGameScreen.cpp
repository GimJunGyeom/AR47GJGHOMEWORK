#include "ConsoleGameScreen.h"
#include <iostream>
#include "Bullet.h"

ConsoleGameScreen ConsoleGameScreen::MainScreen;

int2 ConsoleGameScreen::GetScreenSize()
{
	return int2{ ScreenXSize, ScreenYSize };
}

void ConsoleGameScreen::ScreenClear()
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			// Arr[y][x] = 'b';
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}

bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const
{
	if (0 > _Pos.X)
	{
		return true;
	}

	if (0 > _Pos.Y)
	{
		return true;
	}

	if (ScreenXSize <= _Pos.X)
	{
		return true;
	}

	if (ScreenYSize <= _Pos.Y)
	{
		return true;
	}

	return false;
}

void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	Arr[_Pos.Y][_Pos.X] = _Ch;
}

void ConsoleGameScreen::SetScreenCharacter(bool _Fire)                                            //오버로딩
{
	if (true == _Fire && false == IsScreenOver(Bullet::JustOneBullet.GetBullLoc()))               //총알 그리기 조건1. 플레이어가 발사버튼 눌렀어야함, 조건2. 총알이 화면 밖으로 넘어간 상태 아니여야함
	{
		Arr[Bullet::JustOneBullet.GetBullLoc().Y][Bullet::JustOneBullet.GetBullLoc().X] = '$';    //화면에 총알 위치를 넣어줘요
		Bullet::JustOneBullet.Bullet_Move();                                                      //다음 화면에 들어갈 총알의 위치를 바꿔줌
	}
}




ConsoleGameScreen::ConsoleGameScreen()
{
}

