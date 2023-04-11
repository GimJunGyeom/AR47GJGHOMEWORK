#include "Bomb.h"

#define Ex_Step_0 0
#define Ex_Step_1 -1
#define Ex_Step_2 -2
#define Ex_Step_End -3

Bomb::Bomb()
{
}

Bomb::~Bomb()
{
}

void Bomb::Init()
{
	RenderChar = '@';
}


void Bomb::Update()
{
	ConsoleGameObject::Update();

	--BoomCount;
	if (Ex_Step_0 >= BoomCount)        //폭발 문자로변경
	{
		if (BoomCount <= Ex_Step_End)   //폭발시간 넘기면 폭탄 오프
		{
			Off();
		}
		RenderChar = '$';      //폭발상태
	}
}


void Bomb::Render()
{
	ConsoleGameObject::Render();

	if (Ex_Step_0 >= BoomCount && Ex_Step_1 < BoomCount)              //폭발 0단계
	{
		for (int i = GetPos().X - 1; i <= GetPos().X + 1; i++)  //폭발 가로 영역 
		{
			int2 Explosion(i, GetPos().Y);
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Explosion, RenderChar);
		}
		for (int j = GetPos().Y - 1; j <= GetPos().Y + 1; j++)  //세로 영역
		{
			int2 Explosure(GetPos().X, j);
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Explosure, RenderChar);
		}
	}else if (Ex_Step_1 >= BoomCount && Ex_Step_2 < BoomCount)       //폭발 1단계
	{
		for (int i = GetPos().X - 2; i <= GetPos().X + 2; i++)
		{
			int2 Explosure(i, GetPos().Y);
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Explosure, RenderChar);
		}
		for (int j = GetPos().Y - 2; j <= GetPos().Y + 2; j++)
		{
			int2 Explosure(GetPos().X, j);
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Explosure, RenderChar);
		}
	}else if (Ex_Step_2 >= BoomCount && Ex_Step_End < BoomCount)      //폭발 2단계
	{
		for (int i = GetPos().X - 3; i <= GetPos().X + 3; i++)
		{
			int2 Explosure(i, GetPos().Y);
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Explosure, RenderChar);
		}
		for (int j = GetPos().Y - 3; j <= GetPos().Y + 3; j++)
		{
			int2 Explosure(GetPos().X, j);
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Explosure, RenderChar);
		}
	}
}

//Bomb 헤더에 ConsoleGameScreen.h 추가
//void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
//{
//	if (true == IsScreenOver(_Pos))
//	{
//		return;
//	}
//
//	ArrScreen[_Pos.Y][_Pos.X] = _Ch;
//}