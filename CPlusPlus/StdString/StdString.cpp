
#include <iostream>

//인코딩이란 - 어떤 숫자를 특정한 문자나 의미로 매칭하는것
	//1바이트 인코딩 == 아스키, ANSI
	//1~2 바이트 인코딩 == 멀티바이트 인코딩 
    //2바이트 인코딩 === 와이드 바이트 인코딩
    //한계 - 2바이트 인코딩 까지는 국가별로 매칭이 달라지는 인코딩방식이다. 그래서 다른 나라 운영체제에서 파일열면 글자가 깨짐.

    //그래서 3,4바이트 문자형들이출현. UTF 인코딩 등

//기본적으로 프로그램코드는 국가코드를 따른다.

int main()
{
	char Arr0[6] = "하 호"; //멀티바이트 2(하) + 1(공백) + 2(호) + 1(문자열끝표시 0)
	wchar_t Arr1[8] = L"하 호"; //와이드바이트 2 + 2 + 2 + 2    //공백, 문자열끝의 0 같은것도 무조건 2바이트씩 할당 예외란없음

	//std::string 은 vector 형 자료구조이다,

	{
		std::string Test0 = "안녕하세요"; //멀티바이트 인코딩

		std::wstring Test1 = L"안녕하세요"; //와이드바이트 인코딩
		std::wstring Test2 = L"반갑습니다";
		std::wstring Result = Test1 + Test2;

		setlocale(LC_ALL, "KOR");          //인코딩 국가지역설정 - 이거 안해두면 비주얼스튜디오는 기본적으로 영어권 국가로 인코딩 되어있음. 콘솔 환경아니면 별로 볼일이 없다.
		std::wcout << Result <<std::endl;  //와이드바이트 쓸때는 기존 문자열 관련 요소앞에 다 w 붙여줌 cout -> wcout, print_s -> wprint_s
	}

	{
		std::string Arr0 = "안녕하세요";
		std::string Arr1 = "반갑습니다";

		if (Arr0 == Arr1) //이거는 포인터를 비교를 하는것이지 안에있는 문자열을 비교하는게 아니다. 절대 같을리가 없어서 if문 내부로 들어오지 않는다.
		{
			int a = 0;
		}
		//암시적으로 컴파일러가 비교를 위해 reinterpret_cast<char*>Arr0 == reinterpret_cast<char*>Arr1 로 바꿈.
		//애초에 Arr0, Arr1의 자료형도 char[] 이지만 비교 하고싶은것도 그게 아님. 

		if (Arr0 == "안녕하세요") //이거는 string이 지원을 해준다. 포인터가 가리키는 문자열을 비교해줌. if 문 내부로 들어올것임.
		{
			int a = 0;
		}



	}
	
}

//std::string 내부 함수 
//.replace() 사용법알아오기 - "안녕" -> "오늘"로 바꾸기
//.find() 문자가 문자열 안에 몇번째 인덱스에있는지 날려줌
//.rfind() 
//.find_last_not_of
//.find_first_of
//append()