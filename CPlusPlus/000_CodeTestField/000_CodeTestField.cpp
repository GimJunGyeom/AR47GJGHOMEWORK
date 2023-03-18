

#include <iostream>

//문자열을 넣어주면글자개수를 알아냅니다.
// 0을 포함할지 아닐지는 스스로 정하세요
// 영어만씁니다.

int StringCount(const char* _String)
{
}


int TrimDelete(char* _String)
{

}


//영어나 다른 글자가 섞여 들어가는걸 가정하지 않는다. 오로지 숫자만. 숫자문자열을 넣으면 그걸 그냥 숫자로 출력한다.
int StringToInt(const char* _String)
{

}



int main()
{
    int Return = StringCount("aaa efg rgggg"); //공백 제외한 글자 수 출력

    char Arr[1024] = "a b c d e"; //공백없이 출력
    TrimDelete(Arr);
    printf_s(Arr);
    

    int Rvalue0 = StringToInt("1111");
    
}

