
#include <iostream>

//밑의 두 클래스는 '순환참조'이라는 상황에 빠져있다. 서로가 서로를 참조해야하는 상황
//순환참조로 인한 오류를 예방할 방법은 선언과 구현을 철저히 분리하는 것이다. - 클래스 전방선언, 맴버함수 전방선언 등

class Player
{
public:
	int Att = 10;
	int Hp = 100;

	void Attack(Monster* _Monster)
	{
		_Monster->Hp -= Att;
	}
};

class Monster
{
public:
	int Att = 10;
	int Hp = 100;

	void Attack(Player* _Player)
	{
		_Player->Hp -= Att;
	}
};

// 클래스 전방선언 -  클래스 존재한다고 미리  알려주기
class Monster0;
class Player0;


//맴버함수 전방선언 및 구현
class Player0
{
public:
	int Att = 10;
	int Hp = 100;

	void Attack(Monster* _Monster);
};

class Monster0
{
public:
	int Att = 10;
	int Hp = 100;

	void Attack(Player* _Player);
};

void Player0::Attack(Monster* _Monster)
{
	_Monster->Hp -= Att;
}

void Monster0::Attack(Player* _Player)
{
	_Player->Hp -= Att;
}

//전방 선언으로도 안되는경우 = 컴파일러가 클래스의 모든 내용을 알아야 겠다고 하는 상황. 
//전방선언한 클래스의 맴버함수나 맴버변수에 직접적으로 접근해 사용하려는 상황이 그러한 상황. 

//다음은 Player 객체 안에서 전방선언만 된 Monster 객체를 사용하는 상황이다. 오류가 안나는 경우는 무엇일까

class Monster2;
class Player2
{
	Monster2* Test(Monster2* _NewMonster)    //포인터는 전방선언된 객체에 직접적인 정보가 필요없음 그냥 본인 주소값만 넘기면 되는 함수임 그래서 오류안남
	{
		return _NewMonster;

	}

	//int Test2(Monster2* _NewMonster)     //Monster 객체의 구체적인 정보가 뭔지 알아야 컴파일러가 처리 가능하다고 판단 하므로 오류남
	//{
	//	return _NewMonster->Hp -= 10;

	//}

	//Monster2 Test2(Monster2 _NewMonster)     //Monster 객체의 실제적인 크기가 뭔지 알아야 스택에서 실행흐름 만들고 메모리 공간 할당해야하는데 이건 전방선언 만으론 알 수 가 없어 오류남
	//{
	//	return _NewMonster;

	//}
};




int main()
{
 
}

