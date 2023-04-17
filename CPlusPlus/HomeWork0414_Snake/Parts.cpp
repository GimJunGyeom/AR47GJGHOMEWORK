#include "Parts.h"

bool Parts::MeetToHead = false;

Parts::Parts()
{
	RenderChar = '#';
	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
	SetPos({ X, Y });
}

Parts::~Parts()
{
}

void Parts::Update()
{
	if (true == GetMeetTohead())  //머리랑 몸 충돌하면 새 몸의 좌표 찍어줌
	{
		//맨처음은 랜덤위치 정해준다
		int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
		int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);

		int2 FirstPartsPos(X, Y);
		int2 NewPartsPos(X, Y);
		
		do  //빈공간 나올때까지 부품의 새위치를 찾는다
		{
			char ScreenPlaceChar = ConsoleGameScreen::GetMainScreen().GetScreenCharacter(NewPartsPos);
			if (ScreenPlaceChar != 'a')  //빈공간 아니면 한칸씩 이동하여 탐색
			{
				if (NewPartsPos.X == ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1)     //X좌표 끝에 도달하면 X = 0부터 다시 탐색
				{
					NewPartsPos.X = 0;

					if (NewPartsPos.Y == ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1) //X좌표 끝에 도달해서 다음 Y 좌표로 바꿔주기
					{
						NewPartsPos.Y = 0;
					}
					else
					{
						NewPartsPos.Y += 1;
					}
				}
				else                                                                               //X좌표 끝 아니면 바로다음 X좌표로 이동
				{
					NewPartsPos.X += 1;
				}
			}
			else
			{
				break;
			}
		} while (NewPartsPos != FirstPartsPos);  //화면에 부품 만들자리 한번 싹 둘러봤는데도 제자리로 돌아오면 그냥탐색종료


		SetPos(NewPartsPos);
		SetMeetToHeadfalse();
	}
}


void Parts::SetMeetToHeadTrue()
{
	MeetToHead = true;
}
void Parts::SetMeetToHeadfalse()
{
	MeetToHead = false;
}

bool Parts::GetMeetTohead()
{
	return MeetToHead;
}