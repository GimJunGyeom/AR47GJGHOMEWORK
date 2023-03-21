
#include <iostream>

class Player
{
	//클래스 문법에서는 그 안의 속성과 행동을 외부에 공개할지 안할지를 결정할 수 있다.
	// 클래스의 시작과 끝 사이('내부영역')에 있지 않은 코드는 전부 '외부영역'
	//접근제한 지정자 - 접근제한 지정자는 만들어진 위치부터 아래까지 새로운 접근제한 지정자가 없으면 전부다 자신의 접근제한 지정자 영역으로 판단한다.
	//public, protected, private
	//디폴트 접근제한 지정자는 private이다. 


public: // 내부코드공개, 자식코드공개, 외부코드공개
	int Att;
	int Def;
protected: // 내부공개, 자식공개, 외부 비공개
	int Hp;
private: //내부공개, 자식 비공개, 외부 비공개
	int Speed;
};


int main()
{
	Player NewPlayer = Player();


}
