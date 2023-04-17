#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include "Body.h"
#include "Head.h"


class Parts : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Parts();
	~Parts();

	// delete Function
	Parts(const Parts& _Other) = delete;
	Parts(Parts&& _Other) noexcept = delete;
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

	static void SetMeetToHeadTrue();
	static void SetMeetToHeadfalse();
	static bool GetMeetTohead();
	

protected:
	void Update() override;
private:
	int2 Pos;
	static bool MeetToHead;
	
};

