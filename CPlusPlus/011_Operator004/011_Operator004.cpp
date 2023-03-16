

int main()
{
    //삼항연산자 a ? b : c
    //a가 참이면 b, a가 거짓이면 c를 결과로 반환한다.

    int Left = 7;
    int Right = 3;
    int Result = 0;

    Result = (Left != Right) ? 100 : 200;
    Result = true ? 100 : 200;
    Result = false ? 100 : 200;

    //sizeof 연산자
    // sizeof(메모리영역). 괄호안에 들어갈건 기본자료형은 물론 다른데도 사용가능. Byte 단위로 알려줌
    Result = sizeof(Left); //4
    Result = sizeof(int);  //4
    Result = sizeof(bool); //1
}

