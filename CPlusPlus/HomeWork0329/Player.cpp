#include "Player.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Bullet.h"

Player::Player()
{

}

void Player::Input()
{
	if (0 == _kbhit())
	{
		Sleep(InterFrame);
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
		}
		SetLookingDirection(Lookleft);
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		SetLookingDirection(Lookright);
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		SetLookingDirection(Lookup);
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		SetLookingDirection(Lookdown);
		break;
	case 'e':
	case 'E':
		if (false == IsFire())             //e버튼을 누르면 총알이 나가요
		{
			Fire = true;
			Bullet::JustOneBullet.SetBullLoc(GetPos(), GetLookingDirection());  //현재 플레이어의 위치와 보고있는 방향을 바탕으로 총알 위치 수정

		}
		break;
	default:
		break;
	}

	Sleep(InterFrame);
}
