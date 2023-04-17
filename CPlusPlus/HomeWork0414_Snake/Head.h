#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include <conio.h>
#include "SnakeEnum.h"
#include "Parts.h"
#include "Body.h"


// Ό³Έν :
class Head  : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Head();
	~Head();

	// delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

	static bool IsPlay;
	static int EndGameReason;

	bool IsPartsCheck();
	void SetForePos(int2 _Pos);

protected:
	void Update();
	
private:
	int2 Dir = int2::Up;
	int2 ForePos = Pos;
	
};

