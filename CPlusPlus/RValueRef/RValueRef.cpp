
#include <iostream>

int Function()
{
    return 10;
}


int main()
{
    //LValue - 왼쪽(Left)에 올수 있는 변수 - 특정값 대입이 가능하고 메모리 영역을 특정할 수 있는 변수
    //RValue - 오른쪽(Right)에만 올수 있는 변수 - 사용 및 참조만 할 수 있는 변수
    int Value0 = 10; //Value0 == LValue, 10 == RValue

    //& (일반레퍼런스)는 LValue Ref (LValue만 받을수 있는 레퍼런스) 이다
    int& Test0 = Function(); //일반레퍼런스는 LValue 만 받을수 있음 (일반 레퍼런스는 LValue 처럼 메모리 특정이 가능한 요소만 받음)
    int&& Test1 = Function(); // RValue 까지 받을 수 있는 RValue Ref.

    int&& Test2 = Value0; //그렇다고 RValue Ref 가 LValue 주소까지도 받지는 못함.

