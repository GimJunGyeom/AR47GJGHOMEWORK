#include "ShootingGame.h"

#include <iostream>

#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading()
{

	Bullet::AllOff();
	 
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({ i + 3, 1 });
	}

}

void ShootingGame::Collision()
{

	Bullet* BulletArr = Bullet::GetArrBullet();


	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		Bullet& CurBullet = BulletArr[BulletIndex];

		if (false == CurBullet.IsUpdate())
		{
			continue;
		}

		for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
		{
			Monster& CurMonster = ArrMonster[MonsterIndex];

			if (false == CurMonster.IsUpdate())
			{
				continue;
			}

			if (CurMonster.GetPos() == CurBullet.GetPos())
			{
				CurMonster.Off();
				CurBullet.Off();
			}
		}
	}

}

void ShootingGame::MonsterAllUpdate()
{
	if (true == ConsoleGameScreen::CheckMonsterWall())                      //몬스터가 벽에 붙어있는지 검사
	{
		if (false == ConsoleGameScreen::ReturnMonsterWallCollision())          //상황1. 몬스터가 벽에 붙어있으면서 이전에 충돌한 상태가 아니였던경우 지금 벽에 충돌한 상황이므로 한칸씩 내림
		{
			for (size_t i = 0; i < ArrMonsterCount; i++)
			{
				ArrMonster[i].DownUpdate();
			}
			ConsoleGameScreen::SetMonsterWallCollisionTrue();                      //충돌했다는 상태로 전환
		}
		else                                                                   //상황2. 몬스터가 벽에 붙어있긴한데 이전에 충돌한 상태인 경우 지금은 그냥 벽에서 내려온 상황이니 옆으로 이동
		{
			for (size_t i = 0; i < ArrMonsterCount; i++)
				ArrMonster[i].Update();

			ConsoleGameScreen::SetMonsterWallCollisionFalse();                     //충돌하지 않은 상태로 전환
		}
	}
	else                                                                       //상황3. 몬스터가 벽에 안붙어 있으니 그냥 옆으로 이동
	{
		for (int i = 0; i < ArrMonsterCount; i++)
			ArrMonster[i].Update();
	}

}


void ShootingGame::GameUpdate()
{
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		NewPlayer.Render();
		Bullet::AllRender();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(ArrMonster[i].GetPos()))
			{
				ArrMonster[i].Render();
			}
		}

		Collision();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
		MonsterAllUpdate();          //몬스터 위치를 모두 업데이트
		

	}
}

void ShootingGame::GameProgress()
{
	Loading();
	GameUpdate();
}