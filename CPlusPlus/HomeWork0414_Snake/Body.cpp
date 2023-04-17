#include "Body.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>

int Body::TailBodyCount = 0;
std::vector<Body> Body::AttachedBody(29);

Body::Body()
{
	RenderChar ='i';
	SetPos({ 0, 0 });

}

Body::~Body()
{
}


void Body::AllBodyUpdate()
{
	for (int i = 0; i < TailBodyCount; i++)
	{
		AttachedBody[i].Update();
	}
}

void Body::AllBodyRender()
{
	for (int i = 0; i < TailBodyCount; i++)
	{
		AttachedBody[i].Render();
	}
}

