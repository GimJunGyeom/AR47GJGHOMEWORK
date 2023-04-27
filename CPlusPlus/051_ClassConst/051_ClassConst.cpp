#include <iostream>

//맴버함수 뒤에는 const를 붙일 수 있다.

class Player
{
public:
    void function() const 
        //이 클래스를 통해서 만들어진 객체는 변하지 않는 다는 뜻
        //맴버함수에 첫전째 인자로 암시적으로 전달하는 ' Player* const this' 를 'const Player* const this'로 한다는 문법이다.
        //this가 가진 주소값을 변경 못함(디폴트) <-> this가 가진 주소값도 변경못하고, this가 가리키는 곳의 데이터도 변경못함(멤버함수 뒤에 const)
        //이 맴버함수는 객체의 어떤것도 바꾸지 않을 거라는 의도를 표현하는 것
    {      
    }

    static void Function2()
    {
        //const 못붙임 => const 붙여줄 this 없이 접근하는 함수이기 때문

    }
};


int main()
{
    
}
