// 068_DeepCopyAndShallow.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class A
{
public:
	int* NewInt = new int();

};


int main()
{
	A NewA0 = A();
	A NewA1 = A();

	NewA0 = NewA1; //얕은 복사 (디폴트 복사 대입연산자)
	//(디폴트) 복사 대입 연산자는 기본적으로 얕은 복사를 한다.
	//얕은 복사는 메모리 영역을 공유하는 복사인 것이다.

	//반면에 새로운 메모리 영역에 기존 머모리 공간을 복사하는 것은 깊은 복사라고 한다. 
	//깊은 복사는 복사된 코드끼리 메모리를 공유하지 않는다.
	


}

