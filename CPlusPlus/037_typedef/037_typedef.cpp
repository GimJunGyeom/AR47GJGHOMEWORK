

#include <iostream>

//컨트롤 시프트 g - #include <파일명>으로 이동

//typedef  - 자료형을 새로운 이름으로 정의할때 사용하는 키워드. 사용자 정의 자료형의 일종이다. 코드 길이을 줄여서 코드의 복잡성을 줄이고 유지보수 쉽게하려고 많이사용
typedef __time64_t time_t; //한번 이름 재정의한 자료형을 또 한번더 재정의 할 수 있음. __int64 == __time64_t == time_t 결국 세개 다 __int64 자료형임.

//최신용법 using과 typedef의 효과는 똑같음.
using Myint1 = int;
typedef int Myint2;

//컴파일 시간이 늘어나고 어차피 나중에 이게 무슨 자료형인지 찾아봐야하기 때문에 사용하는게 별이득같지는 않다.

int main()
{
    time_t Dtime = time(0);

}
