
#include <iostream>

//c와 c++의 struct는 완전히 문법이 다르다

struct Monster
{
    //struct와 class는 (접근제한 지정자의 디폴트 값을 제외하고) 문법적으로 완전히 동일하다.
    //struct의 디폴트 접근제한 지정자는 public. (클래스는 private임)
    int Att = 10;
    int Def = 2;

    void myPrint()
    {
        printf_s("스트럭트의 함수구동\n");
    }

};

int main()
{
    Monster NewMonster = Monster();

    NewMonster.myPrint();
}

