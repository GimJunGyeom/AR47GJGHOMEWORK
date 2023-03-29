#include <iostream>

class int2
{
public:
	int X = 0;
	int Y = 0;

public:
	inline int2 Half()
	{
		return { X / 2, Y / 2 };
	}

public:
	inline int2()
	{

	}

	// 생성자에 
	inline int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}
};

class Bullet
{
public:
	Bullet(const char _Direction)
		:Bullet_Dir(_Direction)
	{
	}



protected:

private:

	int2 Bullet_Loc{ 0, 0 };
	const int Bullet_Dir;
};


int main()
{

}