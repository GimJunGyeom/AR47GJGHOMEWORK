
#include <iostream>

//class 선언부는 코드영역에 있음
//클래스 이름이 같으면 코드영역의 같은 공간에 같은 이름(메모리공간)을 쓰겠다는 것이므로 오류남 
/*
class Player
{
    int Att = 10;

};

class Player
{

};
*/

//같은 이름을 써서 나는 에러를 막기위해 namespace를 씀. 즉 이름있는 껍데기 하나 더 씌우는것
//namespace A_programmer
//{
//    class player
//    {
//        int att = 10;
//
//    };
//} 
//
//namespace B_programmer
//{
//    class player
//    {
//        int att = 10;
//
//    };
//}

//using namespace Aprogrammer 절대 사용불가. 뜻 : namespace를 생략가능하면 생략해라

class Player
{
public:
    int Hp;
};
//같은 namespace 영역을 열었다 닫았다(코드 몰아서 한 영역안에 다 적일 필요없음)할 수도 있고 
//namespace 안에 또 namespace를 열고 닫을수 있음

//std:: 는 C++스탠다드, 즉 c++만든 사람들이 제공하는 표준코드

int main()
{
    Player Test = Player();

    //99퍼센트가 풀네임으로 안쓴다.
    Test.Hp;
}
