
#include <iostream>

//객체지향을 깨는 문법이 friend 이다
//C++은 객체지향언어가 아니여서 필요하면 쓴다 단, 최소한으로.
//언제 사용하면 좋나?
// 이너클래스 끼리 private 으로 선언됬을때 서로 어차피 외부에는 공개 안되고 한 외부클래스 내부에서 서로 쓰겠다면 friend 써서 private도 사용하게 해주면 그건 나쁘지 않은 방식.


class B;
class A
{
	friend B; //private으로 선언한것도 이 클래스는 예외로 사용하게 해줌
private:
	int Value = 0;
};

class B
{
public:
	void Function(A& _Other)
	{
		_Other.Value = 20;
	}
};



int main()
{
	A NewA = A();
	B NewB = B();

	NewB.Function(NewA);
}

