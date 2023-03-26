#include <iostream>


//ctrl shift f - 모두 바꾸기
//unnamed 메모리는 값을 변경할수 없고 그 값을 받아서 사용은 할수있다 - 문법적으로 정해놓음
//ex) Number.operator+(10) = 23; 불가능
class Number
{
public:
	int Value;

public:
	Number(int _Value)
		: Value(_Value)
	{
	}

	int operator[](size_t _Value)
	{
		return Value;
	}

	bool operator==(int _Value)
	{
		if (_Value == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	int operator+(int _Value)
	{
		return Value + _Value;
	}

	int operator-(int _Value)
	{
		return Value - _Value;
	}

	int operator*(int _Value)
	{
		return Value * _Value;
	}

	int operator/(int _Value)
	{
		return Value / _Value;
	}

	int operator%(int _Value)
	{
		return Value % _Value;
	}

	bool operator<(int _Value)
	{
		if (Value < _Value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>(int _Value)
	{
		if (Value > _Value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<=(int _Value)
	{
		if (Value <= _Value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(int _Value)
	{
		if (Value >= _Value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(int _Value)
	{
		if (Value != _Value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator&&(int _Value)
	{
		if ( (Value == 0) )
		{
			return false;
		}
		else if ( (_Value == 0) )
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator||(int _Value)
	{
		if (Value != 0)
		{
			return true;
		}
		else if (_Value != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int operator&(int _Value)
	{
		return Value & _Value;
	}

	int operator|(int _Value)
	{
		return Value | _Value;
	}

	int operator<<(int _Value)
	{
		return Value << _Value;
	}

	int operator>>(int _Value)
	{
		return Value >> _Value;
	}

	int operator^(int _Value)
	{
		return Value ^ _Value;
	}


	Number operator+=(int _Value)
	{
		Value += _Value;
		return *this;
	}

	int operator-=(int _Value)
	{
		return Value = Value - _Value;
	}

	int operator*=(int _Value)
	{
		return Value = Value * _Value;
	}

	int operator/=(int _Value)
	{
		return Value = Value / _Value;
	}

	int operator%=(int _Value)
	{
		return Value = Value % _Value;
	}

	int operator&=(int _Value)
	{
		return Value = Value & _Value;
	}

	int operator|=(int _Value)
	{
		return Value = Value | _Value;
	}

	int operator^=(int _Value)
	{
		return Value = Value ^ _Value;
	}

	//후위 증감 연산자는 예외규칙으로 인자 넣어주되 그 인자를 무시하는 문법으로 만들어놈 논리적으론 맞지 않지만 문법을 그렇게 만듬

	//전위 ++
	Number& operator++()
	{
		Value = Value + 1;
		return *this;
	}

	//후위 ++
	int operator++(int)
	{
		int nResult = Value;
		Value += 1;
		return nResult;
	}

	int operator--()
	{
		Value = Value - 1;
		return Value + 1;
	}

	bool operator!()
	{
		if (Value == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


int main()
{
	Number Value = 10;

	bool Test0 = Value || 3;
	bool Test1 = Value <= 3;
	int Test2 = Value &= 3;
	int Test3 = Value ^= 4;
	


	return 0;
}