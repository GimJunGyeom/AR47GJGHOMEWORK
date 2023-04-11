

#include <iostream>


//enum 사용자 정의 자료형은 컴파일되면 int로 변환된다.
//enum class는 enum 처럼 암시적 형변환을 안시켜줌. 
//enum class는 enum 보다 명시적으로 표기 안하면 오류남.

//그냥 enum은 암시적 형변환을 해대서 막 bool 타입에도 들어가버리고 나중에 유지보수때 헷갈리기 쉬워서 enum보단 enum class가 낫다

int main()
{
	{
		enum GameJobType  //다 컴파일때 int 됨
		{
			Fighter, //0
			Mage,    //1
			Archer   //2
		};

		GameJobType MyEnum = Fighter;
		bool Value0 = MyEnum; //enum은 암시적 형변환 해버림
		
	}

	{
		enum class GameJobType
		{
			Fighter, //0
			Mage,    //1
			Archer   //2
		};
		GameJobType MyEnumClass = GameJobType::Mage;
		bool Value1 = MyEnumClass; //암시적 형변환 불가
	}

}
