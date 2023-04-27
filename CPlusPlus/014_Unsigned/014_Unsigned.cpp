#include <iostream>


int main()
{
    {
        signed int Value = 1;
    }

    {
        //unsinged는 음수부호가 없는 수의 범위 이므로 0부터 시작한다.

        unsigned int Value = ~0;
        std::cout << Value << std::endl;

        unsigned int Value1 = 0;
        std::cout << Value1 << std::endl;
    }

    {
        //음수 초기화는 해당 unsigned 자료형의 최대수부터 언더플로우됨
        unsigned int Value0 = -1;
        std::cout << Value0 << std::endl;

        unsigned int Value1 = -2;
        std::cout << Value1 << std::endl;

        unsigned int Value2 = -3;
        std::cout << Value2 << std::endl;
    }
}
