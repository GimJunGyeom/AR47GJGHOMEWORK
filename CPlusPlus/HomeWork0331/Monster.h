#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();
	void Update();
	void DownUpdate();

private:
	int Dir = 1;
};

