#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen;
class Player
{
public:
	Player();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	void Input();


	inline bool IsFire()
	{
		return Fire;
	}

	char GetLookingDirection() const      //플레이어가 보고있는 방향 알려줌
	{
		return LookingDir;
	}

	void SetLookingDirection(const char _Direction)  //플레이어가 가고있는 방향(==총알방향) 설정
	{
		LookingDir = _Direction;
	}

protected:

private:
	static const int InterFrame = 200;

	bool Fire = false;

	int2 Pos = int2(0, 0);

	char LookingDir = Lookdown;     //플레이어가 보고있는 방향인 동서남북을 숫자로 저장

	static const int Lookup = 1;    //위
	static const int Lookdown = 2;  //아래
	static const int Lookleft = 3;  //왼쪽
	static const int Lookright = 4; //오른쪽
};
