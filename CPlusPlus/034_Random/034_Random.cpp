
#include <iostream>
#include <conio.h>

//키가 눌릴때까지 프로그램ㅇ을 정지시킨다. _getch();


int Seed = 0;

int Randomint()
{
    return;
}





int main()
{
    // time(0); utc 세계시간 기준으로한 현재시간을 리턴
    // 초단위이기 때문에 1초에 여러번 난수 생성하면 같은값나옴
    // 시간은 보통8바이트 정수로 준다
    __int64 Test = time(0);
    srand(Test);    

    while (1)
    {
        printf_s("%d\n", Randomint());
        _getch();
    }
    
}
