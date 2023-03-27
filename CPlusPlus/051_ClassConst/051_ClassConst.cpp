#include <iostream>

//맴버함수 뒤에는 const를 붙일 수 있다.

class Player
{
public:
    void function() const 
        //이 클랫를 통해서 만들어진 객체는 변하지 않는 다는 뜻
        //맴버함수에 첫전째 인자로 암시적으로 전달하는 const Player* this 를 const Player* const this로 한다는 문법이다.
        //이 맴버함수는 객체의 어떤것도 바꾸지 않을 거라는 의도를 표현하는 것
    {      
    }
};


int main()
{
    
}
