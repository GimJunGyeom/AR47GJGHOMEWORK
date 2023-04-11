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
	if (Ex_Step_0 >= BoomCount)        //���� ���ڷκ���
	{
		if (BoomCount <= Ex_Step_End)   //���߽ð� �ѱ�� ��ź ����
		{
			Off();
		}
		RenderChar = '$';      //���߻���
	}
}


void Bomb::Render()
{
	ConsoleGameObject::Render();

	if (Ex_Step_0 >= BoomCount && Ex_Step_1 < BoomCount)              //���� 0�ܰ�
	{
		for (int i = GetPos().X - 1; i <= GetPos().X + 1; i++)  //���� ���� ���� 
		{
			int2 Explosion(i, GetPos().Y);
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Explosion, RenderChar);
		}
		for (int j = GetPos().Y - 1; j <= GetPos().Y + 1; j++)  //���� ����
		{
			int2 Explosure(GetPos().X, j);
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Explosure, RenderChar);
		}
	}else if (Ex_Step_1 >= BoomCount && Ex_Step_2 < BoomCount)       //���� 1�ܰ�
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
	}else if (Ex_Step_2 >= BoomCount && Ex_Step_End < BoomCount)      //���� 2�ܰ�
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

//Bomb ����� ConsoleGameScreen.h �߰�
//void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
//{
//	if (true == IsScreenOver(_Pos))
//	{
//		return;
//	}
//
//	ArrScreen[_Pos.Y][_Pos.X] = _Ch;
//}