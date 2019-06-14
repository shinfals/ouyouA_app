#include <stdio.h>
#include <stdlib.h>
#include "initialize.h"
#include "game_start.h"
#include "game_rule.h"
#include "end_initialize.h"

#define NUM_OF_ROOM 25
#define NUM_OF_ENEMY 8

int main(){

  Tokimeki_dungeon Tokimeki[NUM_OF_ROOM];
  Princess_enemy PEnemy[NUM_OF_ENEMY];
  Princess_support PSupport[NUM_OF_ENEMY-1];
  Prince prince = {"Prince",1000,1000,500,500,5,1,0,0,0};

  for(;;){
    int s;
    printf(u8"１：ゲームルール表示\n");
    printf(u8"２：ゲームスタート\n");
    printf(u8"上記の中から数字を選択してください：");
    scanf("%d",&s);
    if(s == 1){
      // system("clear");
      //windowsの場合は下記を使用
      system("cls");
      game_rule();//ルールを表示する関数
    }else if(s == 2){
      // system("clear");
      //windowsの場合は下記を使用
      system("cls");
      //dungeon_initialize(Tokimeki);//ダンジョン情報初期化
      //char_initialize(PEnemy,PSupport);//キャラクター初期化
      int end_flag = end_initialize();//終了条件初期化
      game_start(prince,end_flag);//ゲーム本体の関数
    }
  }
  return 0;
}
