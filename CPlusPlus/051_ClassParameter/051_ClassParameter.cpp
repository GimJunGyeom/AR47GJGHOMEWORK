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
    
}
