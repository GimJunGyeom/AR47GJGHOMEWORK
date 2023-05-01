

#include <iostream>

//템플릿은 선언과 구현을 분리할 수 없다. typename을 똑같이해도 에러가 난다.
// 선언, 구현이 분리되어 있으면 컴파일러 입장에선 typename의 이름이 같아도 헤더파일과 cpp파일에 있는 typename 이름은 전혀 다른 것이라고 생각한다.

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

//컴파일하면 오류가난다. 컴파일은 알수없는 참조라고 오류를 낸다.
//c++은 템플릿문법에서 선언과 구현을 분리할 수없다. 꼭 하나의 파일에 선언된 typename이 같이 사용되어야한다.
//선언과 구현을 템플릿문법에서 분리하는 경우는 템플릿 특수화를 할때 이다.


//왜 오류가 날까.
//컴파일러가 템플릿코드를 복붙하는 원리를 이해해야한다.
//컴파일러는 템플릿이 사용된 코드가 있으면 그 템플릿이 선언된 곳으로 가서 코드를 똑같이 복사하고, 붙여넣기를 !!템플릿을 실제로 쓰는 파일!! 위에 한다.
//붙여넣기 할때 자료형만 알아서 고치고 붙여넣어 주는 것이다.
//근데 선언만 되어있으면? 붙여넣기 하고 싶어도 구현된걸 못찾으니 알수 없는 참조가 되는 것이다.
//예를들어 main 함수는 template.h 파일에 있는 템플릿을 쓴다고 하자. 구현은 template.cpp 에 분리되어 있다. 
//main 함수는 template.h 을 include 한다.
//main 함수는 template.h 파일의 템플릿 함수를 사용하려고 하면 컴파일에러가 난다.
//컴파일러는 템플릿클래스를 만드려고 헤더파일로 갔더니 선언만 되어있고 구현이 안되어있다. main에서 include는 헤더파일만 하고 cpp는 하지 않았으므로 
//컴파일 단계에선 구현을 확인할 도리가 없다. 템플릿은 반드시 컴파일 단계에서 구현부를 컴파일러가 확인하고 코드를 알맞게 붙여넣기 해야하는데 
//그렇다고 main 함수에 .h 파일과 .cpp 파일 까지 include하면 선언이 여러번 정의된 기호가 있다고 오류 띄운다.

//inline이 동작하는 원리와 비슷하다고 하니 찾아볼것.


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

//사실 템플릿의 선언과 구현을 분리해도 되는 방법(.hpp)이 찾아보니 있긴한데... 별로 추천되지는 않는듯?

