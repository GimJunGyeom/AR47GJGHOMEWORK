#include <iostream>

class Player
{

};


void StatusRenderPtr(const Player* _Player)
{
    //방어코드
    if (nullptr == _Player)
    {
        return;
    }

}

//보통 레퍼런스(또는 포인터)로 인자를 넘기는 이유 - 인자 크기가 8바이트보다 큰 경우 메모리낭비 + 새로운 메모리 할당하고 등등 실행속도 손해
//인자가 없어지는 경우가 절대 없는 경우 레퍼런스로, 아니면 포인터로 인자를 넘김.
//전역 변수는 없어지는 경우가 프로그램 종료일떄 이므로 인자로 레퍼런스 사용가능. 즉 포인터 인자는 항상 null 체크 해야함
void StatusRenderPtr(const Player& _Player)
{
   

}


int main()
{
    int Value0 = 2;
    int* Ptr0 = &Value0;
    int* (&Ref0) = Ptr0;  //Ref0은 Ptr0의 주소값을 가진다.
    int& Ref1 = *Ptr0;    //Ref1은 Value0의 주소값을 가진다. (*Ptr0 == Value0 이므로)

    std::cout << Value0 << std::endl;
    std::cout << Ptr0 << std::endl;    //Ptr0에 들어있는 Value0의 주소값이 출력됨.
    std::cout << Ref0 << std::endl;    //Ref0에는 Ptr0의 주소값이 들어있고, 레퍼런스 특징에 따라 자동적으로 Ptr0의 내용(Value의 주소값)이 출력됨.
    std::cout << Ref1 << std::endl;    //Ref1에는 Ptr0이 가리키는 값, 즉 Value0의 주소값이 있고 레퍼런스 특징에 따라 Value값이 출력됨.
    
}
