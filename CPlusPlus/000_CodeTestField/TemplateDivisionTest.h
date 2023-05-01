#pragma once
#include <iostream>

class TemplateDivisionTest
{
public:
	//constructor destructor
	TemplateDivisionTest();
	~TemplateDivisionTest();

	//default function
	TemplateDivisionTest(const TemplateDivisionTest& _Other) = delete;
	TemplateDivisionTest(TemplateDivisionTest&& _Other) noexcept = delete;
	TemplateDivisionTest& operator=(const TemplateDivisionTest& _Other) = delete;
	TemplateDivisionTest& operator=(TemplateDivisionTest&& _Other) noexcept = delete;

	//선언과 구현 동시
	/*template<typename DataType>
	void Function(DataType _Value)
	{
		std::out << _Value << std::endl;
	}*/

	template<typename DataType>
	void Function(DataType _Value);

protected:

private:

};