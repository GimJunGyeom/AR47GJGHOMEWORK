
#include <iostream>

//C++은 영역이 전역 지역 맴버 Namespace 이렇게 4종류가 있음

//어느 영역에도 속하지 않는 것을 전역이라고 함.
//전역안에 선언된 함수를 전역함수라고 함

//Test 전역함수
void Test()
{

}

//Glabal 전역변수
int Global = 10;

//사용자 정의 자료형 내부의 공간은 맴버공간이라고한다. (지역이라고 하지 않고 class는 특별취급)
class Player
{
	//맴버공간
public:
	void Damage(int _Att)
	{
		//맴버공간 안에있는 지역
		int Value = 10; //맴버공간 안에 만들어진 지역변수
	}

};

int main()
{

}

