#include <iostream>

//overload - 과중한 짐, 과적. ~에 짐을 너무 많이 싣다, 부담을 많이 지우다.
//override - ~보다 우위에 서다, 짓밟다. ~을 재정의 하다.

//밑의 두 함수의 이름은 같지 않다. 함수의 인자까지가 함수의 이름이기 때문.
//인자는 함수 이름에 포함되는 반면에 리턴값은 함수 오버로딩에 영향을 주지 않는다.
void Function()
{

}

void Function(int _Value)
{

}

//밑의 두 함수는 다른 함수이지만 이런 오버로딩은 인자값 넘길때 자료형을 명시해줘야 헷갈리지 않으므로 별로 좋은 오버로딩이 아니다.
void Function(short _Value, int _Test)
{
	printf_s("short, int\n");
}
void Function(int _Value, int _Test)
{
	printf_s("int, int\n");
}





int main()
{
	Function(10, 10);  //과연 어떤 함수가 실행될까?
	Function((short)10, 10);
	Function((int)10, 10);

	//첫번째 Function이 뭐가 호출됬건, 컴파일러가 알아서 해주는거지 저런식으로 오버로딩 시킨 함수 자체가 모호하기때문에 좋지 않다는 것. 
	//오버로딩 할라면 안 헷갈리게 인자값의 자료형을 확실히 구별되는 걸로 하던지 해야함
}

