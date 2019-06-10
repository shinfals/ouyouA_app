#include <stdio.h>
#include <stdlib.h>
#include "initialize.h"
#include "game_start.h"

#define NUM_OF_PRINCESSES 4
#define NUM_OF_MIDDLE_PRINCESSES 3
#define NUM_OF_LAST_PRINCESSES 1

void game_rule();
void end_initialize();

int main(){

  Tokimeki_dungeon Tokimeki[] = {};
  Princess_enemy PEnemy[] = {};
  Princess_support PSupport[] = {};
  Prince prince = {"Prince",1000,1000,500,500,5,1,0,0,0};

  for(;;){
    int s;
    printf("１：ゲームルール表示\n");
    printf("２：ゲームスタート\n");
    printf("上記の中から数字を選択してください：");
    scanf("%d",&s);
    if(s == 1){
      system("clear");
      //windowsの場合は下記を使用
      //system("cls");
      game_rule();//ルールを表示する関数
    }else if(s == 2){
      //dungeon_initialize(Tokimeki);//ダンジョン情報初期化
      //char_initialize(PEnemy,PSupport);//キャラクター初期化
      end_initialize();//終了条件初期化
      game_start(prince);//ゲーム本体の関数
    }
  }
  return 0;
}

void game_rule(){
  printf("主人公のステータスはゲームスタート時にランダムできまる\n");
  printf("移動時の操作は「W：上」「A：左」「S：下」「D：右」で操作する\n");
  printf("攻撃する順序は相手のSPDによる\n" );
  printf("ダメージは自身のATKー相手のDFF\n" );
  printf("スキルはMP1で1回使用可能\n");
  printf("洗脳は相手の残HPにより確率変動\n");
  printf("アイテムは戦闘終了後にランダムでドロップ\n");
  printf("宝箱は鍵を所持していないと空けられない\n");
  printf("アイテムは探索中でも使用可能\n" );
  printf("ある特定の武器はスキルを所持し、そのスキルを使用すると武器はなくなる\n" );
  printf("中ボスを倒すとラスボスに挑めるようになる\n" );
  printf("パーティが自分含め２人以上の場合、敵からの攻撃はランダムになる\n" );
  printf("宝箱からは武器が出る\n" );
}

void end_initialize(){
  int end_flag = 0;
}
