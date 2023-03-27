
#include <iostream>

//c++은 전역의 존재 때문에 엄밀한 객체지향 언어가 아님. 오직 객체, 클래스로만 동작하는게 객체지향.
class Monster
{
public:
	//모든 객체가 공유하는 데이터가 필요할때 데이터 영역에 있는 static 변수 씀 그래서 막상 객체 안(스택영역)에는 없다. 그래서 static 변수는 클래스 이름으로도 접근이 가능함.
	static int MonsterCount;
	//즉 static은 같은 클래스의 객체들끼리만 공유하는 전역변수.



private:
	static int MonsterCount_pri; //몬스터 객체만 접근가능
};

int main()
{
	Monster::MonsterCount = 20;
}
