

#include <iostream>


//enum 사용자 정의 자료형은 컴파일되면 int로 변환된다.
//enum class는 enum 처럼 암시적 형변환을 안시켜줌. 
//enum class는 enum 보다 명시적으로 표기 안하면 오류남.

//그냥 enum은 암시적 형변환을 해대서 막 bool 타입에도 들어가버리고 나중에 유지보수때 헷갈리기 쉬워서 enum보단 enum class가 낫다

int main()
{

	//원래쓰던 enum
	{
		enum GameJobType  //다 컴파일때 int 됨
		{
			Fighter, //0
			Mage,    //1
			Archer   //2
		};
		GameJobType MyEnum = GameJobType::Fighter;
		bool Value0 = MyEnum; //enum은 암시적 형변환 해버림
		
		GameJobType MyEnum = Fighter; //앞에 enum의 그룹 이름을 안적어줘도 사용이 됨(이게 또 나중에 enum 막 만들다 보면 단점이됨 - 여러 enum이 많아지면 어디것이 뭐가 뭔지 몰라서.)
	}

	//원래쓰는 enum의 단점(마음대로 암시적 형변환해버림)을 보완하기 위해 나온 enum class
	{
		enum class GameJobType
		{
			Fighter, //0
			Mage,    //1
			Archer   //2
		};
		GameJobType MyEnumClass = GameJobType::Mage;
		bool Value1 = MyEnumClass; //enum class는 enum과 달리 암시적 형변환 불가

		GameJobType MyEnumClass = Mage; //enum과 다르게 앞에 꼭 enum class 이름도 적어줘야함
	}

}
