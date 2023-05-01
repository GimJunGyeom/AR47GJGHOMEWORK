

#include <iostream>

//템플릿은 선언과 구현을 분리할 수 없다. typename을 똑같이해도 에러가 난다.
// 컴파일러 입장에선 typename이 같아도 헤더파일과 cpp파일에 있는 typename은 전혀 다른것이다.

//헤더파일의 상황
template<typename Datatype>
class Temp
{
public:
	Datatype Value0 = 0;
	void Function(Datatype);
};

//cpp 파일상황
template<typename Datatype>
void Temp<Datatype>::Function(Datatype _Value)
{
	Datatype Value1 = _Value;
}

//컴파일하면 오류가난다. 헤더파일의 Datatype 과 cpp 파일의 Datatype은 컴파일 입장에서 전혀 다르게 해석한다. 컴파일은 알수없는 참조라고 오류를 낸다.
//c++은 템플릿문법에서 선언과 구현을 분리할 수없다. 꼭 하나의 파일에 선언된 typename이 같이 사용되어야한다.
//선언과 구현을 템플릿문법에서 분리하는 경우는 템플릿 특수화를 할때 이다.

//템플릿을 쓰는 요소가 호출(사용)될때, 컴파일러는 선언이 있는 파일이 아니라 호출한 파일에 코드를 복붙해서 써준다.

//옳게된 템플릿 사용법 - 선언과 구현을 무조건 같이.
template<typename Datatype>
class Temp0
{
public:
	Datatype Value0 = 0;
	void Function(Datatype _Value)
	{
		Datatype Value1 = _Value;
	}
};

//선언과 구현의 분리를 할떄는 템플릿 특수화를 할때일뿐.
template<>
void Temp0<int>::Function(int _Value)
{
	int Value1 = _Value;
}

int main()
{


}


