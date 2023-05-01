
#include <iostream>

//원래 함수에 인자를 사용하기로 정의 되어있으면 함수 사용시 각 인자에 값을 무조건 넣어줘야한다. 그런데 인자의 값을 굳이 넣어주지 않아도 함수가 동작되게 하려면? -> 디폴트 인자 설정
//디폴트 인자 - 인자의 기본값을 미리 설정해줘서 함수 사용시에 인자를 넣어도, 안넣어도 함수가 동작하게 해주는 문법.
//당연히 함수 인자의 값을 넣어주지 않으면 디폴트 인자의 기본값으로 함수가 동작.
void DefaultFunction(int _Value0 = 10)
{
    std::cout << _Value0 << std::endl;
}

//디폴트 인자는 함수인자들의 무조건 오른쪽부터 넣어줄수 있음.
//함수오버로딩 할때 디폴트 인자를 조심해서 써야한다. 

//디폴트 인자와 함수 오버로딩 함께 쓸때 조심해야되는 사례
void Function(int _Value0 = 50)
{
    std::cout << "첫째 함수" << std::endl;
}

void Function(int _Value1, int _Value0 = 50)
{
    std::cout << "둘째 함수" << std::endl;
}

int main()
{
    {
        DefaultFunction();
        DefaultFunction(39);
    }
    

    {
        Function(10); // 첫번째 함수의 _Value0을 10으로 하라는건지, 두번째 함수의 _Value1을 10으로 하란건지 알 수가 없음
        Function(10, 20); // 인자를 두개 쓰는 Function은 둘째 함수로 특정될수 있으므로 오류없음
    }
}

