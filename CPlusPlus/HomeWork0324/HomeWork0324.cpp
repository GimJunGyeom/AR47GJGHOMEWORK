
#include <iostream>
#include <conio.h>
#include <Windows.h>

//배경 크기
const int ScreenXSize = 30;
const int ScreenYSize = 15;




int main()
{
	//플레이어 위치
	int PlayerX = 10;
	int PlayerY = 10;


	//배경 초기화
	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	//장애물 크기
	const int Obstacle0_X_Min = 10;
	const int Obstacle0_X_Max = 25;

	const int Obstacle0_Y_Min = 3;
	const int Obstacle0_Y_Max = 10;

	//장애물 초기화
	char Obstacle0[ScreenYSize][ScreenXSize] = { 0 };
	for (int y = 0; y < ScreenYSize; y++)
	{
		for (int x = 0; x < ScreenXSize; x++)
		{
			Obstacle0[y][x] = 1;
		}
	}

	//폭탄 초기화
	char Boom[ScreenYSize][ScreenXSize] = { 0 };
	char(*BPtr)[ScreenXSize] = Boom;


	while (true)
	{
		system("cls");

		//배경 입력
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				Arr[y][x] = 'a';
			}
		}

		//장애물 상태입력
		for (int j = Obstacle0_Y_Min; j < Obstacle0_Y_Max; j++)
		{
			for (int i = Obstacle0_X_Min; i < Obstacle0_X_Max; i++)
			{
				if (Obstacle0[j][i] == 1)
				{
					Arr[j][i] = '#';
				}
				else
				{
					Arr[j][i] = ' ';
				}

			}
		}

		//폭탄 입력
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				switch (Boom[y][x])
				{
				case 0:                                    // 폭탄 없는 상태
				{
					break;
				}
				case 1:                                    // 최초 설치
				{
					Arr[y][x] = '@';
					Boom[y][x] += 1;                       //** 다음 폭팔 상태로 변경
					break;
				}
				case 2:                                    // 폭팔 카운트 2
				{
					Arr[y][x] = '@';
					Boom[y][x] += 1;
					break;
				}
				case 3:                                    // 폭팔 카운트 3
				{
					Arr[y][x] = '@';
					Boom[y][x] += 1;
					break;
				}
				case 4:                                    // 폭팔 카운트 4
				{
					Arr[y][x] = '@';
					Boom[y][x] += 1;
					break;
				}
				case 5:                                    // 폭팔 카운트 5
				{
					Arr[y][x] = '@';
					Boom[y][x] += 1;
					break;
				}
				case 6:                                    // 폭팔 카운트 6
				{
					Arr[y][x] = '@';
					Boom[y][x] += 1;
					break;
				}
				case 7:                                    // 폭팔 카운트 7
				{
					Arr[y][x] = '@';
					Boom[y][x] += 1;
					break;
				}
				case 8:                                    // 폭팔 카운트 8
				{
					Arr[y][x] = '@';
					Boom[y][x] += 1;
					break;
				}
				case 9:                                    // 폭팔 카운트 9
				{
					Arr[y][x] = '@';
					Boom[y][x] += 1;
					break;
				}
				case 10:                                    // 폭팔 카운트 10
				{
					Arr[y][x] = '@';
					Boom[y][x] += 1;
					break;
				}
				case 11:                                    // 폭팔 카운트 11
				{
					Arr[y][x] = '@';
					Boom[y][x] += 1;
					break;
				}
				case 12:                                    // 폭팔 카운트 12
				{
					Arr[y][x] = '@';
					Boom[y][x] += 1;
					break;
				}
				case 13:                                    // 폭발 1단계
				{
					for (int i = x - 1; i < x + 2; i++)    //** 가로 폭팔 그리기
					{
						if (Arr[y][i] == '#')              //**** 장애물 있으면 파괴되서 공백됨
						{
							Obstacle0[y][i] = 0;
						}
						if (1 <= Boom[y][i] && Boom[y][i] <= 12)  //*** 폭팔 자리에 폭탄이 있으면 그걸 폭팔상태로 바로 변경
						{
							if (i > x)
							{
								Boom[y][i] = 16;
							}
							else
							{
								Boom[y][i] = 13;
							}
						}
						Arr[y][i] = '&';
					}
					for (int j = y - 1; j < y + 2; j++)    //** 세로 폭팔 그리기
					{
						if (Arr[j][x] == '#')
						{
							Obstacle0[j][x] = 0;
						}
						if (1 <= Boom[j][x] && Boom[j][x] <= 12)
						{
							if (j > y)
							{
								Boom[j][x] = 16;
							}
							else
							{
								Boom[j][x] = 13;
							}
						}
						Arr[j][x] = '&';
					}
					Boom[y][x] += 1;
					break;
				}
				case 14:                                    // 폭팔 2단계
				{
					for (int i = x - 3; i < x + 4; i++)
					{
						if (Arr[y][i] == '#')
						{
							Obstacle0[y][i] = 0;
						}
						if (1 <= Boom[y][i] && Boom[y][i] <= 12)
						{
							if (i > x)
							{
								Boom[y][i] = 16;
							}
							else
							{
								Boom[y][i] = 13;
							}
						}
						Arr[y][i] = '&';
					}
					for (int j = y - 3; j < y + 4; j++)
					{
						if (Arr[j][x] == '#')
						{
							Obstacle0[j][x] = 0;
						}
						if (1 <= Boom[j][x] && Boom[j][x] <= 12)
						{
							if (j > y)
							{
								Boom[j][x] = 16;
							}
							else
							{
								Boom[j][x] = 13;
							}
						}
						Arr[j][x] = '&';
					}
					Boom[y][x] += 1;
					break;
				}
				case 15:                                   // 폭팔 3단계
				{
					for (int i = x - 5; i < x + 6; i++)
					{
						if (Arr[y][i] == '#')
						{
							Obstacle0[y][i] = 0;
						}
						if (1 <= Boom[y][i] && Boom[y][i] <= 12)
						{
							if (i > x)
							{
								Boom[y][i] = 16;
							}
							else
							{
								Boom[y][i] = 13;
							}
						}
						Arr[y][i] = '&';
					}
					for (int j = y - 5; j < y + 6; j++)
					{
						if (Arr[j][x] == '#')
						{
							Obstacle0[j][x] = 0;
						}
						if (1 <= Boom[j][x] && Boom[j][x] <= 12)
						{
							if (j > y)
							{
								Boom[j][x] = 16;
							}
							else
							{
								Boom[j][x] = 13;
							}
						}
						Arr[j][x] = '&';
					}
					Boom[y][x] = 0;                       //** 폭탄 없는 상태로 바꾸고 마무리
					break;
				}
				case 16:                                  //옆폭탄 터져서 영향받은 폭탄 
				{
					Arr[y][x] = '&';
					Boom[y][x] = 13;
					break;
				}
				default:
					break;
				}
			}
		}



		//플레이어 위치입력
		Arr[PlayerY][PlayerX] = '*';

		//화면 그리기
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}


		if (0 == _kbhit())
		{
			Sleep(200);
			continue;
		}



		char Ch = _getch();

		//상하좌우키 입력 이후 플레이어 위치가 전체맵의 범위 밖이거나 장애물,폭탄있는 위치일 때 갈수 없음
		switch (Ch)
		{
		case 'a':
		case 'A':
			if (PlayerX == 0)
			{
				break;
			}
			else if (Arr[PlayerY][PlayerX - 1] == '#' || Arr[PlayerY][PlayerX - 1] == '@')
			{
				break;
			}
			else
			{
				PlayerX -= 1;
				break;
			}
		case 'w':
		case 'W':
			if (PlayerY == 0)
			{
				break;
			}
			else if (Arr[PlayerY - 1][PlayerX] == '#' || Arr[PlayerY - 1][PlayerX] == '@')
			{
				break;
			}
			else
			{
				PlayerY -= 1;
				break;
			}
		case 's':
		case 'S':
			if (PlayerY == (ScreenYSize - 1))
			{
				break;
			}
			else if (Arr[PlayerY + 1][PlayerX] == '#' || Arr[PlayerY + 1][PlayerX] == '@')
			{
				break;
			}
			else
			{
				PlayerY += 1;
				break;
			}
		case 'd':
		case 'D':
			if (PlayerX == (ScreenXSize - 1))
			{
				break;
			}
			else if (Arr[PlayerY][PlayerX + 1] == '#' || Arr[PlayerY][PlayerX + 1] == '@')
			{
				break;
			}
			else
			{
				PlayerX += 1;
				break;
			}
		case 'f':
		case 'F':
			Boom[PlayerY][PlayerX] = 1;
			break;
		default:
			break;
		}



		Sleep(200);
	}


}
