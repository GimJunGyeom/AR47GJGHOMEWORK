#include <iostream>


//문자열의 글자개수 출력
int StringCount(const char* _String)
{
    const char* Ptr = _String;
    int Count = 0;
    int index = 0;

    while (Ptr[index] != 0)
    {
        if (Ptr[index] != ' ')
        {
            Count++;
        }
        
        index++;
    }

    return Count;
}

//문자열 공백 없애기
char* TrimDelete(const char* _String)
{
    const char* Ptr = _String;
    int index = 0;
    char Arr[1024] = { };
    int Newindex = 0;

    while (Ptr[index] != 0)
    {
        if (Ptr[index] != ' ')
        {
            Arr[Newindex] = Ptr[index];
            Newindex++;
        }

        index++;
    }


    return Arr;
}

//문자열로된 숫자를 실제 숫자데이터로 바꾸기
int StringToInt(const char* _String)
{
    int result = 0;
    int LC =  0;      
    const char* Ptr = _String;
    int index = 0;
    int pow = 1;
    int Powindex = 0;


    //문자열의 숫자 갯수 구하기 
    while (true)
    {
        if (Ptr[index] != 0)
        {
            LC++;
            index++;
        }
        else
        {
            break;
        }
    }


    //문자열을 숫자로 바꾸기
    index = 0;
    while (LC != 0)
    {
        //비교하려는 수가 1의자리 이상이면 자릿수(LC)만큼 10의 거듭제곱(pow) 구하rl
        pow = 1;
        if( LC > 1)
        {
            Powindex = 1;
            while (Powindex != LC)
            {
                pow *= 10;
                Powindex++;
            }
        }

     
        //배열의 문자를 비교해서 매치되는 실제 수로 바꿔주기
        switch (Ptr[index])
        {
        case '1':
            result += 1 * pow;
            break;
        case '2':
            result += 2 * pow;
            break;
        case '3':
            result += 3 * pow;
            break;
        case '4':
            result += 4 * pow;
            break;
        case '5':
            result += 5 * pow;
            break;
        case '6':
            result += 6 * pow;
            break;
        case '7':
            result += 7 * pow;
            break;
        case '8':
            result += 8 * pow;
            break;
        case '9':
            result += 9 * pow;
            break;
        default:
            break;
        }


        index++;
        LC--;
    }



    return result;
}


int main()
{
    // StringCount
    int A_Value1 = StringCount("rtyuu ");                  
    printf_s("%d\n", A_Value1);
    int A_Value2 = StringCount("rr rrr ggggg www");       
    printf_s("%d\n", A_Value2);
    int A_Value3 = StringCount("abcd efg hijk lmnop         qrs tuv wx y   z"); 
    printf_s("%d\n", A_Value3);




    
    // TrimDelete
    char* B_Arr1 = TrimDelete("abcd efg hijk lmnop         qrs tuv wx y   z");
    int B_index1 = 0;
    while (B_Arr1[B_index1] != 0)
    {
        putchar(B_Arr1[B_index1]);
        B_index1++;
    }
    printf_s("\n");

    char* B_Arr2 = TrimDelete("t tt t           E E E E FFF Fgg   g gGGG G    ");
    int B_index2 = 0;
    while (B_Arr2[B_index2] != 0)
    {
        putchar(B_Arr2[B_index2]);
        B_index2++;
    }
    printf_s("\n");
    
    char* B_Arr3 = TrimDelete("I have an apple and a piece of pizza");
    int B_index3 = 0;
    while (B_Arr3[B_index3] != 0)
    {
        putchar(B_Arr3[B_index3]);
        B_index3++;
    }
    printf_s("\n");



  

    // StringToInt
    int C_Value1 = StringToInt("123454321");
    printf("%d\n", C_Value1);
    int C_Value2 = StringToInt("40069000");
    printf("%d\n", C_Value2);
    int C_Value3 = StringToInt("110101101");
    printf("%d\n", C_Value3);

}
