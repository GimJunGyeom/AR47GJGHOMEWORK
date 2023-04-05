#pragma once

typedef int DataType;

// ���� :
class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrCount = _Other.ArrCount;
		ArrPtr = new DataType[ArrCount];

		for (int i = 0; i < ArrCount; i++)
		{
			ArrPtr[i] = _Other.ArrPtr[i];
		}

		
		return *this;
	}

	// constrcuter destructer
	GameEngineArray(size_t _Value)
		: ArrPtr(new DataType[_Value])
		, ArrCount(_Value)
	{
	}

	~GameEngineArray()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	

	size_t Count()
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	void ReSize(int _Value)
	{
		size_t NewArrCount = _Value;
		DataType* NewArrPtr = new DataType[NewArrCount]; //���ο� �� �޸� ��ġ
		DataType* TemporaryPtr = nullptr;                //���� �� �޸� ��ġ ������
		
		if (ArrCount < NewArrCount)                      //Resize ũ�Ⱑ Ŀ���� ���
		{
			for (int i = 0; i < NewArrCount; i++)
			{
				NewArrPtr[i] = i < ArrCount ? ArrPtr[i] : 0;
			}
		}
		else                                            //Resize ũ�Ⱑ �۾����� ���
		{
			for (int i = 0; i < NewArrCount; i++)
			{
				NewArrPtr[i] = ArrPtr[i];
			}
		}

		TemporaryPtr = ArrPtr;                          //���� ���޸� ��ġ �Ҿ������ �ʰ� �ű��
		ArrPtr = NewArrPtr;                             //�� �޸� ��ġ�� �����
		ArrCount = NewArrCount;

		if (nullptr != TemporaryPtr)                   //���� �޸� ����
		{
			delete[] TemporaryPtr;
			TemporaryPtr = nullptr;
		}
	}

protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;

};

