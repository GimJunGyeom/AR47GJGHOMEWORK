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

	char GetLookingDirection() const      //�÷��̾ �����ִ� ���� �˷���
	{
		return LookingDir;
	}

	void SetLookingDirection(const char _Direction)  //�÷��̾ �����ִ� ����(==�Ѿ˹���) ����
	{
		LookingDir = _Direction;
	}

protected:

private:
	static const int InterFrame = 200;

	bool Fire = false;

	int2 Pos = int2(0, 0);

	char LookingDir = Lookdown;     //�÷��̾ �����ִ� ������ ���������� ���ڷ� ����

	static const int Lookup = 1;    //��
	static const int Lookdown = 2;  //�Ʒ�
	static const int Lookleft = 3;  //����
	static const int Lookright = 4; //������
};
