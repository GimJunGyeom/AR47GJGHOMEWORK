#pragma once

#include "ConsoleGameMath.h"


class Bullet
{
public:

	static Bullet JustOneBullet;

	Bullet(const int2 _PlayerLocation, const char _PlayerLook);


	int2 GetBullLoc() const;
	void SetBullLoc(const int2& _NewLocation, const char& _LookingDirection);
	char GetBullDir() const;
	void Bullet_Move();

protected:
private:

	int2 Bullet_Loc;
	char Bullet_Dir;
	static const char Bullet_Up = 1;
	static const char Bullet_Down = 2;
	static const char Bullet_Left = 3;
	static const char Bullet_Right = 4;
};



