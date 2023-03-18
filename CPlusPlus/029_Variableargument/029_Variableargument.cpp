// 함수는 함수의 인자들를 8바이트 배열로 전달한다. ex)4바이트 int 형과 1바이트 char형을 인자로 넘겨도 함수에선 그 인자들을 8바이트 메모리 공간을 할당함. 
// (실제 자료형은 총 5바이트지만 함수에서의 메모리할당은 총 16바이트)

//디버그(D) -> 창(W) -> 호출스택으로 함수가 어디서 호출됬는지 볼수있는 창이 있음.


// 인자는 이름을 넣어주지 않아도 인자로 사용할 수 있다. 인자의 이름을 넣어준다는 것은 인자로 뭔가 더 다양한 일을 한다는 뜻이다.

#include <iostream>

void TestFunction(int , int, int)
{
}

void TestFunction2(int num, int, int, int, int, int)
{
    {
        int i = num;
        int j = 1;
        int* Ptr = &num;
        int inputnumber = 0;


        while (j <= i)
        {
            inputnumber = Ptr[j * 2];
            j++;
        }
    } //나의 방법

    { //센세의 방법
        int* Ptr = &num;
        while (num--)
        {
            Ptr += 2;
            int Value = *Ptr;

            int a = 0;
        }

    }
}

int main()
{
    //TestFunction2(5, 67, 246, 76, 8978, 8709);


    // %d숫자 %s문자열
    TestFunction(10, 20, 30);
    printf_s("%d %d %d ", 1);


    return 0;
}

