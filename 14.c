#include <stdio.h>

#define NUM_OF_PRINCESSES 4
#define NUM_OF_MIDDLE_PRINCESSES 3
#define NUM_OF_LAST_PRINCESSES 1

void game_rule();
void dungeon_initialize();
void char_initialize();
void end_initialize();
void game_start();

int main(){
  typedef struct Tokimeki_dungeon{
    int PrincessEnemyNum;
    int TresureChest;
    int Door[4];
  }Tokimeki_dungeon;

  typedef struct Princess_enemy{
    cahr name[256];
    int Hp;
    int Mp;
    int Atk;
    int Def;
    int Spd;
    int Skill;
  }Princess_enemy;

  typedef struct Prince{
    char naem[] = "Prince";
    int Hp;
    int Mp;
    int Atk;
    int Def;
    int Spd;
    int Skill;
    int flag = 0;
    int x = 0;
    int y = 0;
  }Prince;

  typedef struct Princess_support{
    int Hp;
    int Atk;
    int Def;
    int Spd;
  }Princess_support;

  typedef struct Weapon{
    char name[256];
    int Atk;
    int Def;
    int Skill;
  }Weapon;

  typedef struct Item{
    int Hp;
    int Mp
  }Item;

  for(;;){
    int s;
    printf("１：ゲームルール表示\n");
    printf("２：ゲームスタート\n");
    printf("上記の中から数字を選択してください：");
    scanf("%d",&s);
    if(s == 1){
      game_rule();//ルールを表示する関数
    }else if(s == 2){
      dungeon_initialize(Tokimeki_dungeon);//ダンジョン情報初期化
      char_initialize(Princess_enemy,Princess_support);//キャラクター初期化
      end_initialize();//終了条件初期化
      game_start();//ゲーム本体の関数
    }
  }
  return 0;
}

void game_rule(){

}

void end_initialize(){
  end_flag = 0;
}
