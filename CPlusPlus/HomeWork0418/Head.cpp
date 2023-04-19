#include "Head.h"
#include <conio.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <list>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "GameEnum.h"
#include "Body.h"

bool Head::IsPlay = true;

Head::Head()
{
	RenderChar = L'▼';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head()
{
}

void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*>& BombGroup
		= ConsoleObjectManager::GetGroup(SnakeGameOrder::Body);

	for (ConsoleGameObject* BodyPtr : BombGroup)
	{
		// 터질때가 있습니다.
		if (nullptr == BodyPtr)
		{
			continue;
		}

		int2 BodyPos = BodyPtr->GetPos();
		if (GetPos() == BodyPos)
		{
			Parts* BodyPart = dynamic_cast<Parts*>(BodyPtr);

			if (nullptr == BodyPart)
			{
				MsgBoxAssert("바디그룹 쪽에 바디가 아닌 객체가 들어있었습니다.");
				return;
			}

			Parts* Last = GetLast();

			//int2 PrevPos = GetPrevPos();
			//BodyPart->SetPos(PrevPos);
			// ??BodyPart
			Last->SetNext(BodyPart);
			ConsoleObjectManager::CreateConsoleObject<Body>(SnakeGameOrder::Body);
			return;
		}
	}
}

void Head::Update()
{
	this;

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}


	if (0 == _kbhit())
	{
		// SetPos(GetPos() + Dir);
		// IsBodyCheck();
		// NewBodyCreateCheck();
		return;
	}

	char Ch = _getch();
	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		Dir = int2::Left;
		//this->RenderChar = L'◀';
		break;
	case 'd':
	case 'D':
		Dir = int2::Right;
		break;
	case 'w':
	case 'W':
		Dir = int2::Up;
		break;
	case 's':
	case 'S':
		Dir = int2::Down;
		break;
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		return;
	}

	SetPos(GetPos() + Dir);
	SetMyDir(Dir);
	SetMyRenderChar(GetMyDir());

	IsBodyCheck();

	NextMove();

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}



}
