// 069_Assert.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <assert.h>    //assert 함수 쓰려고
#include <Windows.h>  //MessageBox 함수 쓰려고


//함수로 구현한 오류발생기
//void MsgBoxAssert(const char* _Text, const char* _Title)
//{
//	MessageBoxA(nullptr, _Text, _Title, MB_OK);  
//	assert(false);
//}

//함수로 만들어서 쓰면 귀찮으니까 define 전처리기 지시문으로 만들어보자.
#define MsgBoxAssert(_Text) MessageBoxA(nullptr, _Text, "제목", MB_OK);  assert(false);



int main()
{
	//프로그래머가 일부러 프로세스를 터트리기 (원하지 않는 상황에 프로세스가 진행되었을때 그 코드 부분에 삽입한다.)
	{
		MessageBoxA(nullptr, "내용 - aaaa", "제목 - 오류입니다.", /*확인버튼 만들어주는 인자*/MB_OK);  //확인누르기 전까지 실행을 멈춰주는 박스를 만들어 준다.
		assert(false);                                                                                 //실제로 프로세스 터트리기
	}

	////define 전처리기 지시문을 이용해서 오류코드 만들기
	//{
	//	MsgBoxAssert("오류입니다");
	//}
	//그럼 왜 굳이 define 전처리기 지시문으로 매크로 함수를 만들어서 오류생성코드를 구현하는가?  -> 함수로 오류발생 코드를 구현하면 디버깅모드에서 호출스택을 뒤로 넘기면서 검사하면서 오류난 줄을 확인해야 하는데 그게 너무 귀찮다.
	//이 스토리를 기억해야함. 함수가 아니라 define을 이용해 오류발생코드를 구현하면 디버그 호출스택 뒤적거리며 오류난 줄 찾는 수고를 안해도 되니까 이렇게 구현한것.
}