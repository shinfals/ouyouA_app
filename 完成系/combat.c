#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int GetRandomInt(int min,int max);

int combat(Prince *prince,Princess_enemy *p_enemy,Princess_support *p_support,Item *item,Weapon *weapon,int EneNum){
  int count = 1;//ターン数
  char com;//コマンド選択肢
  int flag = 0;//0:戦闘続行,1:勝利,2:洗脳勝利,3:敗北,4:コマンド選択に戻る,5:洗脳失敗
  int sup_flag = 0;//p_supportが生きているかどうか
  int atk_flag;//敵が主人公と味方姫どちらに攻撃するか
  int damage;//敵へ与えるダメージ
  int e_damage;//敵から受けるダメージ
  int e_damage_to_sup;//味方姫が敵から受けるダメージ
  float random_num;//敵から攻撃を受ける際のランダムな倍率を保存
  int e_max_hp = p_enemy[EneNum].Hp;//敵の最大HP
  int prob;//確率用
  float pre;//GetRandomInt()を起動した後に入れる
  srand((unsigned int)time(NULL));//乱数のシード初期化
  system("cls");
  if(prince->Spd > p_enemy[EneNum].Spd){//先攻の場合の処理
    pre = (float)(GetRandomInt(750,1250))/1000.0;//乱数生成を起動
    printf("先攻です\n");
    for(;;){
      flag = 0;
      printf("[ターン:%d]\n",count);
      printf("主人公|ステータス  :  NAME:%s | HP:%d | MP:%d | ATK:%d | DEF:%d\n",prince->name,prince->Hp,prince->Mp,prince->Atk,prince->Def);
      if(p_support->Hp > 0){
        printf("味方姫|ステータス  :  HP:%d | ATK:%d | DEF%d\n",p_support->Hp,p_support->Atk,p_support->Def);
      }
      printf("敵姫|ステータス  :  NAME:%s | HP:%d | MP:%d | ATK:%d | DEF%d\n",p_enemy[EneNum].name,p_enemy[EneNum].Hp,p_enemy[EneNum].Mp,p_enemy[EneNum].Atk,p_enemy[EneNum].Def);
	  printf("1:攻撃 2:スキル 3:武器スキル 4:アイテム 5:洗脳\n");
      printf("コマンドを入力してください:");
      fflush(stdin);
      com = _getch();
      system("cls");
      switch(com){
        case '1'://攻撃
          //主人公の攻撃
          random_num = (float)(GetRandomInt(750,1250))/1000.0;
          damage = (int)(((prince->Atk + weapon[prince->wep].Atk) * random_num) - p_enemy[EneNum].Def);
          if(damage <= 0){
            printf("主人公:敵にダメージを与えられませんでした\n");
            Sleep(500);
          }else{
            p_enemy[EneNum].Hp -= damage;
          }
          if(p_enemy[EneNum].Hp <= 0){
            printf("主人公:敵に%dのダメージを与えました\n",damage);
            Sleep(500);
            printf("勝利しました\n");
            flag = 1;
          }else if(damage > 0){
            printf("主人公:敵に%dのダメージを与えました\n",damage);
            Sleep(500);
          }
          if(p_support->Hp > 0 && flag == 0){//味方姫がいれば攻撃
            random_num = (float)(GetRandomInt(750,1250))/1000.0;
            damage = (int)((p_support->Atk * random_num) - p_enemy[EneNum].Def);
            if(damage <= 0){
              printf("味方姫:敵にダメージを与えられませんでした\n");
              Sleep(500);
            }else{
              p_enemy[EneNum].Hp -= damage;
            }
            if(p_enemy[EneNum].Hp <= 0 && flag == 0){
              printf("味方姫:敵に%dのダメージを与えました\n",damage);
              Sleep(500);
              printf("勝利しました\n");
              flag = 1;
            }else if(damage > 0){
              printf("味方姫:敵に%dのダメージを与えました\n",damage);
              Sleep(500);
            }
          }
          break;
        case '2'://スキル
          if(prince->Mp > 0){
            char name_skill_1[256] = "スラッシュ";
            char name_skill_2[256] = "レーザービーム";
            switch(prince->Skill){
              case 0://スラッシュ
                damage = (int)(((prince->Atk + weapon[prince->wep].Atk) * ((float)(GetRandomInt(1500,2500))/1000.0)) - p_enemy[EneNum].Def);
                p_enemy[EneNum].Hp -= damage;
                if(p_enemy[EneNum].Hp <= 0){
                  printf("スキル:%sで%dダメージを与えました\n",name_skill_1,damage);
                  Sleep(500);
                  printf("勝利しました\n");
                  prince->Mp--;
                  flag = 1;
                }else{
                  printf("スキル:%sで%dダメージを与えました\n",name_skill_1,damage);
                  Sleep(500);
                  prince->Mp--;
                }
                break;
              case 1://レーザービーム
                damage = 450;
                p_enemy[EneNum].Hp -= damage;
                if(p_enemy[EneNum].Hp <= 0){
                  printf("スキル:%sで%dダメージを与えました\n",name_skill_2,damage);
                  Sleep(500);
                  printf("勝利しました\n");
                  prince->Mp--;
                  flag = 1;
                }else{
                  printf("スキル:%sで%dダメージを与えました\n",name_skill_2,damage);
                  Sleep(500);
                  prince->Mp--;
                }
                break;
            }
          }else{
            printf("MPが無いためスキルは使用できません\n");
          }
          break;
        case '3'://武器スキル
          if(weapon->Skill != 0){
            damage = 1500;
            printf("武器が壊れた!\n");
            Sleep(500);
            p_enemy[EneNum].Hp -= damage;
            if(p_enemy[EneNum].Hp <= 0){
              printf("%sのスキルを用いて%dのダメージを与えました\n",weapon->name,damage);
              Sleep(500);
              printf("勝利しました\n");
              flag = 1;
            }else{
              printf("%sのスキルを用いて%dのダメージを与えました\n",weapon->name,damage);
              Sleep(500);
            }
            prince->wep = 0;
          }else{
            printf("この武器にスキルは無いため使用できません\n");
            flag = 4;
          }
          break;
        case '4'://アイテム
          if(prince->item != 0){
            char ans;
            if((item+prince->item)->Hp == 0){
              printf("MPを%d回復するポーションを保持しています。使用しますか？(y/n):",(item+prince->item)->Mp);
              ans = _getch();
              if(ans == 'y'){
                prince->Mp += (item+prince->item)->Mp;
                printf("MPを%d回復しました\n",(item+prince->item)->Mp);
                Sleep(500);
                prince->item = 0;
              }else if(ans == 'n'){
                printf("コマンド選択に戻ります\n");
                flag = 4;
              }
            }else{
              printf("HPを%d回復するポーションを保持しています。使用しますか？(y/n):",(item+prince->item)->Hp);
              ans = _getch();
              if(ans == 'y'){
                prince->Hp += (item+prince->item)->Hp;
                printf("HPを%d回復しました\n",(item+prince->item)->Hp);
                Sleep(500);
                prince->item = 0;
              }else if(ans == 'n'){
                printf("コマンド選択に戻ります\n");
                flag = 4;
              }
            }
          }else{
            printf("アイテムが無いため使用できません\n");
            flag = 4;
          }
          break;
        case '5'://洗脳
          if(p_enemy->name != "極姫"){
            prob = GetRandomInt(1,10);
            for(int i = 1; i < 11; i++){
              if((e_max_hp/10)*i >= p_enemy[EneNum].Hp){
                switch(i){
                  case 1://100%
                    flag = 2;
                    break;
                  case 2://90%
                    if(prob != i){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 3://80%
                    if(prob != 1 && prob != 9){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 4://70%
                    if(prob != 1 && prob != 3 && prob != 8){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 5://60%
                    if(prob != 2 && prob != 3 && prob != 5 && prob != 7){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 6://50%
                    if(prob%2 == 0){
                      flag = 0;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 7://40%
                    if(prob == 2 || prob == 4 || prob == 6 || prob == 10){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 8://30%
                    if(prob == 3 || prob == 6 || prob == 8){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 9://20%
                    if(prob == 6 || prob == 9){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 10://10%
                    if(prob == i){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  }
                }
                if(flag == 2 || flag == 5){
                  break;
                }
              }
            }
            //洗脳に成功or失敗したかの判定
            if(flag == 2){
              printf("洗脳に成功しました\n");
            }else if(flag == 5){
              if(p_enemy->name == "極姫"){
                printf("極姫は洗脳できません\n");
                Sleep(500);
              }else{
                printf("洗脳に失敗しました\n");
                Sleep(500);
              }
            }
            break;
          default:
            printf("正しい値を入力してください\n");
            flag = 4;
            break;
          }
      if(flag == 0 || flag == 5){
        random_num = (float)(GetRandomInt(750,1250))/1000.0;
        e_damage = (int)((p_enemy[EneNum].Atk * random_num) - (prince->Def + weapon->Def));
        e_damage_to_sup = (int)((p_enemy[EneNum].Atk * random_num) - p_support->Def);
        atk_flag = GetRandomInt(0,1);
        if(atk_flag == 0 || p_support->Hp <= 0){//主人公or味方姫どちらに攻撃するか？
          if(e_damage <= 0){//ダメージが0を下回った場合の処理
            printf("主人公:ダメージを受けませんでした\n");
            Sleep(500);
          }else{
            prince->Hp -= e_damage;
          }
          if(prince->Hp <= 0){
            printf("主人公:敵から%dのダメージを受けました\n",e_damage);
            Sleep(500);
            printf("敗北しました\n");
            flag = 3;
          }else if(e_damage > 0){
            printf("主人公:敵から%dのダメージを受けました\n",e_damage);
            Sleep(500);
          }
        }else{
          if(e_damage_to_sup <= 0){//ダメージが0を下回った場合の処理
            printf("味方姫:ダメージを受けませんでした\n");
            Sleep(500);
          }else{
            p_support->Hp -= e_damage_to_sup;
          }
          if(p_support->Hp <= 0 && sup_flag == 0){
            printf("味方姫:敵から%dのダメージを受けました\n",e_damage_to_sup);
            Sleep(500);
            printf("味方姫:倒されました\n");
            sup_flag = 1;
          }else if(e_damage_to_sup > 0){
            printf("味方姫:敵から%dのダメージを受けました\n",e_damage_to_sup);
            Sleep(500);
          }
        }
      }
      if(!(flag == 0 || flag == 4 || flag == 5)){
        break;
      }else if(flag != 4){
        count++;
      }
    }
  }else if(prince->Spd <= p_enemy[EneNum].Spd){//後攻の場合の処理
    pre = (float)(GetRandomInt(750,1250))/1000.0;//乱数生成を起動
    printf("後攻です\n");
    for(;;){
      if(flag != 4){
        random_num = (float)(GetRandomInt(750,1250))/1000.0;
        e_damage = (int)((p_enemy[EneNum].Atk * random_num) - (prince->Def + weapon->Def));
        e_damage_to_sup = (int)((p_enemy[EneNum].Atk * random_num) - p_support->Def);
        atk_flag = GetRandomInt(0,1);
        if(atk_flag == 0 || p_support->Hp <= 0){//主人公or味方姫どちらに攻撃するか？
          if(e_damage <= 0){//ダメージが0を下回った場合の処理
            printf("主人公:ダメージを受けませんでした\n");
            Sleep(500);
          }else{
            prince->Hp -= e_damage;
          }
          if(prince->Hp <= 0){
            printf("主人公:敵から%dのダメージを受けました\n",e_damage);
            Sleep(500);
            printf("敗北しました\n");
            flag = 3;
          }else if(e_damage > 0){
            printf("主人公:敵から%dのダメージを受けました\n",e_damage);
            Sleep(500);
          }
        }else{
          if(e_damage_to_sup <= 0){//ダメージが0を下回った場合の処理
            printf("味方姫:ダメージを受けませんでした\n");
            Sleep(500);
          }else{
            p_support->Hp -= e_damage_to_sup;
          }
          if(p_support->Hp <= 0 && sup_flag == 0){
            printf("味方姫:敵から%dのダメージを受けました\n",e_damage_to_sup);
            Sleep(500);
            printf("味方姫:倒されました\n");
            sup_flag = 1;
          }else if(e_damage_to_sup > 0){
            printf("味方姫:敵から%dのダメージを受けました\n",e_damage_to_sup);
            Sleep(500);
          }
        }
      }
      if(flag == 4 || flag == 5){
        flag = 0;
      }
      if(flag != 0){
        break;
      }
      printf("[ターン:%d]\n",count);
      printf("主人公|ステータス  :  NAME:%s | HP:%d | MP:%d | ATK:%d | DEF:%d\n",prince->name,prince->Hp,prince->Mp,prince->Atk,prince->Def);
      if(p_support->Hp > 0){
        printf("味方姫|ステータス  :  HP:%d | ATK:%d | DEF%d\n",p_support->Hp,p_support->Atk,p_support->Def);
      }
      printf("敵姫|ステータス  :  NAME:%s | HP:%d | MP:%d | ATK:%d | DEF%d\n",p_enemy[EneNum].name,p_enemy[EneNum].Hp,p_enemy[EneNum].Mp,p_enemy[EneNum].Atk,p_enemy[EneNum].Def);
      printf("1:攻撃 2:スキル 3:武器スキル 4:アイテム 5:洗脳\n");
      printf("コマンドを入力してください:");
      fflush(stdin);
      com = _getch();
      system("cls");
      switch(com){
        case '1'://攻撃
          //主人公の攻撃
          random_num = (float)(GetRandomInt(750,1250))/1000.0;
          damage = (int)(((prince->Atk + weapon[prince->wep].Atk) * random_num) - p_enemy[EneNum].Def);
          if(damage <= 0){
            printf("主人公:敵にダメージを与えられませんでした\n");
            Sleep(500);
          }else{
            p_enemy[EneNum].Hp -= damage;
          }
          if(p_enemy[EneNum].Hp <= 0){
            printf("主人公:敵に%dのダメージを与えました\n",damage);
            Sleep(500);
            printf("勝利しました\n");
            flag = 1;
          }else if(damage > 0){
            printf("主人公:敵に%dのダメージを与えました\n",damage);
            Sleep(500);
          }
          if(p_support->Hp > 0 && flag == 0){//味方姫がいれば攻撃
            random_num = (float)(GetRandomInt(750,1250))/1000.0;
            damage = (int)((p_support->Atk * random_num) - p_enemy[EneNum].Def);
            if(damage <= 0){
              printf("味方姫:敵にダメージを与えられませんでした\n");
              Sleep(500);
            }else{
              p_enemy[EneNum].Hp -= damage;
            }
            if(p_enemy[EneNum].Hp <= 0 && flag == 0){
              printf("味方姫:敵に%dのダメージを与えました\n",damage);
              Sleep(500);
              printf("勝利しました\n");
              flag = 1;
            }else if(damage > 0){
              printf("味方姫:敵に%dのダメージを与えました\n",damage);
              Sleep(500);
            }
          }
          break;
        case '2'://スキル
          if(prince->Mp > 0){
            char name_skill_1[256] = "スラッシュ";
            char name_skill_2[256] = "レーザービーム";
            switch(prince->Skill){
              case 0://スラッシュ
                damage = (int)(((prince->Atk + weapon[prince->wep].Atk) * ((float)(GetRandomInt(1500,2500))/1000.0)) - p_enemy[EneNum].Def);
                p_enemy[EneNum].Hp -= damage*2;
                if(p_enemy[EneNum].Hp <= 0){
                  printf("スキル:%sで%dダメージを与えました\n",name_skill_1,damage);
                  Sleep(500);
                  printf("勝利しました\n");
                  prince->Mp--;
                  flag = 1;
                }else{
                  printf("スキル:%sで%dダメージを与えました\n",name_skill_1,damage);
                  Sleep(500);
                  prince->Mp--;
                }
                break;
              case 1://レーザービーム
                damage = 450;
                p_enemy[EneNum].Hp -= damage;
                if(p_enemy[EneNum].Hp <= 0){
                  printf("スキル:%sで%dダメージを与えました\n",name_skill_2,damage);
                  Sleep(500);
                  printf("勝利しました\n");
                  prince->Mp--;
                  flag = 1;
                }else{
                  printf("スキル:%sで%dダメージを与えました\n",name_skill_2,damage);
                  Sleep(500);
                  prince->Mp--;
                }
                break;
            }
          }else{
            printf("MPが無いためスキルは使用できません\n");
          }
          break;
        case '3'://武器スキル
          if(weapon[prince->wep].Skill != 0){
            damage = 1500;
            printf("武器が壊れた!\n");
            Sleep(500);
            p_enemy[EneNum].Hp -= damage;
            if(p_enemy[EneNum].Hp <= 0){
              printf("%sのスキルを用いて%dのダメージを与えました\n",weapon->name,damage);
              Sleep(500);
              printf("勝利しました\n");
              flag = 1;
            }else{
              printf("%sのスキルを用いて%dのダメージを与えました\n",weapon->name,damage);
              Sleep(500);
            }
            prince->wep = 0;
          }else{
            printf("この武器にスキルは無いため使用できません\n");
            flag = 4;
          }
          break;
        case '4'://アイテム
          if(prince->item != 0){
            char ans;
            if((item+prince->item)->Hp == 0){
              printf("MPを%d回復するポーションを保持しています。使用しますか？(y/n):",(item+prince->item)->Mp);
              ans = _getch();
              if(ans == 'y'){
                prince->Mp += (item+prince->item)->Mp;
                printf("MPを%d回復しました\n",(item+prince->item)->Mp);
                Sleep(500);
                prince->item = 0;
              }else if(ans == 'n'){
                printf("コマンド選択に戻ります\n");
                flag = 4;
              }
            }else{
              printf("HPを%d回復するポーションを保持しています。使用しますか？(y/n):",(item+prince->item)->Hp);
              ans = _getch();
              if(ans == 'y'){
                prince->Hp += (item+prince->item)->Hp;
                printf("HPを%d回復しました\n",(item+prince->item)->Hp);
                Sleep(500);
                prince->item = 0;
              }else if(ans == 'n'){
                printf("コマンド選択に戻ります\n");
                flag = 4;
              }
            }
          }else{
            printf("アイテムが無いため使用できません\n");
            flag = 4;
          }
          break;
        case '5'://洗脳
          if(p_enemy->name != "極姫"){
            prob = GetRandomInt(1,10);
            for(int i = 1; i < 11; i++){
              if((e_max_hp/10)*i >= p_enemy[EneNum].Hp){
                switch(i){
                  case 1://100%
                    flag = 2;
                    break;
                  case 2://90%
                    if(prob != i){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 3://80%
                    if(prob != 1 && prob != 9){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 4://70%
                    if(prob != 1 && prob != 3 && prob != 8){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 5://60%
                    if(prob != 2 && prob != 3 && prob != 5 && prob != 7){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 6://50%
                    if(prob%2 == 0){
                      flag = 0;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 7://40%
                    if(prob == 2 || prob == 4 || prob == 6 || prob == 10){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 8://30%
                    if(prob == 3 || prob == 6 || prob == 8){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 9://20%
                    if(prob == 6 || prob == 9){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  case 10://10%
                    if(prob == i){
                      flag = 2;
                    }else{
                      flag = 5;
                    }
                    break;
                  }
                }
                if(flag == 2 || flag == 5){
                  break;
                }
              }
            }
            //洗脳に成功or失敗したかの判定
            if(flag == 2){
              printf("洗脳に成功しました\n");
            }else if(flag == 5){
              if(p_enemy->name == "極姫"){
                printf("極姫は洗脳できません\n");
                Sleep(500);
              }else{
                printf("洗脳に失敗しました\n");
                Sleep(500);
              }
            }
            break;
          default:
            printf("正しい値を入力してください\n");
            flag = 4;
            break;
          }
          if(!(flag == 0 || flag == 4 || flag == 5)){
            break;
          }else if(flag != 4){
            count++;
          }
        }
      }
	system("pause");
  return flag;
}

int GetRandomInt(int min,int max)
{
	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
