
#include <iostream>

class A
{
	//private: 디폴트 접근제한 지정자
	//public: A(){} 디폴트 생성자
	//       ~A(){} 디폴트 소멸자
	
	//A(const A& _Other) = delete             디폴트 복사생성자
	//A(A&& _Other) = delete                  디폴트 Rvalue 복사생성자
	//A& operator=(const A& _Other) = delete  디폴트 대입연산자
	//A& operator=(A&& _Other) = delete       디폴트 RValue 대입연산자
	

	// = delete 선언 -> 함수를 사용안하겠다(== 비활성화 하겠다)는 선언

};

int main()
{
	A NewA0 = A();
   
}

