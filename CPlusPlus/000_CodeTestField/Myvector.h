#pragma once
#include <GameEngineBase/GameEngineDebug.h>

template <typename DataType>
class Myvector
{
public:
	//constructor destructor
	Myvector();
	~Myvector();

	//default function
	Myvector(const Myvector& _Other) = delete;
	Myvector(Myvector&& _Other) noexcept = delete;
	Myvector& operator=(const Myvector& _Other) = delete;
	Myvector& operator=(Myvector&& _Other) noexcept = delete;

	void Resize(int _Value);
	void SetElement(int _Order, DataType _Value);
	DataType GetElement(int _Order);

	DataType& operator[](int _Index) const
	{
		if (Size <= _Index)
		{
			MsgBoxAssert("�ε����� �����Ͽ� ���͸� ����Ϸ��� �߽��ϴ�.");
		}

		return Ptr[_Index];
	}

protected:
	

private:
	int Size = 0;
	DataType* Ptr = nullptr;

};