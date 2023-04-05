#pragma once

class ADefaultClass
{
public:
	//constructor destructor
	ADefaultClass();
	~ADefaultClass();

	//default function
	ADefaultClass(const ADefaultClass& _Other) = delete;
	ADefaultClass(ADefaultClass&& _Other) noexcept = delete;
	ADefaultClass& operator=(const ADefaultClass& _Other) = delete;
	ADefaultClass& operator=(ADefaultClass&& _Other) noexcept = delete;

protected:

private:

};