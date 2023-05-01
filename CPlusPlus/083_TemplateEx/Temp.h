#pragma once

class Temp
{
public:
	//constructor destructor
	Temp();
	~Temp();

	//default function
	Temp(const Temp& _Other) = delete;
	Temp(Temp&& _Other) noexcept = delete;
	Temp& operator=(const Temp& _Other) = delete;
	Temp& operator=(Temp&& _Other) noexcept = delete;

protected:

private:

};