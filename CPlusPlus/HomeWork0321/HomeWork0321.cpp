#include <iostream>
#include <conio.h>

void StatusRender(
    const char* const _Name, // 이름
    const int& _Att,  // 공격력
    const int& _Hp // 체력
)
{
    printf_s("%s 의 스테이터스 ------------\n", _Name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _Hp);
    printf_s("---------------------------\n");
}

int Damage(
    const char* const _Attacker_Name, // 때리는 쪽의 이름
    const int& _Attacker_att,  // 때리는 쪽의 공격력
    int& _Attacker_Hp, // 때리는 쪽의 체력
    const char* const _Defender_Name, // 맞는 쪽의 이름 
    const int& _Defender_att,  //맞는쪽의 공격력
    int& _Defender_Hp, // 맞는 쪽의 체력
    int _ord //출력순서
)
{
    int result = 0;
    _Defender_Hp -= _Attacker_att;

    system("cls");
    if (_ord == 1)
    {
        StatusRender(_Attacker_Name, _Attacker_att, _Attacker_Hp);
        StatusRender(_Defender_Name, _Defender_att, _Defender_Hp);
    }
    else
    {
        StatusRender(_Defender_Name, _Defender_att, _Defender_Hp);
        StatusRender(_Attacker_Name, _Attacker_att, _Attacker_Hp);
    }

    printf_s("%s가 공격을 시작합니다\n", _Attacker_Name);
    printf_s("%s가 %d의 데미지를 입었습니다.\n", _Defender_Name, _Attacker_att);
    _getch();

    if (0 >= _Defender_Hp)
    {
        printf_s("%s가 죽었습니다.", _Defender_Name);
        printf_s("%s의 승리입니다.", _Attacker_Name);
        _getch();
        
        result = 1;
    }
    else
    {
        result = 0;
    }

    return result;
}


int main()
{
    int PlayerHp = 100;
    int PlayerAtt = 10;

    int MonsterHp = 100;
    int MonsterAtt = 10;

    int Someone_Death = 0;

    system("cls");

    StatusRender("Player", PlayerAtt, PlayerHp);
    StatusRender("Monster", MonsterAtt, MonsterHp);
    _getch();

    while (true)
    {


        Someone_Death = Damage("Player", PlayerAtt, PlayerHp, "Monster", MonsterAtt, MonsterHp,1);

        if (Someone_Death)
        {
           break;
        }

        Someone_Death = Damage("Monster", MonsterAtt, MonsterHp, "Player", PlayerAtt, PlayerHp, 2);

        if (Someone_Death)
        {
            break;
        }

    }
}
