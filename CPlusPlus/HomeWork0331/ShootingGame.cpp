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
	if (true == ConsoleGameScreen::CheckMonsterWall())                      //���Ͱ� ���� �پ��ִ��� �˻�
	{
		if (false == ConsoleGameScreen::ReturnMonsterWallCollision())          //��Ȳ1. ���Ͱ� ���� �پ������鼭 ������ �浹�� ���°� �ƴϿ������ ���� ���� �浹�� ��Ȳ�̹Ƿ� ��ĭ�� ����
		{
			for (size_t i = 0; i < ArrMonsterCount; i++)
			{
				ArrMonster[i].DownUpdate();
			}
			ConsoleGameScreen::SetMonsterWallCollisionTrue();                      //�浹�ߴٴ� ���·� ��ȯ
		}
		else                                                                   //��Ȳ2. ���Ͱ� ���� �پ��ֱ��ѵ� ������ �浹�� ������ ��� ������ �׳� ������ ������ ��Ȳ�̴� ������ �̵�
		{
			for (size_t i = 0; i < ArrMonsterCount; i++)
				ArrMonster[i].Update();

			ConsoleGameScreen::SetMonsterWallCollisionFalse();                     //�浹���� ���� ���·� ��ȯ
		}
	}
	else                                                                       //��Ȳ3. ���Ͱ� ���� �Ⱥپ� ������ �׳� ������ �̵�
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
		MonsterAllUpdate();          //���� ��ġ�� ��� ������Ʈ
		

	}
}

void ShootingGame::GameProgress()
{
	Loading();
	GameUpdate();
}