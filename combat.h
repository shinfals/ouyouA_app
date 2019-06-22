#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "initialize.h"

float GetRandom(float min,float max);
int GetRandomInt(int min,int max);

int combat(Prince *prince,Princess_enemy *p_enemy,Princess_support *p_support,Item *item,Weapon *weapon){
  srand((unsigned int)time(NULL));
  int count = 1;//ターン数
  int flag = 0;//0:戦闘続行,1:勝利,2:洗脳勝利,3:敗北
  int com;//コマンド選択肢
  int damage = 0;//敵へ与えるダメージ
  int e_damage = 0;//敵から受けるダメージ
  int e_max_hp = p_enemy->Hp;//敵の最大HP
  system("cls");
  if(prince->Spd > p_enemy->Spd){
    printf("先攻です\n");
    for(;;){
      printf("ターン:%d\n",count);
      printf("主人公|ステータス  :  NAME:%s | HP:%d | MP:%d | ATK:%d | DEF:%d\n",prince->name,prince->Hp,prince->Mp,prince->Atk,prince->Def);
      if(p_support->Hp > 0){
        printf("味方姫|ステータス  :  HP:%d | ATK:%d | DEF%d\n",p_support->Hp,p_support->Atk,p_support->Def);
      }
      printf("敵姫|ステータス  :  NAME:%s | HP:%d | MP:%d | ATK:%d | DEF%d\n",p_enemy->name,p_enemy->Hp,p_enemy->Mp,p_enemy->Atk,p_enemy->Def);
      printf("1:攻撃 2:スキル 3:武器スキル 4:アイテム 5:洗脳\n");
      printf("コマンドを入力してください:");
      fflush(stdin);
      scanf("%d",&com);
      system("cls");
      switch(com){
        case 1://攻撃
          damage = (int)(((prince->Atk + weapon[prince->weapon]->Atk) * GetRandom(0.75,1.25)) - p_enemy->Def);
          p_enemy->Hp -= damage;
          if(p_enemy->Hp <= 0){
            printf("勝利しました\n");
            flag = 1;
            break;
          }else{
            printf("敵に%dのダメージを与えました\n",damage);
            if(p_support->Hp <= 0){
              break;
            }
          }
          if(p_support->Hp > 0){
            damage = (int)((p_support->Atk * GetRandom(0.75,1.25)) - p_enemy->Def);
            p_enemy->Hp -= damage;
            if(p_enemy->Hp <= 0){
              printf("勝利した\n");
              flag = 1;
              break;
            }else{
              printf("味方の姫が敵に%dのダメージを与えました\n",damage);
              break;
            }
          }
        case 2://スキル
          if(prince->Mp > 0){
            switch(prince->Skill){
              case 0:
                char name[256] = "スラッシュ";
                damage = (int)(((prince->Atk + weapon[prince->weapon]->Atk) * GetRandom(1.5,2.5)) - p_enemy->Def);
                break;
              case 1:
                char name[256] = "レーザービーム";
                damage = 300;
                break;
            }
            p_enemy->Hp -= damage;
            if(p_enemy->Hp <= 0){
              printf("勝利しました\n");
              flag = 1;
              break;
            }else{
              printf("スキル:%sで%dダメージを与えました\n",name,damage);
              break;
            }
          }else{
            printf("MPが無いためスキルは使用できません\n");
            break;
          }
        case 3://武器スキル
          if(weapon[prince->weapon]->Skill != 0){
            damage = 1500;
            p_enemy->Hp -= damage;
            if(p_enemy->Hp <= 0){
              printf("勝利した\n");
              flag = 1;
              break;
            }else{
              printf("武器スキルを用いて%dのダメージを与えました",damage);
              break;
            }
          }else{
            printf("この武器にスキルは無いため使用できません\n");
            continue;
          }
        case 4://アイテム
          if(prince->item != 0){
            char ans;
            prince->Hp += item->Hp;
            prince->Mp += item->Mp;
            if(item->Hp == 0){
              printf("MPを%d回復するポーションを保持しています。使用しますか？(y/n):",item->Mp);
              scanf("%c",&ans);
              if(ans == "y"){
                prince->Mp += item->Mp;
                printf("MPを%d回復しました\n",item->Mp);
                continue;
              }else{
                printf("コマンド選択に戻ります\n");
                continue;
              }
            }else{
              printf("HPを%d回復するポーションを保持しています。使用しますか？(y/n):",item->Hp);
              scanf("%c",&ans);
              if(ans == "y"){
                prince->Hp += item->Hp;
                printf("HPを%d回復しました\n",item->Hp);
                continue;
              }else{
                printf("コマンド選択に戻ります\n");
                continue;
              }
            }
          }else{
            printf("アイテムが無いため使用できません\n");
            continue;
          }
        case 5://洗脳
          int prob;//確率用
          for(int i = 1; i < 11; i++){
            if((e_max_hp/10)*i >= p_enemy->Hp){
              prob = GetRandomInt(1,10);
              switch(i){
                case 1://100%
                  flag = 2;
                  break;
                case 2://90%
                  if(prob != i){
                    flag = 2;
                  }
                  break;
                case 3://80%
                  if(prob != 1 && prob != 9){
                    flag = 2;
                  }
                  break;
                case 4://70%
                  if(prob != 1 && prob != 3 && prob != 8){
                    flag = 2;
                  }
                  break;
                case 5://60%
                  if(prob != 2 && prob != 3 && prob != 5 && prob != 7){
                    flag = 2;
                  }
                  break;
                case 6://50%
                  if(prob%2 == 0){
                    flag = 0;
                  }
                  break;
                case 7://40%
                  if(prob == 2 || prob == 4 || prob == 6 || prob == 10){
                    flag = 2;
                  }
                  break;
                case 8://30%
                  if(prob == 3 || prob == 6 || prob == 8){
                    flag = 2;
                  }
                  break;
                case 9://20%
                  if(prob == 6 || prob == 9){
                    flag = 2;
                  }
                  break;
                case 10://10%
                  if(prob = i){
                    flag = 2;
                  }
                  break;
                }
              }
              if(flag == 2){
                break;
              }
            }
            break;
          }
      e_damage = (int)((p_enemy->Atk * GetRandom(0.75,1.25)) - (prince->Def + weapon[prince->weapon]->Def));
      if(p_enemy->Hp%2 == 0){//主人公or味方姫どちらに攻撃するか？
        prince->Hp -= e_damage;
        if(prince->Hp <= 0){
          printf("敗北しました\n");
          flag = 3;
        }else{
          printf("敵から%dのダメージを受けました\n",e_damage);
        }
      }else{
        p_support->Hp -= e_damage;
        if(p_support->Hp <= 0){
          printf("味方の姫が倒されました\n");
        }else{
          printf("味方の姫が敵から%dのダメージを受けました\n",e_damage);
        }
      }
      if(flag != 0){
        break;
      }
      count++;
    }
  }else if(prince->Spd <= p_enemy->Spd){
    printf("後攻です\n");
    for(;;){
      e_damage = (int)((p_enemy->Atk * GetRandom(0.75,1.25)) - (prince->Def + weapon[prince->weapon]->Def));
      if(p_enemy->Hp%2 == 0){//主人公or味方姫どちらに攻撃するか？
        prince->Hp -= e_damage;
        if(prince->Hp <= 0){
          printf("敗北しました\n");
          flag = 3;
        }else{
          printf("敵から%dのダメージを受けました\n",e_damage);
        }
      }else{
        p_support->Hp -= e_damage;
        if(p_support->Hp <= 0){
          printf("味方の姫が倒されました\n");
        }else{
          printf("味方の姫が敵から%dのダメージを受けました\n",e_damage);
        }
      }
      if(flag != 0){
        break;
      }
      printf("ターン:%d\n",count);
      printf("主人公|ステータス  :  NAME:%s | HP:%d | MP:%d | ATK:%d | DEF:%d\n",prince->name,prince->Hp,prince->Mp,prince->Atk,prince->Def);
      if(p_support->Hp > 0){
        printf("味方姫|ステータス  :  HP:%d | ATK:%d | DEF%d\n",p_support->Hp,p_support->Atk,p_support->Def);
      }
      printf("敵姫|ステータス  :  NAME:%s | HP:%d | MP:%d | ATK:%d | DEF%d\n",p_enemy->name,p_enemy->Hp,p_enemy->Mp,p_enemy->Atk,p_enemy->Def);
      printf("1:攻撃 2:スキル 3:武器スキル 4:アイテム 5:洗脳\n");
      printf("コマンドを入力してください:");
      fflush(stdin);
      scanf("%d",&com);
      system("cls");
      switch(com){
        case 1://攻撃
          damage = (int)(((prince->Atk + weapon[prince->weapon]->Atk) * GetRandom(0.75,1.25)) - p_enemy->Def);
          p_enemy->Hp -= damage;
          if(p_enemy->Hp <= 0){
            printf("勝利しました\n");
            flag = 1;
            break;
          }else{
            printf("敵に%dのダメージを与えました\n",damage);
            if(p_support->Hp <= 0){
              break;
            }
          }
          if(p_support->Hp > 0){
            damage = (int)((p_support->Atk * GetRandom(0.75,1.25)) - p_enemy->Def);
            p_enemy->Hp -= damage;
            if(p_enemy->Hp <= 0){
              printf("勝利した\n");
              flag = 1;
              break;
            }else{
              printf("味方の姫が敵に%dのダメージを与えました\n",damage);
              break;
            }
          }
        case 2://スキル
          if(prince->Mp > 0){
            switch(prince->Skill){
              case 0:
                char name[256] = "スラッシュ";
                damage = (int)(((prince->Atk + weapon[prince->weapon]->Atk) * GetRandom(1.5,2.5)) - p_enemy->Def);
                break;
              case 1:
                char name[256] = "レーザービーム";
                damage = 300;
                break;
            }
            p_enemy->Hp -= damage;
            if(p_enemy->Hp <= 0){
              printf("勝利しました\n");
              flag = 1;
              break;
            }else{
              printf("スキル:%sで%dダメージを与えました\n",name,damage);
              break;
            }
          }else{
            printf("MPが無いためスキルは使用できません\n");
            break;
          }
        case 3://武器スキル
          if(weapon[prince->weapon]->Skill != 0){
            damage = 1500;
            p_enemy->Hp -= damage;
            if(p_enemy->Hp <= 0){
              printf("勝利した\n");
              flag = 1;
              break;
            }else{
              printf("武器スキルを用いて%dのダメージを与えました",damage);
              break;
            }
          }else{
            printf("この武器にスキルは無いため使用できません\n");
            continue;
          }
        case 4://アイテム
          if(prince->item != 0){
            char ans;
            prince->Hp += item->Hp;
            prince->Mp += item->Mp;
            if(item->Hp == 0){
              printf("MPを%d回復するポーションを保持しています。使用しますか？(y/n):",item->Mp);
              scanf("%c",&ans);
              if(ans == "y"){
                prince->Mp += item->Mp;
                printf("MPを%d回復しました\n",item->Mp);
                continue;
              }else{
                printf("コマンド選択に戻ります\n");
                continue;
              }
            }else{
              printf("HPを%d回復するポーションを保持しています。使用しますか？(y/n):",item->Hp);
              scanf("%c",&ans);
              if(ans == "y"){
                prince->Hp += item->Hp;
                printf("HPを%d回復しました\n",item->Hp);
                continue;
              }else{
                printf("コマンド選択に戻ります\n");
                continue;
              }
            }
          }else{
            printf("アイテムが無いため使用できません\n");
            continue;
          }
        case 5://洗脳
          int prob;//確率用
          for(int i = 1; i < 11; i++){
            if((e_max_hp/10)*i >= p_enemy->Hp){
              prob = GetRandomInt(1,10);
              switch(i){
                case 1://100%
                  flag = 2;
                  break;
                case 2://90%
                  if(prob != i){
                    flag = 2;
                  }
                  break;
                case 3://80%
                  if(prob != 1 && prob != 9){
                    flag = 2;
                  }
                  break;
                case 4://70%
                  if(prob != 1 && prob != 3 && prob != 8){
                    flag = 2;
                  }
                  break;
                case 5://60%
                  if(prob != 2 && prob != 3 && prob != 5 && prob != 7){
                    flag = 2;
                  }
                  break;
                case 6://50%
                  if(prob%2 == 0){
                    flag = 0;
                  }
                  break;
                case 7://40%
                  if(prob == 2 || prob == 4 || prob == 6 || prob == 10){
                    flag = 2;
                  }
                  break;
                case 8://30%
                  if(prob == 3 || prob == 6 || prob == 8){
                    flag = 2;
                  }
                  break;
                case 9://20%
                  if(prob == 6 || prob == 9){
                    flag = 2;
                  }
                  break;
                case 10://10%
                  if(prob = i){
                    flag = 2;
                  }
                  break;
                }
              }
              if(flag == 2){
                break;
              }
            }
            break;
          }
          if(flag != 0){
            break;
          }
          count++;
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
