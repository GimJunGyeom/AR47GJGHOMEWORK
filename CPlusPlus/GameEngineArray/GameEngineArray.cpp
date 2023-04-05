
#include <iostream>

int main()
{
    {
        int Arr0[3] = { 1,2,3 };
        int Arr1[3] = { 0, };

        //Arr1 = Arr0  안된다.
        //컴파일러에서 제공하는 int[] 인트배열 자료형에는 operator= 함수를 구현해주지 않는것.
    }
}

