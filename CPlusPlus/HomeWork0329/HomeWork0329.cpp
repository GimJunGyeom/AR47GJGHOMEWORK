

#include <iostream>
#include "Player.h"
#include "ConsoleGameScreen.h"

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