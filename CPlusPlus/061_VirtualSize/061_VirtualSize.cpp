﻿#include <iostream>


// 맴버변수가 아무것도 없는 클래스는 문법적인 통일성을 위해 0 바이트가 아니라 1 바이트라는 최소한의 크기를 주는 것이다.
// 예로들어, 맴버변수가 아무것도 없는 클래스는 스택에 0바이트가 쌓니는게 원래 정상이지만, 그러면 그 클래스의 배열을 만들면 포인터가 이동할 수 없으니 문법적인 예외가 생겨버림
// 그래서 그냥  맴버변수없는 클래스에도 1바이트 정도 메모리줘서 문법적인 통일성을 만든것이다.



int main()
{
   
}
