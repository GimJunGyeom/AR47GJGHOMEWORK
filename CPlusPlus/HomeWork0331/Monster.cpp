#include "Monster.h"
#include "ConsoleGameScreen.h"

Monster::Monster()
{
	RenderChar = 'M';
}

void Monster::Update()          //������ ����
{
	if (false == IsUpdate())
	{
		return;
	}

	Pos.X += Dir;
}

void Monster::DownUpdate()      //���� �浹�ϸ� �Ʒ��� ����
{
	if (false == IsUpdate())
	{
		return;
	}

	Pos.Y += 1;
	Dir = -Dir;                     //���� �浹�ؼ� ���������� ������ �̵��ϴ� ������ �ٲ۴�
}

