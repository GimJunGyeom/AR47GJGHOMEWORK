#include "Parts.h"

Parts::Parts()
{
}

Parts::~Parts()
{
}

void Parts::Update()
{
	ConsoleGameObject::Update();
}

void Parts::NextMove()
{
	Parts* Next = GetNext();

	if (nullptr == Next)
	{
		return;
	}

	Next->SetPos(GetPrevPos());
	Next->SetMyDir(GetMyPrevDir());
	Next->SetMyRenderChar(Next->GetMyDir());
	return Next->NextMove();
}

