

#include <iostream>

class MyCout
{
public:
	void operator<<(const char* _Value)
	{
		printf_s("%s", _Value);
	}

};

//cout은 전역객체였다는 사실
namespace std
{
	MyCout MCout;

};
int main()
{

}
