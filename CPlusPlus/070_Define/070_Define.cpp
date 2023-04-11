
#include <iostream>

//define 전처리기 지시문이란? - 특정코드의 내용을 적어준 코드의 내용대로 완전히 똑같이 바꿔적어주는 전처리기 지시문입니다.
//#define 내용1 내용2
// 내용1을 내용2로 완전히 바꿔줌
// define은 컴파일러가 문법검사 같은걸 전혀 안해주기 때문에 잘쓰면 편하게 쓸수 있고 못쓰면 큰일납니다.



#define TEN 10grafgf;;tgtp
//특정문자를 엔터치기 전까지의 모든코드로 대체 (TEN ==> 10grafgf;;tgtp)

//define의 다른 사용법- 매크로 함수
#define PLUS(Value1, Value2) Value1 + Value2
//대부분 define 보다 inline을 쓰라고 하는 이유는 inline은 문법검사를 해주기 때문입니다.

int main()
{
	//매크로 함수는 컴파일러가 함수의 문법검사를 해주지 않는다.
	PLUS("ggasf3", 5); //이거는 나중에 "ggasf3" + 4 로 바뀌게 됩니다.
	
}