
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

	{
		//스위치문은 case: 밑에 변수를 선언하면 오류가 난다. (최신버전에선 안그럴 수도 있음 버전을 확인해야함)
		// 따라서 스위치문 이전에 변수를 선언하거나, case: 마다 중괄호로 묶어줘야 오류가 생기지 않는다.

		switch (1)
		{
		case 1:
			//int Value0 = 1;  //오류남
			break;
		case Value:
			break;
		case 3:
			break;
		default:
			break;
		}

	}

	{
		switch (1)
		{
		case 1:
		{
			int Value0 = 1;  //중괄호로 묶음
			break;
		}
		case Value:
			break;
		case 3:
			break;
		default:
			break;
		}

	}
    
}

