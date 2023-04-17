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

	//화면 밖이동 체크
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
		EndGameReason = 1;
	}

	//몸 충돌 체크
	bool BodyClashCheck = Body::IsHeadClashedBody(Pos);
	if (true == BodyClashCheck)
	{
		IsPlay = false;
		EndGameReason = 2;
	}

	//부품 획득 체크
	bool PartsClashCheck = IsPartsCheck();
	if (true == PartsClashCheck)
	{
		Body::AttachBody(ForePos);     //새로운 몸 먹으면 머리가 이동하기 바로 이전 자리에 꼬리 새로 만들기
	}
	else 
	{
		Body::AttachTail(ForePos);     //이동했는데 몸 안 먹었으면 그냥 붙여져있던 꼬리만 이동시킴
	}

	//게임 승리 조건 체크
	int2 ComPareWithScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	int CountForEndGame = ComPareWithScreenSize.X * ComPareWithScreenSize.Y - 1;     //화면 크기에 플레이어 개수 제외
	if (Body::TailBodyCount == CountForEndGame)
	{
		IsPlay = false;
		EndGameReason = 3;
	}


}
