#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "initialize.h"

float GetRandom(float min,float max);
int GetRandomInt(int min,int max);

int combat(Prince *prince,Princess_enemy *p_enemy,Princess_support *p_support,Item *item,Weapon *weapon){
  srand((unsigned int)time(NULL));
  int flag;
  int com;
  system("cls");
  if(prince->Spd > p_enemy->Spd){
    for(;;){
      printf("1:攻撃 2:スキル 3:武器スキル 4:アイテム 5:逃げる\n");
      printf("コマンドを入力してください:");
      scanf("%d",&com);
      switch(com){
        case 1:
          p_enemy->Hp = p_enemy->Hp - (int)((prince->Atk - p_enemy->Def) * GetRandom(0.75,1.25));
      if(p_enemy->Hp <= 0){
        count += 1;
        break;
      }
      }
      prince->Hp = prince->Hp - (int)((p_enemy->Atk - prince->Def) * GetRandom(0.75,1.25));
      if(prince->Hp <= 0){
        break;
      }
    }
  }else if(prince->Spd <= p_enemy->Spd){
    for(;;){
      prince->Hp = prince->Hp - (int)((p_enemy->Atk - prince->Def) * GetRandom(0.75,1.25));
      if(prince->Hp <= 0){
        break;
      }
      p_enemy->Hp = p_enemy->Hp - (int)((prince->Atk - p_enemy->Def) * GetRandom(0.75,1.25));
      if(p_enemy->Hp <= 0){
        count += 1;
        break;
      }
    }
  }
  return flag;
}

float GetRandom(float min,float max)
{
	return min + (rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

int GetRandomInt(int min,int max)
{
	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
