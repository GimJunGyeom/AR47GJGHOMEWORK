#include "Bullet.h"

Bullet Bullet::JustOneBullet{ {0,0} ,2 };

Bullet:: Bullet(const int2 _PlayerLocation, const char _PlayerLook)  // �Ѿ��� ��ġ�� ���� ������ �־��
	:Bullet_Loc(_PlayerLocation), Bullet_Dir(_PlayerLook)
{
}


int2 Bullet::GetBullLoc() const  
{
	return Bullet_Loc;
}

void Bullet::SetBullLoc(const int2& _NewLocation, const char& _LookingDirection)  //�÷��̾� ��ġ, �÷��̾ ���� ������ �������� �Ѿ��� ��ġ, �̵������� �������
{
	switch(_LookingDirection)
	{
	case Bullet_Up:
		Bullet_Loc.X = _NewLocation.X;
		Bullet_Loc.Y = _NewLocation.Y-1;
		Bullet_Dir = Bullet_Up;
		break;
	case Bullet_Down:
		Bullet_Loc.X = _NewLocation.X;
		Bullet_Loc.Y = _NewLocation.Y+1;
		Bullet_Dir = Bullet_Down;
		break;
	case Bullet_Left:
		Bullet_Loc.X = _NewLocation.X-1;
		Bullet_Loc.Y = _NewLocation.Y;
		Bullet_Dir = Bullet_Left;
		break;
	case Bullet_Right:
		Bullet_Loc.X = _NewLocation.X+1;
		Bullet_Loc.Y = _NewLocation.Y;
		Bullet_Dir = Bullet_Right;
		break;
	}
}

char Bullet::GetBullDir() const  //�Ѿ��� �̵��ϴ� ���� �˷��ֱ�
{
	return Bullet_Dir;
}

void Bullet::Bullet_Move()
{
	switch (Bullet_Dir)        //�Ѿ� �߻�� ���⿡ ���� ��� �������� ��ġ�� ��ĭ �̵����� �������
	{
	case  Bullet_Up:
		Bullet_Loc.Y -= 1;
		break;
	case  Bullet_Down:
		Bullet_Loc.Y += 1;
		break;
	case  Bullet_Left:
		Bullet_Loc.X -= 1;
		break;
	case  Bullet_Right:
		Bullet_Loc.X += 1;
		break;
	}
}