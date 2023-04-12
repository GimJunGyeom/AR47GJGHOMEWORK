#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include "ConsoleObjectManager.h"
#include "Bomb.h"
#include "GameEnum.h"
#include "ConsoleObjectManager.h"

bool Player::IsGameUpdate = true;

Player::Player()
{
	RenderChar = '*';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

}

bool Player::IsBomb(int2 _NextPos)
{

	GameEngineArray<ConsoleGameObject*>& BombGroup 
		= ConsoleObjectManager::GetGroup(ObjectOrder::Bomb);

	for (int i = 0; i < BombGroup.Count(); i++)
	{
		if (nullptr != BombGroup[i])
		{
			int2 BombPos = BombGroup[i]->GetPos();
			char BombChar = ConsoleGameScreen::GetMainScreen().GetScreenCharacter(BombPos);
			if (BombChar != '#' && BombPos == _NextPos)
			{
				return true;
			}
		}
	}
	
	return false;
}

// 화면바깥으로 못나가게 하세요. 
void Player::Update()
{
	if (0 == _kbhit())
	{
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };


	switch (Ch)
	{
	case 'a':
	case 'A':
	{
		NextPos = Pos;
		NextPos.X -= 1;
		bool ScreenOverTest = ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos);
		bool NoBombTest = IsBomb(NextPos);
		if (false == ScreenOverTest && false == NoBombTest)
		{
			Pos.X -= 1;
		}
		break;
	}
	case 'd':
	case 'D':
	{
		NextPos = Pos;
		NextPos.X += 1;
		bool ScreenOverTest = ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos);
		bool NoBombTest = IsBomb(NextPos);
		if (false == ScreenOverTest && false == NoBombTest)
		{
			Pos.X += 1;
		}
		break;
	}
	case 'w':
	case 'W':
	{
		NextPos = Pos;
		NextPos.Y -= 1;
		bool ScreenOverTest = ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos);
		bool NoBombTest = IsBomb(NextPos);
		if (false == ScreenOverTest && false == NoBombTest)
		{
			Pos.Y -= 1;
		}
		break;
	}
	case 's':
	case 'S':
	{
		NextPos = Pos;
		NextPos.Y += 1;
		bool ScreenOverTest = ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos);
		bool NoBombTest = IsBomb(NextPos);
		if (false == ScreenOverTest && false == NoBombTest)
		{
			Pos.Y += 1;
		}
		break;
	}
	case 'f':
	case 'F':
	{
		// 여기 이상황에서 보면
		// ConsoleObjectManager 있고
		// Player 
		Bomb* NewBomb = ConsoleObjectManager::CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
		NewBomb->Init(BombPower);
		NewBomb->SetPos(GetPos());
		// 폭탄설치 
		break;
	}
	/*case 'q':
	case 'Q':
	{
		IsGameUpdate = false;
		break;
	}*/
	default:
		break;
	}
}
