// HomeWork0407.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineConsole/ConsoleGameScreen.h>


int main()
{
    while (true)
    {
        ConsoleGameScreen::GetMainScreen().ScreenClear();
        ConsoleGameScreen::GetMainScreen().ScreenPrint();
    }
}


//폭탄 터트리기
