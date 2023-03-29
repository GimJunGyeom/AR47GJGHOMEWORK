#include "Bullet.h"

Bullet Bullet::JustOneBullet{ {0,0} ,2 };

Bullet:: Bullet(const int2 _PlayerLocation, const char _PlayerLook)  // 총알은 위치와 가는 방향이 있어요
	:Bullet_Loc(_PlayerLocation), Bullet_Dir(_PlayerLook)
{
}


int2 Bullet::GetBullLoc() const  
{
	return Bullet_Loc;
}

void Bullet::SetBullLoc(const int2& _NewLocation, const char& _LookingDirection)  //플레이어 위치, 플레이어가 보는 방향을 바탕으로 총알의 위치, 이동방향을 정해줘요
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

char Bullet::GetBullDir() const  //총알이 이동하는 방향 알려주기
{
	return Bullet_Dir;
}

void Bullet::Bullet_Move()
{
	switch (Bullet_Dir)        //총알 발사된 방향에 따라서 어느 방향으로 위치를 한칸 이동할지 정해줘요
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