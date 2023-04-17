#include <vector>
#include <iostream>
namespace Test0
{
	class namespaceClass
	{
	public:
		void namespaceClassFunction()
		{
			printf_s("namespaceClass ÇÔ¼ö\n");
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
	OutClass MyOutClass = OutClass();

	MyOutClass.OutClassFunction();

	//OutClass::namespaceClassInOutClass
}
