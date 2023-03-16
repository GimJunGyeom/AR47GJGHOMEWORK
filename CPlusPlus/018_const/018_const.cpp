
#include <iostream>

int main()
{
	/*
	int ArrSize = 20;
	int Value[ArrSize] = { 30 };
	어 왜 안되지? => 이유는 함수의 스택에서의 메모리 크기는 컴파일시 고정되어야 하기 때문이다.따라서 배열선언에 변수를 사용할 수 없다. 배열선언에는 '상수'를 써야한다.
	즉, 메모리 할당 영역이 exe파일에 미리 정해져 있어야 하는것이다 

	(자바 같은 언어는 할 수 있음)
	*/

	/*
	특정 자료형 앞에 const 키워드를 붙이면 그 메모리영역을 '상수화'한다. 다시말해, 그 메모리 영역안의 비트를 단 하나라도 내용을 바꿀 수 없다. 
	사용법 - const 모든자료형 변수이름 = 수;
	ex) const int Value = 20;
	    "Testchar";
	*/

	const int Value = 20;
	char ArrValue[Value] = {};

}
