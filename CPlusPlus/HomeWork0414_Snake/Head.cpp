#include "Head.h"

bool Head::IsPlay = true;
int Head::EndGameReason = 0;

Head::Head()
{
	RenderChar = '$';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head()
{
}

bool Head::IsPartsCheck()
{
	std::list<ConsoleGameObject*>& PartsGroup = ConsoleObjectManager::GetGroup(SnakeEnum::Parts);
	int2 PartPos = PartsGroup.front()->GetPos();
	int2 HeadPos = this->Pos;

	if (PartPos == HeadPos)
	{
		Parts::SetMeetToHeadTrue();
		return true;
	}

	return false;
}


void Head::SetForePos(int2 _Pos)
{
	ForePos = Pos;
}

void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
		EndGameReason = 1;
	}


	if (0 == _kbhit())
	{
		// SetPos(GetPos() + Dir);
		IsPartsCheck();
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
	{
		Dir = int2::Left;
		break;
	}
	case 'd':
	case 'D':
	{
		Dir = int2::Right;
		break;
	}
	case 'w':
	case 'W':
	{
		Dir = int2::Up;
		break;
	}
	case 's':
	case 'S':
	{
		Dir = int2::Down;	
		break;
	}
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		return;
	}

	SetForePos(Pos);
	SetPos(GetPos() + Dir);

	//ȭ�� ���̵� üũ
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
		EndGameReason = 1;
	}

	//�� �浹 üũ
	bool BodyClashCheck = Body::IsHeadClashedBody(Pos);
	if (true == BodyClashCheck)
	{
		IsPlay = false;
		EndGameReason = 2;
	}

	//��ǰ ȹ�� üũ
	bool PartsClashCheck = IsPartsCheck();
	if (true == PartsClashCheck)
	{
		Body::AttachBody(ForePos);     //���ο� �� ������ �Ӹ��� �̵��ϱ� �ٷ� ���� �ڸ��� ���� ���� �����
	}
	else 
	{
		Body::AttachTail(ForePos);     //�̵��ߴµ� �� �� �Ծ����� �׳� �ٿ����ִ� ������ �̵���Ŵ
	}

	//���� �¸� ���� üũ
	int2 ComPareWithScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	int CountForEndGame = ComPareWithScreenSize.X * ComPareWithScreenSize.Y - 1;     //ȭ�� ũ�⿡ �÷��̾� ���� ����
	if (Body::TailBodyCount == CountForEndGame)
	{
		IsPlay = false;
		EndGameReason = 3;
	}


}
