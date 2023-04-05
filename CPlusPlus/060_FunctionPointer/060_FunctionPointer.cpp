
#include <iostream>


void Test()
{
	printf_s("Test function\n");
}



int main()
{

	//리턴값 (*함수포인터명) (인자)
	void(*Ptr)() = nullptr;
	Ptr = Test;

	Ptr();

	{
		void(*Ptr[10])();
		void(**Ptr2)() = Ptr;

	}

	//그래서., 함수포인터는 어따써요? ==> 함수 오버라이딩의 원리가 가상함수문법입니다. 가상함수 문법이 바로 함수 포인터로 구현되는 원리입니다.
}

