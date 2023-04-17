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
	if (true == GetMeetTohead())  //�Ӹ��� �� �浹�ϸ� �� ���� ��ǥ �����
	{
		//��ó���� ������ġ �����ش�
		int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
		int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);

		int2 FirstPartsPos(X, Y);
		int2 NewPartsPos(X, Y);
		
		do  //����� ���ö����� ��ǰ�� ����ġ�� ã�´�
		{
			char ScreenPlaceChar = ConsoleGameScreen::GetMainScreen().GetScreenCharacter(NewPartsPos);
			if (ScreenPlaceChar != 'a')  //����� �ƴϸ� ��ĭ�� �̵��Ͽ� Ž��
			{
				if (NewPartsPos.X == ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1)     //X��ǥ ���� �����ϸ� X = 0���� �ٽ� Ž��
				{
					NewPartsPos.X = 0;

					if (NewPartsPos.Y == ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1) //X��ǥ ���� �����ؼ� ���� Y ��ǥ�� �ٲ��ֱ�
					{
						NewPartsPos.Y = 0;
					}
					else
					{
						NewPartsPos.Y += 1;
					}
				}
				else                                                                               //X��ǥ �� �ƴϸ� �ٷδ��� X��ǥ�� �̵�
				{
					NewPartsPos.X += 1;
				}
			}
			else
			{
				break;
			}
		} while (NewPartsPos != FirstPartsPos);  //ȭ�鿡 ��ǰ �����ڸ� �ѹ� �� �ѷ��ôµ��� ���ڸ��� ���ƿ��� �׳�Ž������


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