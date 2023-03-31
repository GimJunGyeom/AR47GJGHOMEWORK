#include "Monster.h"
#include "ConsoleGameScreen.h"

Monster::Monster()
{
	RenderChar = 'M';
}

void Monster::Update()          //옆으로 간다
{
	if (false == IsUpdate())
	{
		return;
	}

	Pos.X += Dir;
}

void Monster::DownUpdate()      //벽에 충돌하면 아래로 간다
{
	if (false == IsUpdate())
	{
		return;
	}

	Pos.Y += 1;
	Dir = -Dir;                     //벽에 충돌해서 내려왔으니 옆으로 이동하는 방향을 바꾼다
}

