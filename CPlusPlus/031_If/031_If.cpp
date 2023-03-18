

#include <iostream>

int ReturnValue()
{
    return 10;
}

//자동완성기능
//if 또는 swi 치고 tab
//컨트롤 + 스페이스

int main()
{
    //센세가 선호하는 if문 방식1
    int Value = ReturnValue();
    if (Value)
    {
        printf_s("실행됩니다.");
    }

    //센세가 선호하 방식2
    if (int Value = ReturnValue())
    {
        printf_s("실행됩니다.");
    }


    //센세가 선호하는 방식3
    if (0 != ReturnValue())
    {
        printf_s("실행됩니다.");
    }

    //센세는 이런방식은 조건문 값을 디버깅으로 확인할 수 없어서 싫어함
    if(ReturnValue())
    {
        printf_s("실행됩니다.");
    }

    //센세는 한줄치기를 극혐한다. 실수할 가능성이 높기때문
    if (ReturnValue())
        printf_s("실행됩니다.");


    //else if는 아무리 많아도 조건문이 참이되는 윗줄에 가까운 단 하나만 실행
    //else는 모든 if문이 실패하면 무조건실행

    
    //if 내부는 ,(따옴표) 몇개를 써도 맨 오른쪽을 조건문으로 보고 실행
    if (printf_s("10"), printf_s("20"), 0)
    {
        printf_s("실행됩니다.");
    }

    

}

