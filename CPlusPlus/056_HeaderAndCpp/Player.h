#pragma once  //한 cpp 파일 내에 중복되는 헤더를 제거해줌. 다른 cpp 파일에 있는건 중복제거 못해줌.
//헤더중복을 제거하는 일도 컴파일 시간이 늘어나게 하기 때문에 헤더는 필요할때만 include 써야한다.


class Player
{
public:
	Player()
	{
	}

	int Hp = 100;
	int Att = 10;

};

int Value = 0;