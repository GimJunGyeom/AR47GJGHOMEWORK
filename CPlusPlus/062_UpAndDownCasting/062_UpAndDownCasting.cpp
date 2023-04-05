// 062_UpAndDown.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class FightUnit
{
public:
	int GetAtt()
	{
		return Att;
	}
private:
	int Att = 10;
};


class Player : public FightUnit
{
public:
	int GetAtt() override
	{
		return FightUnit::GetAtt() + Lv;
	}
private:
	int Lv = 1;
	int Att = 10;
};
class Monster
{

};

//Up Casting 울 이용한 함수
void Fight(FightUnit* _Left, FightUnit* _Right)
{

}

void main()
{
	Player NewPlayer;
	Monster NewMonster;

	Player* PlayerPtr = &NewPlayer;

	//업 캐스팅. NewPlayer 객체에서 상속받은 부분은 그대로 남아있고 Player 클래스 부분은 사라짐.
	FightUnit* Ptr = PlayerPtr;
	//즉 자식 클래스에서 부모 클래스로 형변환 되는것이 업 캐스팅.

	//다운캐스팅은 업캐스팅의반대. 즉 부모형을 자식형으로 바꿈. 강제캐스팅이고 내가 직접 형변환 해줘야함. Why? 다운캐스팅할 자식클래스들 중에 뭘로 바꿔줘야할지 컴퓨터가 알 방법이 없기때문에 프로그래머가 명시적으로 지정해줘야함.
	//반면 업캐스팅은 그냥 부모 하나있으니까 자동으로 암시적으로 형변환 해줄수 있는거임.
	//다운캐스팅 방법은 최악의 방법으로 어떤 오류가 발생할지 알수가 없다. 코드가 돌아가긴 하는데 예측이 불가하기 때문이다.
	//다운캐스팅은 안전하게 하는 방법이 반드시 존재하고 그 이외의 방식으로 그냥하면 절대 안됨. 그렇지 않으면 다운캐스팅해서 접근한 알수없는 메모리 영역에 접근할때 반드시 문제가 생긴다. 
	//다운캐스팅이 안좋은 이유는 부모클래스가 알아서는 안될 자식클래스를 참조하려고 하기 때문이다.


	//그렇다면 다운캐스팅 하지 않고 이름이 같은 함수를 어떻게 그때그떄 다른 자식클래스에 따라서 다르게 동작하게 만들 수 있을까? 그냥 일일히 그때마다 코드를 치는 방법밖엔 없을까?
	//virtual 가상함수 문법 - 자식클래스가 부모함수를 새롭게 정의하지 않으면 부모형으로 동작하고 자식클래스가 부모함수를 새롭게 정의하면 부모클래스랑 상관없이 새롭게 정의한대로 함수가 동작하게 해준다.
	//오버라이드 문법
	//명시적으로 override 했다는 것을 표현해주는 것이 좋다. 안써도 자동으로 오버라이드  시켜주긴하는데 명시적으로 표현 안하는걸 선생님은 싫어한다.
	//선언과 구현을 분리했을때는 구현부에 override 생략해야한다.




}
