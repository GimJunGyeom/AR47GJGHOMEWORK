
#include <iostream>
#include <conio.h> //콘솔 인풋 아웃풋. _getch(), kbhit() 함수 들어있음

// 키가 눌릴때까지 프로그램을 정지시킨다. _getch();
// C의 scanf 와 C++의 cin과 다르게 getch()는 입력버퍼를 사용하지 않기 때문에, 입력후 엔터기를 누르지 않아도 키보드 누름과 동시에 값이 입력된다.
// 게다가 space와 Enter 같은 특수키도 입력이 가능하다.
// 키보드 입력은 ASCII코드로 값이 입력된다.
// getch()는 마지막에 입력된 키 하나만 입력하기에 두 키를 동시에 눌러도 하나만 인식한다. 

// kbhit() = 키보드 입력확인. true/false

//int Seed = 0;
//
//void Randomint()
//{
//    return;
//}





void main()
{
    std::cout << "Ok" << std::endl;
    //{
    //    // time(0); utc 세계시간 기준으로한 현재시간을 리턴
    //    // 초단위이기 때문에 1초에 여러번 난수 생성하면 같은값나옴
    //    // 시간은 보통8바이트 정수로 준다
    //    __int64 Test = time(0);
    //    srand((int)Test);
    //}
  /*  int a = 0;
    {
        char c = 0;
        while (true)
        {
            
            if (_kbhit())
            {
                c = _getch();

                switch (c)
                {
                case 1:
                    std::cout << c << std::endl;
                    break;
                default:
                    std::cout << "??" << std::endl;
                    break;
                }

            }
        }
    }*/
}
