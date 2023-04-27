#include <iostream>


int main()
{
    int Value = 0;
    //2진수로 표현하는법 - 앞에0b 붙이고 뒤에 0이나 1 씀
    Value = 0b000000000000100101; 

    //8진수 표현법 - 앞에 0 하나만 붙이고 뒤에 0~7 사이 숫자를 씀. 
    int Value1 = 0;
    Value1 = 02457;
    //어떤 언어에는 0 대신 0o 두글자로 8진수를 표현하기도함.
    
    //16진수 표현법 - 앞에 0x 붙이고 뒤에 0~f 까지 (0~9,a b c d e f 까지) 숫자를 씀
    int Value2 = 0;
    Value2 = 0xc4f6;

    std::cout << Value << std::endl;
    std::cout << Value1 << std::endl;
    std::cout << Value2 << std::endl;

}
