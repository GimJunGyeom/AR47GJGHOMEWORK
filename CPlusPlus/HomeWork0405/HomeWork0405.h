#pragma once

typedef int DataType;

// 설명 :
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
		DataType* NewArrPtr = new DataType[NewArrCount]; //새로운 힙 메모리 위치
		DataType* TemporaryPtr = nullptr;                //기존 힙 메모리 위치 삭제용
		
		if (ArrCount < NewArrCount)                      //Resize 크기가 커지는 경우
		{
			for (int i = 0; i < NewArrCount; i++)
			{
				NewArrPtr[i] = i < ArrCount ? ArrPtr[i] : 0;
			}
		}
		else                                            //Resize 크기가 작아지는 경우
		{
			for (int i = 0; i < NewArrCount; i++)
			{
				NewArrPtr[i] = ArrPtr[i];
			}
		}

		TemporaryPtr = ArrPtr;                          //기존 힙메모리 위치 잃어버리지 않게 옮기기
		ArrPtr = NewArrPtr;                             //새 메모리 위치로 덮어쓰기
		ArrCount = NewArrCount;

		if (nullptr != TemporaryPtr)                   //기존 메모리 삭제
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

