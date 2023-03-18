
#include <iostream>


//case 뒤에는 상수 메모리만 올수 있음. 변수 안됨 

//case 안에 변수 선언이라던가 뭔가 하려면 중괄호를 쳐줘야한다. switch는 실행흐름 만드는 방식이 독특해서 더 깊게 파지말고 지금은 그리 알것
/*ex) 

	안되는 코드
	case 1:
		int a = 0;

	되는 코드
	case 1:
	{
		int a = 0;
	}	

*/

int main()
{
	const int Value = 2;
	switch (1)
	{
	case 1:
		break;
	case Value:
		break;
	case 3:
		break;
	default:
		break;
	}
    
}

