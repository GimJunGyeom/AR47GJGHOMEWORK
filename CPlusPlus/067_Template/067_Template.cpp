
#include <iostream>

// template문법 - 자료형을 변수처럼 사용하고 싶을때
// 왜사용하나? 코드는 그대로인데 자료형만 바꿔주어야 할 경우, 똑같은 코드를 자료형만 바꾸고 다시 중복으로 치는게 싫으니까
// 특정함수나 특정클래스에서 자료형만 바뀐 완전히 동일한 코드로 이루어진 클래스나 함수를 만들고 싶은때 사용합니다. 

//예시 - 인자 다른 오버로딩함수는 똑같은 함수임에도 자료형이 다르다는 이유만으로 다시 쳐야한다.
void SameCode(int _a)
{
    
}

void SameCode(char _a)
{

}

//원래 프로그래머가 오버로딩으로 코드를 직접 쳐줘야하는 것을 이렇게 template으로 적어놓으면 컴파일 할때 필요한 오버로딩 함수를 컴파일러가 대신 쳐줍니다.
//template을 남용하면 컴파일 시간이 길어집니다만 크게 신경쓸 필요는 없음.
template<typename Datatype>
void Function(Datatype _Value)
{
    printf_s("%d\n", _Value);
}

//템플릿 문법중의 하나로, 딱 특정 자료형일때만 다르게 동작하는 함수를 만들고 싶을떄가 있으면 '템플릿 특수화' 문법을 사용해서 구현하면됩니다.
//예시 - char 함수일때는 문자로 출력하고 싶어
template<>                        //요거는 이게 템플릿 함수라는걸 표시해주는거에요 명시적으로. 안써도 돌아가긴합니다.
void Function(char _Value)
{
    printf_s("%c\n", _Value);
}




int main()
{
    {
        Function<bool>(true);
        Function<int>(100);
        Function<char>('1');
        //컴파일러는 요기 세줄을 보고 오버로딩 함수를 자료형만 다른걸로 세 개 대신 쳐줍니다. 

        /*void Function(bool _Value)
        {
            printf_s("%d\n", _Value);
        }
        void Function(int_Value)
        {
            printf_s("%d\n", _Value);
        }
        void Function(char _Value)
        {
            printf_s("%d\n", _Value);
        }*/


        //컴파일러가 자료형을 알아서 암시적으로 자료형 찾는 '인자추론'을 해주기 때문에 <자료형> 생략가능
        Function(true); // == Function(true);
        Function(100); // == Function<int>(100);
        Function('1'); // == Function<char>('1');

        //템플릿 특수화로 다르게 동작하게 만들긴 했는데 그냥 이때는 원래대로 동작하게 하고 싶으면 앞에 자료형을 명시해주면 그대로 그거 따라서 함수가 실행됩니다.
        Function<int>('1'); 
    }

    {
        //클래스는 템플릿으로 왜 인자추론이 안될까? - 클래스는 크기를 알아야 스택에 메모리를 할당할텐데 인자추론은 컴파일타임때 크기를 알수가 없으니 인자추론이 불가능하다

    }
    
}

