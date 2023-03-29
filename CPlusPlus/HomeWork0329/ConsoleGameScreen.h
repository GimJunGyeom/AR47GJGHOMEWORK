#pragma once
#include "ConsoleGameMath.h"
 
class ConsoleGameScreen
{
public:

	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	static int2 GetScreenSize();

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);
	void SetScreenCharacter(bool _Fire);                   //함수 오버로딩 (총알용)
	

protected:

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;
};