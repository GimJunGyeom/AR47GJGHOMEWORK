
#include <iostream>

//class 내부에 정의된 변수 중에 자료형의 크기가 가장큰 것을 기준으로 바구니 담듯이 변수에 메모리 영역을 할당. 
//클래스의 변수 선언시 빈공간이 생기는 영역을 패딩바이트라함

//숙제 
class A
{
public:
    int a;   //8바이트 할당
    short b;
    __int64 c; //8바이트 할당
};


int main()
{
    std::cout << "Hello World!\n";
}

