#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <vector>

class ConsoleGameScreen;
class Body : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Body();
	~Body();

	// delete Function
	Body(const Body& _Other) = delete;
	Body(Body&& _Other) noexcept = delete;
	Body& operator=(const Body& _Other) = delete;
	Body& operator=(Body&& _Other) noexcept = delete;

	static int TailBodyCount;
	static void AttachBody(const int2& _Pos)         //기존에 붙어있던 꼬리들은 가만히 있고 새로 붙일 몸만 좌표 설정해주기
	{
		AttachedBody[TailBodyCount].SetPos(_Pos);
		TailBodyCount++;
	}

	static void AttachTail(int2 _Pos)                //기존에 있는 꼬리들 좌표 한칸씩 이동
	{
		for (int i = 0; i < TailBodyCount; i++)
		{
			if (i == TailBodyCount - 1)
			{
				AttachedBody[i].SetPos(_Pos);
				continue;
			}
			int2 TakeNextBody = AttachedBody[i + 1].GetPos();
			AttachedBody[i].SetPos(TakeNextBody);
		}
	}

	static bool IsHeadClashedBody(const int2& _Pos)  //머리랑 몸 부딪혔는지 체크
	{
		for (int i = 0; i < TailBodyCount; i++)
		{
			int2 BodyTailPos = AttachedBody[i].GetPos();
			if (BodyTailPos == _Pos)
			{
				return true;
			}
		}
		return false;
	}



	static void AllBodyUpdate();
	static void AllBodyRender();
	


protected:
	void update();

private:
	static std::vector<Body> AttachedBody;
	
};

