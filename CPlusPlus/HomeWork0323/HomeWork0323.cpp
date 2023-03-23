#include <iostream>

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


	int operator+=(int _Value)
	{
		return Value = Value + _Value;
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


	int operator++()
	{
		Value = Value + 1;
		return Value - 1;
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