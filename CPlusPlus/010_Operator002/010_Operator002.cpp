#include <iostream>

int main() 
{
	int Left = 0b00000000000000000000000000000010;
	int Right = 0b00000000000000000000000000000001;
	int result = 0b00000000000000000000000000000000;

	//비트단위 연산자
	
	// and or 비트 연산자
	// & |

	// not 연산자
	result = ~0; 
	// xor 연산자 - 비트가 같으면 false 다르면 true
	result = Left ^ Right;

	/* true 와 false (참과 거짓)의 명확한 의미
	* 특정 메모리 영역의 비트가 전부 0이라면 false. 단 하나의 비트라도 1이 있으면 true. 즉 값이 있으면 참 없으면 거짓 
	*/
	bool bResult = 2;
	bResult = 0 && 10021312;  // '거짓 and 참'

	{
		int Value0 = 0b00110010; //32 + 16 + 2 = 50
		int Result0 = Value0 << 3; // 110010'000 = 16 + 128 + 256 = 400
		int Result1 = Value0 >> 3; // 110 = 2 + 4 = 6

		std::cout << Result0 << std::endl;
		std::cout << Result1 << std::endl;
	}

	{
		int Value0 = 0b00110010; 

		//: shift count negative or too big, undefined behavior - 비트이동 연산이 너무 크거나 음수인 경우는 정의되지 않는 행동이다 == 의미 없는 연산이다.
		int Result2 = Value0 << -3;
		int Result3 = Value0 >> -3; 
		int Result4 = Value0 << 32;

		std::cout << Result2 << std::endl;
		std::cout << Result3 << std::endl;
		std::cout << Result4 << std::endl;
	}
}
