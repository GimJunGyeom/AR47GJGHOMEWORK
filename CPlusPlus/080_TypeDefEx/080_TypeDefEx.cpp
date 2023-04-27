
#include <iostream>


//typedef으로 포인터 재정의 하는법
typedef int LW, * LWP; //int와 int* 를 동시에 정의
typedef int* KK;       //int* 만 정의

//C타입 구조체 선언법
struct __tagPlayer
{
    int Hp;
    int Att;
};
typedef __tagPlayer Player;  //c는 앞에 struct 키워드 생략하고 구조체를 선언하지 못해서 귀찮기 때문에 이런식으로 한번 구조체 정의하고 typedef으로 한번더 재정의해줌. 
                             //c++은 struct 키워드 생략하고 구조체 선언이 가능하지만 그래도  c와의 호환성을 위해서 이렇게 자료형 재정의 해놓은 코드들이 많다.
                             //__tagPlayer MyPlayer -> c는 불가능, c++은 가능한 선언

//선언과 동시에 재정의 하는 기법
typedef struct __tagPlayer0
{

} Player0;

int main()
{
    {
        LW TestInt0 = 0;
        KK TestPtr0 = nullptr;
        LWP TestPtr1 = nullptr;
    }

    {
        struct __tagPlayer MyPlyaer0; // C 방식 구조체 선언.
        __tagPlayer MyPlayer1; // c에선 안되지만 c++은 struct 키워드를 생략하고 구조체를 선언할수 있다.
    }

    //사용자정의 자료형은 기본키워드가 아니기 때문에 처음엔 사용자정의 자료형으로 변수이름을 지을 수 있으나, 그 이후에는 대신 더이상 사용자정의 자료형으로 쓰질못한다.
    {
        Player Player0;   //변수이름이 또다른 사용자 정의 자료형임.
        Player0 Player;   //컴파일러 입장에선 이미 Player0이라는 이름은 변수이름이 되버려서 더이상 자료형으로 못쓴다 
    }
    {
        Player0 Player;   
        Player Player0;
    }
}

