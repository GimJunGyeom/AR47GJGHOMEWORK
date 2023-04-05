

#include <iostream> //crtdbg,h 가 iostream안에 있어서 따로 선언 안해줘도 됨.





void main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    {
        //중복할당
        int* Newint = new int();
        Newint = new int();

        //new는 운영체제가 할당해주는 거기 때문에 null체크 하고 써야되는게 습관되어야 한다. 왜냐면 운영체제가 할당안해줄수도 있으니. 중단점 걸어서 체크하는게 당연해야한다.
        if (nullptr == Newint)
        {
            return;
        }
    }

    {
        //지운거 또지우기 == 댕글링포인터
        int* Newint = new int();

        delete Newint;
        delete Newint;
        //메모리 크러쉬라고함
        //메모리 크러쉬는 그냥 프로그램이 꺼짐. (Ram에서 프로세스가 내려감)
    }

    {
        int* Newint = new int();

        //가장 안전한 메모리 삭제법
        if (nullptr != Newint)
        {
            delete Newint;
            Newint = nullptr;   //delete 했다고 포인터변수까지 당연히 nullptr 넣어주는 작업까지 해주는게 아니기 때문에 이 작업을 해줘야함. delete는 단순 메모리 할당을 회수해주는거지 포인터변수는 참견안함
                                //그냥 delete만 해주면 포인터 변수에는 쓰레기 값이 남아 있기때문에 불안하다. delete만 하고 포인터 변수에 중단점 걸어보면 쓰레기 값이 남아 있음을 알 수 있다.
        }
    }   
}
//정리 - 습관 1. 동적할당한 메모리를 nullptr 인지 항상 확인하고 쓰기. 습관 2. 안전한 메모리 삭제를 하는 코드 항상 짜두기 


//포인터를 이중포인터로 인자 전달해서 함수에서 해제할수있나?
void DeleteMemory(int** _Ptr)
{
    delete *_Ptr;
    *_Ptr = nullptr;
    //이게 될까??
}