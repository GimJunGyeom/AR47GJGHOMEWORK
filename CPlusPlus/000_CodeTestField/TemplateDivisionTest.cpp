#include "TemplateDivisionTest.h"

TemplateDivisionTest::TemplateDivisionTest()
{
}

TemplateDivisionTest::~TemplateDivisionTest()
{
}


template<typename DataType>
void TemplateDivisionTest::Function(DataType _Value)
{
	std::cout << _Value << std::endl;
}