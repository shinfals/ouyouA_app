#include <stdlib.h>
#include <time.h>

int GetRandomInt(int min,int max);

int combat(Prince *prince,Princess_enemy *p_enemy,Princess_support *p_support,Item *item,Weapon *weapon){
  int count = 1;//ターン数
  int com;//コマンド選択肢
  int flag = 0;//0:戦闘続行,1:勝利,2:洗脳勝利,3:敗北,4:コマンド選択に戻る,5:洗脳失敗
  int sup_flag = 0;//p_supportが生きているかどうか
  int atk_flag;//敵が主人公と味方姫どちらに攻撃するか
  int damage;//敵へ与えるダメージ
  int e_damage;//敵から受けるダメージ
  int e_damage_to_sup;//味方姫が敵から受けるダメージ
  float random_num;//敵から攻撃を受ける際のランダムな倍率を保存
  int e_max_hp = p_enemy->Hp;//敵の最大HP
  int prob;//確率用
  float pre;//GetRandomInt()を起動した後に入れる
  srand((unsigned int)time(NULL));//乱数のシード初期化
  system("clear");
  if(prince->Spd > p_enemy->Spd){//先攻の場合の処理
    pre = (float)(GetRandomInt(750,1250))/1000.0;//乱数生成を起動
    printf("先攻です\n");
    for(;;){
      flag = 0;
      printf("[ターン:%d]\n",count);
      printf("主人公|ステータス  :  NAME:%s | HP:%d | MP:%d | ATK:%d | DEF:%d\n",prince->name,prince->Hp,prince->Mp,prince->Atk,prince->Def);
      if(p_support->Hp > 0){
        printf("味方姫|ステータス  :  HP:%d | ATK:%d | DEF%d\n",p_support->Hp,p_support->Atk,p_support->Def);
      }
      printf("敵姫|ステータス  :  NAME:%s | HP:%d | MP:%d | ATK:%d | DEF%d\n",p_enemy->name,p_enemy->Hp,p_enemy->Mp,p_enemy->Atk,p_enemy->Def);
      printf("1:攻撃 2:スキル 3:武器スキル 4:アイテム 5:洗脳\n");
      printf("コマンドを入力してください:");
      fflush(stdin);
      scanf("%d",&com);
      system("clear");
      switch(com){
        case 1://攻撃
          //主人公の攻撃
          random_num = (float)(GetRandomInt(750,1250))/1000.0;
          damage = (int)(((prince->Atk + (weapon+prince->weapon)->Atk) * random_num) - p_enemy->Def);
          if(damage <= 0){
            printf("主人公:敵にダメージを与えられませんでした\n");
          }else{
            p_enemy->Hp -= damage;
          }
          if(p_enemy->Hp <= 0){
            printf("勝利しました\n");
            flag = 1;
          }else if(damage > 0){
            printf("主人公:敵に%dのダメージを与えました\n",damage);
          }
          if(p_support->Hp > 0 && flag == 0){//味方姫がいれば攻撃
            random_num = (float)(GetRandomInt(750,1250))/1000.0;
            damage = (int)((p_support->Atk * random_num) - p_enemy->Def);
            if(damage <= 0){
              printf("味方姫:敵にダメージを与えられませんでした\n");
            }else{
              p_enemy->Hp -= damage;
            }
            if(p_enemy->Hp <= 0 && flag == 0){
              printf("勝利しました\n");
              flag = 1;
            }else if(damage > 0){
              printf("味方姫:敵に%dのダメージを与えました\n",damage);
            }
          }
          break;
        case 2://スキル
          if(prince->Mp > 0){
            char name_skill_1[256] = "スラッシュ";
            char name_skill_2[256] = "レーザービーム";
            switch(prince->Skill){
              case 0://スラッシュ
                damage = (int)(((prince->Atk + (weapon+prince->weapon)->Atk) * ((float)(GetRandomInt(1500,2500))/1000.0)) - p_enemy->Def);
                p_enemy->Hp -= damage;
                if(p_enemy->Hp <= 0){
                  printf("勝利しました\n");
                  prince->Mp--;
                  flag = 1;
                }else{
                  printf("スキル:%sで%dダメージを与えました\n",name_skill_1,damage);
                  prince->Mp--;
                }
                break;
              case 1://レーザービーム
                damage = 300;
                p_enemy->Hp -= damage;
                if(p_enemy->Hp <= 0){
                  printf("勝利しました\n");
                  prince->Mp--;
                  flag = 1;
                }else{
                  printf("スキル:%sで%dダメージを与えました\n",name_skill_2,damage);
                  prince->Mp--;
                }
                break;
            }
          }else{
            printf("MPが無いためスキルは使用できません\n");
          }
          break;
        case 3://武器スキル
          if((weapon+prince->weapon)->Skill != 0){
            damage = 1500;
            p_enemy->Hp -= damage;
            if(p_enemy->Hp <= 0){
              printf("勝利しました\n");
              flag = 1;
            }else{
              printf("%sのスキルを用いて%dのダメージを与えました\n",(weapon+prince->weapon)->name,damage);
            }
          }else{
            printf("この武器にスキルは無いため使用できません\n");
            flag = 4;
          }
          break;
        case 4://アイテム
          if(prince->item != 0){
            char ans;
            if((item+prince->item)->Hp == 0){
              printf("MPを%d回復するポーションを保持しています。使用しますか？(y/n):",(item+prince->item)->Mp);
              scanf("%*c%c",&ans);
              if(ans == 'y'){
                prince->Mp += (item+prince->item)->Mp;
                printf("MPを%d回復しました\n",(item+prince->item)->Mp);
                prince->item = 0;
              }else if(ans == 'n'){
                printf("コマンド選択に戻ります\n");
              }
            }else{
              printf("HPを%d回復するポーションを保持しています。使用しますか？(y/n):",(item+prince->item)->Hp);
              scanf("%*c%c",&ans);
              if(ans == 'y'){
                prince->Hp += (item+prince->item)->Hp;
                printf("HPを%d回復しました\n",(item+prince->item)->Hp);
                prince->item = 0;
              }else if(ans == 'n'){
                printf("コマンド選択に戻ります\n");
              }
            }
          }else{
            printf("アイテムが無いため使用できません\n");
          }
          flag = 4;
          break;
        case 5://洗脳
          prob = GetRandomInt(1,10);
          for(int i = 1; i < 11; i++){
            if((e_max_hp/10)*i >= p_enemy->Hp){
              switch(i){
                case 1://100%
                  flag = 2;
                  break;
                case 2://90%
                  if(prob != i){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 3://80%
                  if(prob != 1 && prob != 9){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 4://70%
                  if(prob != 1 && prob != 3 && prob != 8){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 5://60%
                  if(prob != 2 && prob != 3 && prob != 5 && prob != 7){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 6://50%
                  if(prob%2 == 0){
                    flag = 0;
                  }
                  flag = 5;
                  break;
                case 7://40%
                  if(prob == 2 || prob == 4 || prob == 6 || prob == 10){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 8://30%
                  if(prob == 3 || prob == 6 || prob == 8){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 9://20%
                  if(prob == 6 || prob == 9){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 10://10%
                  if(prob == i){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                }
              }
              if(flag == 2 || flag == 5){
                break;
              }
            }
            //洗脳に成功or失敗したかの判定
            if(flag == 2){
              printf("洗脳に成功しました\n");
            }else if(flag == 5){
              printf("洗脳に失敗しました\n");
            }
            break;
          default:
            printf("正しい値を入力してください\n");
            flag = 4;
            break;
          }
      if(flag == 0 || flag == 5){
        random_num = (float)(GetRandomInt(750,1250))/1000.0;
        e_damage = (int)((p_enemy->Atk * random_num) - (prince->Def + (weapon+prince->weapon)->Def));
        e_damage_to_sup = (int)((p_enemy->Atk * random_num) - p_support->Def);
        atk_flag = GetRandomInt(0,1);
        if(atk_flag == 0 || p_support->Hp <= 0){//主人公or味方姫どちらに攻撃するか？
          if(e_damage <= 0){//ダメージが0を下回った場合の処理
            printf("主人公:ダメージを受けませんでした\n");
          }else{
            prince->Hp -= e_damage;
          }
          if(prince->Hp <= 0){
            printf("敗北しました\n");
            flag = 3;
          }else if(e_damage > 0){
            printf("主人公:敵から%dのダメージを受けました\n",e_damage);
          }
        }else{
          if(e_damage_to_sup <= 0){//ダメージが0を下回った場合の処理
            printf("味方姫:ダメージを受けませんでした\n");
          }else{
            p_support->Hp -= e_damage_to_sup;
          }
          if(p_support->Hp <= 0 && sup_flag == 0){
            printf("味方姫:倒されました\n");
            sup_flag = 1;
          }else if(e_damage_to_sup > 0){
            printf("味方姫:敵から%dのダメージを受けました\n",e_damage_to_sup);
          }
        }
      }
      if(!(flag == 0 || flag == 4 || flag == 5)){
        break;
      }else if(flag != 4){
        count++;
      }
    }
  }else if(prince->Spd <= p_enemy->Spd){//後攻の場合の処理
    pre = (float)(GetRandomInt(750,1250))/1000.0;//乱数生成を起動
    printf("後攻です\n");
    for(;;){
      if(flag != 4){
        random_num = (float)(GetRandomInt(750,1250))/1000.0;
        e_damage = (int)((p_enemy->Atk * random_num) - (prince->Def + (weapon+prince->weapon)->Def));
        e_damage_to_sup = (int)((p_enemy->Atk * random_num) - p_support->Def);
        atk_flag = GetRandomInt(0,1);
        if(atk_flag == 0 || p_support->Hp <= 0){//主人公or味方姫どちらに攻撃するか？
          if(e_damage <= 0){//ダメージが0を下回った場合の処理
            printf("主人公:ダメージを受けませんでした\n");
          }else{
            prince->Hp -= e_damage;
          }
          if(prince->Hp <= 0){
            printf("敗北しました\n");
            flag = 3;
          }else if(e_damage > 0){
            printf("主人公:敵から%dのダメージを受けました\n",e_damage);
          }
        }else{
          if(e_damage_to_sup <= 0){//ダメージが0を下回った場合の処理
            printf("味方姫:ダメージを受けませんでした\n");
          }else{
            p_support->Hp -= e_damage_to_sup;
          }
          if(p_support->Hp <= 0 && sup_flag == 0){
            printf("味方姫:倒されました\n");
            sup_flag = 1;
          }else if(e_damage_to_sup > 0){
            printf("味方姫:敵から%dのダメージを受けました\n",e_damage_to_sup);
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
      printf("敵姫|ステータス  :  NAME:%s | HP:%d | MP:%d | ATK:%d | DEF%d\n",p_enemy->name,p_enemy->Hp,p_enemy->Mp,p_enemy->Atk,p_enemy->Def);
      printf("1:攻撃 2:スキル 3:武器スキル 4:アイテム 5:洗脳\n");
      printf("コマンドを入力してください:");
      fflush(stdin);
      scanf("%d",&com);
      system("clear");
      switch(com){
        case 1://攻撃
          //主人公の攻撃
          random_num = (float)(GetRandomInt(750,1250))/1000.0;
          damage = (int)(((prince->Atk + (weapon+prince->weapon)->Atk) * random_num) - p_enemy->Def);
          if(damage <= 0){
            printf("主人公:敵にダメージを与えられませんでした\n");
          }else{
            p_enemy->Hp -= damage;
          }
          if(p_enemy->Hp <= 0){
            printf("勝利しました\n");
            flag = 1;
          }else if(damage > 0){
            printf("主人公:敵に%dのダメージを与えました\n",damage);
          }
          if(p_support->Hp > 0 && flag == 0){//味方姫がいれば攻撃
            random_num = (float)(GetRandomInt(750,1250))/1000.0;
            damage = (int)((p_support->Atk * random_num) - p_enemy->Def);
            if(damage <= 0){
              printf("味方姫:敵にダメージを与えられませんでした\n");
            }else{
              p_enemy->Hp -= damage;
            }
            if(p_enemy->Hp <= 0 && flag == 0){
              printf("勝利しました\n");
              flag = 1;
            }else if(damage > 0){
              printf("味方姫:敵に%dのダメージを与えました\n",damage);
            }
          }
          break;
        case 2://スキル
          if(prince->Mp > 0){
            char name_skill_1[256] = "スラッシュ";
            char name_skill_2[256] = "レーザービーム";
            switch(prince->Skill){
              case 0://スラッシュ
                damage = (int)(((prince->Atk + (weapon+prince->weapon)->Atk) * ((float)(GetRandomInt(1500,2500))/1000.0)) - p_enemy->Def);
                p_enemy->Hp -= damage;
                if(p_enemy->Hp <= 0){
                  printf("勝利しました\n");
                  prince->Mp--;
                  flag = 1;
                }else{
                  printf("スキル:%sで%dダメージを与えました\n",name_skill_1,damage);
                  prince->Mp--;
                }
                break;
              case 1://レーザービーム
                damage = 300;
                p_enemy->Hp -= damage;
                if(p_enemy->Hp <= 0){
                  printf("勝利しました\n");
                  prince->Mp--;
                  flag = 1;
                }else{
                  printf("スキル:%sで%dダメージを与えました\n",name_skill_2,damage);
                  prince->Mp--;
                }
                break;
            }
          }else{
            printf("MPが無いためスキルは使用できません\n");
          }
          break;
        case 3://武器スキル
          if((weapon+prince->weapon)->Skill != 0){
            damage = 1500;
            p_enemy->Hp -= damage;
            if(p_enemy->Hp <= 0){
              printf("勝利しました\n");
              flag = 1;
            }else{
              printf("%sのスキルを用いて%dのダメージを与えました\n",(weapon+prince->weapon)->name,damage);
            }
          }else{
            printf("この武器にスキルは無いため使用できません\n");
            flag = 4;
          }
          break;
        case 4://アイテム
          if(prince->item != 0){
            char ans;
            if((item+prince->item)->Hp == 0){
              printf("MPを%d回復するポーションを保持しています。使用しますか？(y/n):",(item+prince->item)->Mp);
              scanf("%*c%c",&ans);
              if(ans == 'y'){
                prince->Mp += (item+prince->item)->Mp;
                printf("MPを%d回復しました\n",(item+prince->item)->Mp);
                prince->item = 0;
              }else if(ans == 'n'){
                printf("コマンド選択に戻ります\n");
              }
            }else{
              printf("HPを%d回復するポーションを保持しています。使用しますか？(y/n):",(item+prince->item)->Hp);
              scanf("%*c%c",&ans);
              if(ans == 'y'){
                prince->Hp += (item+prince->item)->Hp;
                printf("HPを%d回復しました\n",(item+prince->item)->Hp);
                prince->item = 0;
              }else if(ans == 'n'){
                printf("コマンド選択に戻ります\n");
              }
            }
          }else{
            printf("アイテムが無いため使用できません\n");
          }
          flag = 4;
          break;
        case 5://洗脳
          prob = GetRandomInt(1,10);
          for(int i = 1; i < 11; i++){
            if((e_max_hp/10)*i >= p_enemy->Hp){
              switch(i){
                case 1://100%
                  flag = 2;
                  break;
                case 2://90%
                  if(prob != i){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 3://80%
                  if(prob != 1 && prob != 9){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 4://70%
                  if(prob != 1 && prob != 3 && prob != 8){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 5://60%
                  if(prob != 2 && prob != 3 && prob != 5 && prob != 7){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 6://50%
                  if(prob%2 == 0){
                    flag = 0;
                  }
                  flag = 5;
                  break;
                case 7://40%
                  if(prob == 2 || prob == 4 || prob == 6 || prob == 10){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 8://30%
                  if(prob == 3 || prob == 6 || prob == 8){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 9://20%
                  if(prob == 6 || prob == 9){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                case 10://10%
                  if(prob == i){
                    flag = 2;
                  }
                  flag = 5;
                  break;
                }
              }
              if(flag == 2 || flag == 5){
                break;
              }
            }
            //洗脳に成功or失敗したかの判定
            if(flag == 2){
              printf("洗脳に成功しました\n");
            }else if(flag == 5){
              printf("洗脳に失敗しました\n");
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
  return flag;
}

int GetRandomInt(int min,int max)
{
	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}