
#include <iostream>

class Player
{
public:
    int Hp;

    //맴버함수는 첫번째 인자로 무조건 자기자신의 클래스의 포인터가 들어가게 된다. 
    void Damage(/*Player* const _this,*/ int att)
    {
        //_this->Hp = att;
        Hp -= att;
    }

};


void GlobalPlayer(Player* _NewPlayer) //클래스 포인터는 맴버를 .이아닌 ->로 접근한다.
{
    _NewPlayer->Hp -= 10;
}


int main()
{
    
}

