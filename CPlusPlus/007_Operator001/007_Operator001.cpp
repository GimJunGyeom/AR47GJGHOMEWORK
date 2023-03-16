// shift + home + 위아래방향키 >>줄 한칸 기준 커서이동
// shift + alt + 위아래왼쪽오른쪽방향키 >>한칸 기준 커서이동


int main()
{
    int Left = 7;
    int Right = 3;
    int Result = 0;
    /*단항연산자 : 연산에 필요한 메모리 영역이 1개
    이항 연산자 : 2개
    삼항 연산자 : 3개
    */

    //이항연산자
    Result = Left + Right;
    Result = Left - Right;
    Result = Left * Right;
    Result = Left / Right;  //정수에서는 결과가 몫만 나오는 나누기 
    Result = Left % Right;  //정수에서는 결과가 나머지만 나오는 나누기

    //단항연산자
    Result = -Left;
    Result = +Left;
    Result = ++Left;
    Result = Left++;
    Result = --Left;
    Result = Left--;

    //괄호 연산자 - 연산을 먼저 하게 해주는 연산자
    Result = (1 + 2) * 3;

    // bool이라는 자료형은 논리형이라고 부른다.
    // 논리형은 true와 false 2가지만 표현하는 자료형.
    bool bResult = true;

    //비교연산자 관계연산자
    bResult = Left == Right;
    bResult = Left != Right;
    bResult = Left < Right;
    bResult = Left > Right;
    bResult = Left >= Right;
    bResult = Left <= Right;

    //논리 연산자
    bResult = true && false;
    bResult = true || false ;

}

