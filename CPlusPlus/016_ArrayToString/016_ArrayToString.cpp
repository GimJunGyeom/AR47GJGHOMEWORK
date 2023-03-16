

int main()
{
	{
		//자동으로 0으로 초기화.
		int ArrValue[5] = {};
		int ArrValue2[5] = { 0, };
	}

	{	
		//0을 false로 쓰는건 안좋은 습관.
		bool ArrValue[5] = {};
		bool ArrValue2[5] = {true, };
		bool ArrValue3[5] = {false, };
	}

	{
		char ArrValue[5] = { 'a', 'b', 'c' };
		//문법적으로 문자의 배열은 축약형표현인 쌍따옴표를 사용할 수 있다.
		char ArrValue2[5] = "abc";
	}
}
