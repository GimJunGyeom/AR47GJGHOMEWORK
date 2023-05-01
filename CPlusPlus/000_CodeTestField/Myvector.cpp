#include <vector>
#include <iostream>
//#include "TemplateDivisionTest.h"
#include "TemplateDivisionTest.cpp"
namespace Test0
{
	class namespaceClass
	{
	public:
		void namespaceClassFunction()
		{
			printf_s("namespaceClass 함수\n");
		}
		int GetValue0()
		{
			return Value0;
		}
		int GetValue1()
		{
			return Value1;
		}
	private:
		int Value0 = 1;
		int Value1 = 2;
	};
};


class OutClass
{
public:
	void OutClassFunction()
	{
		printf_s("Value0 : %d, Value1: %d\n", namespaceClassInOutClass.GetValue0(), namespaceClassInOutClass.GetValue1());
	}
//private:
	static Test0::namespaceClass namespaceClassInOutClass;
};


Test0::namespaceClass OutClass::namespaceClassInOutClass;

int main()
{

	//inclass outclass 이름장난 테스트
	{
		OutClass MyOutClass = OutClass();

		MyOutClass.OutClassFunction();

		//OutClass::namespaceClassInOutClass
	}


	{
		TemplateDivisionTest MyTemplateClass{};

		MyTemplateClass.Function(3);
	}
}
