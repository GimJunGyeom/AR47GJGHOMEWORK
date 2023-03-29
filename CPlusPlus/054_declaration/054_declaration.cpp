
#include <iostream>

//함수를 볼때 두가지 부분으로 나눠서 봐야합니다. 함수선언, 함수체. 
//함수구현이라고 하는 문법은 함수선언과 함수체를 같이 놓은 것을 말하고, 이런 함수를 '구현된 함수'라고 부른다

//함수선언
void Function() 
//함수체
{
}

//이때, 함수선언만을 따로 놓을 수 있습니다. 이런 문법을 만들어 놓은 이유는, 함수끼리 서로 호출할때 명시적으로 이 함수가 실재한다는 사실을 알려줘서 절차적인 코드 실행시 오류를 막아주기 때문입니다.
/*
*  void Function_2()
* {
*	void Function_1();
* }
* // Function_1이 Function_2보다 아래에 구현되어 있었다면, 코드 절차적으로 수행하고 있었을때 이 순간만은 Function_1은 없었기 때문에 없는 함수를 호출햇다는 오류가 생김.
*/
//따라서 코드 맨 상단부에 함수선언을 미리 작성해놓으면 이 함수가 없는 함수가 아니라 구현이 되있는 함수라고 미리 선언하는 역할을 하는 것입니다

//함수선언만 놓는법 - 함수선언에 ; 붙이기
void Function_2();
void Function_1();

//클래스 내부함수는 선언만해 놓았다면 반드시 클래스 외부에 함수 풀네임 써주면서 구현시켜 놔야함
class Player
{
public:
	void Function();
	int a = 0;
};

void Player::Function()
{

}
//클래스 내부에서 함수구현을 다 해놓았다면 클래스 밖에서 재구현 할수는 없음. 

//static변수는 선언과 구현을 무조건 따로 하게 만들었다. 즉, 초기화를 할 수가 없다는 것이다.
//무슨 말이냐면 static 변수는 클래스 내부에서 선언만 해놓을 수 있고 실제값은 밖에서 실제값을 넣어줘야 실체가 생기는 것이다.
// static 변수 선언은 코드영역에 있는거고, 거기에 실제값을 넣어줘야 데이터영역에 실체가 생긴다. 
//골때리는게 c++은 클래스 내부 static 변수는 리터럴 초기화가 안됨..why? 앞서 말했다시피 static 변수는 데이터 영역에 클래스의 모든 객체가 공유하는 거라고 했는데 
//만약 이런 static 변수를 클래스 내부에서초기화를 해준다면 객체가 생성될 때마다 static 변수가 리셋되어버리기 때문에 문법적으로 막은 것임. 따라서 static 변수는 클래스 밖에서 따로 초기화를 해줘야함.

//예시 - static Value = 0; 이라는 변수가 클래스 내부에서 초기화 됬다고 치자. myclass A = myclass(); 라고 객체 A가 만들어진 후 Value 값을 3으로 바꿨다. 
//근데 갑자기 myclass B = myclass(); 라는 새로운 객체 B를 만들면 Value가 또 0으로 초기화 되버리고 3이란 값은 증발해버림. 이래서 static 변수는 클래스 내부에 초기화 못하도록 믄법적으로 선언과 구현을 분리시켜놓은 것임

class Test
{
public:
	Test()
		:Value1(0)
	{
	}
	// static int Value = 0; 오류남
	static int Value0;
	const int Value1;  // 위에 Test 생성자에서 초기화 안해주면  오류남
	const int Value2 = 0;
	static const int Value3;
	static const int Value4 = 0; //static인데도 const가 있기 때문에 바로 초기화 시킬 수가 있음. static const 는 상수로 생각해서 코드영역에 위치시키기 때문이다.
	                             //정리하자면, 클래스 내부에서 static만 있다면 선언과 구현을 따로 해줘야 하지만, static const는 선언과 동시에 구현을 시킬 수 있다는 것이다.
	                             //원래 const 있으면 무조건 선언과 구현을 같이 해야되는데 앞에 static이 붙으면 초기화는 무조건 해야하는건 변함없지만 선언과 구현을 따로 시킬 수 있는, 초기화 방법이 2개로 늘어난 것임.
	int Value5 = 0;
	int Value6 = 0;
};

//Value 0과 Value3은 밑에 외부초기화 안적어두면 나중에 LNK2001 확인할 수 없는 외부기호 라는 오류 날 것임.
int Test::Value0 = 0;
const int Test::Value3 = 0;



//const int Value3;

int main()
{
	Test Mytest = Test();
	__int64 Arr0 = (__int64)&Mytest.Value0;
	__int64 Arr1 = (__int64)&Mytest.Value1;
	__int64 Arr2 = (__int64)&Mytest.Value2;
	__int64 Arr3 = (__int64)&Mytest.Value3;
	__int64 Arr4 = (__int64)&Mytest.Value4;
	__int64 Arr5 = (__int64)&Mytest.Value5;
	__int64 Arr6 = (__int64)&Mytest.Value6;

	//정리:: 
	//코드영역 - 전역 const변수, 클래스의 static const변수   (Value3, Value4)
	//데이터영역 - 클래스의 static 변수                      (Value0)
	//스택영역 -  클래스의 const변수, 일반 맴버변수          (Value1, Value2, Value5, Value6)
	
	//!!(전역 const가 코드영역에 있는거고 클래스 const는 스택에 있음. 클래스 const가 코드영역에 있다고 착각하지마라 - 위 예시에 Value1 Value2 Value5 Value6 네 변수들이 연속적인 메모리에 있다는걸 확인하라)
	//!!(static 변수 Value0 하고 static const 변수 Value3 Value4 의 주소가 의미있게 아주 멀리 떨어져 있음을 확인하라. static은 데이터영역, static const는 코드영역.)

	int a = 0;
}
