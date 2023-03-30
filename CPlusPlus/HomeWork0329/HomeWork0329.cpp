

#include <iostream>
#include "Player.h"
#include "ConsoleGameScreen.h"

//상대의 말을 잘듣고 이해하지 못한 부분을 정확히 짚어서 질문해야한다.  >> 상대가 뭘 요구하고 있는지, 요구의 단계도 나눠서 정리.
//문제를 거시적인 시각으로 접근하지말라. 문제를 쪼개서 볼줄아는 논리력이 요구된다.

int main()
{


	Player NewPlayer = Player();
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetPos(), '*');

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.IsFire()); //플레이어가 발사버튼 눌렀으면 총알도 그려요

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();

	}

   
}