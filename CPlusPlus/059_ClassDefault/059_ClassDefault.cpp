
#include <iostream>

class A
{
public:
	//private: 디폴트 접근제한 지정자
	// A(){} //디폴트 생성자
	//~A(){} //디폴트 소멸자
	
	//A(const A& _Other) = delete           //  디폴트 복사생성자. 얕은복사
	//A(A&& _Other) = delete;                  //  디폴트 Rvalue 복사생성자
	A& operator=(const A& _Other) = delete;//  디폴트 대입연산자
	//A& operator=(A&& _Other) = delete;       //  디폴트 RValue 대입연산자
	

	// = delete 선언 -> 함수를 사용안하겠다(== 비활성화 하겠다)는 선언

public:
	int Value0 = 1;

};

int main()
{
	A NewA0 = A();
	A NewA1 = NewA0;
	A NewA2 = A(NewA0);

	NewA0.Value0 += 10;

	std::cout << NewA0.Value0 << std::endl;
	std::cout << NewA1.Value0 << std::endl;
	std::cout << NewA2.Value0 << std::endl;
}

