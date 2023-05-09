// 086_UnionAndDataPadding.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//구조체를 바로 변수화 시키는 문법. (구조체 이름이 없음) 
struct
{
	int a;
} Value;


//위 코드는 다음코드와 같음
struct Myclass
{
	int a;
};
Myclass Value0;

//union 내부에 의미있는 변수가 있으면 그중 가장큰 변수를 중심으로 같은 위치에 다른이름을 준다.
union MyUnion
{
	__int64 C;
	int A=0;  
	int B;
	//int A = 0; 오류남. 초기화는 변수 하나만 할 수 있음. c에서는 맨 첫번쨰 변수만 초기화가능
};

class ClassUnion
{
	//union의 이름이 없으면 그냥 메모리 구조만 union 답게 해달라는 것이다. 즉, 변수 a와 b는 클래스의 멤버변수이지만 메모리 구성만 union 처럼 쓰겠단 것이다.
	union
	{
		int a;
		int b;
	};

	//union 이름이 있으면 이건 그낭 클래스 내부에 유니온을 정의한 거다.
	union MyUnion
	{
		int c;
		int d;
	};

	//Value0은 e,f의 껍데기역할만 함. 즉 변수 e,f는 ClassUnion의 멤버변수 이고, 풀네임이 Value0.e, Value0.f이다. 그리고 추가적으로 메모리 구조는 union이다.
	union
	{
		int e;
		int f;
	} Value0;

	//위에 Value0과 확실히 다른 뜻이다. ClassUnion의 멤버변수로 Value1이 있는것이고, Value1은 또 e, f를 멤버로 가진 것이다. 
	union NameExistUnion
	{
		int e;
		int f;
	} Value1;
	
	//Value0은 ClassUnion의 멤버 변수가 아님. 그냥 ClassUnion의 멤버변수인 e,f의 껍데기 이름 역할만함. 
	//Value1은 ClassUnion의 멤버 변수임. 그리고 그 안에 Value1의 멤버로 e,f가 들어있음.

};

int main()
{
  
}

