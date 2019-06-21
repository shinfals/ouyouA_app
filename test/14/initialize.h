#pragma once
//構造体はここにまとめます
typedef struct Tokimeki_dungeon{
  int PrincessEnemyNum; //0=なし　1=モブ１　2=モブ２　3=モブ３　4=ノブ４
  //5=中ボス１　6=中ボス２　7=中ボス３　8=ラスボス
  int TresureChest; //0=なし　1=銅　2=鉄　3=勇者　4=スカ
  int Door[4]; //Door[0]=北　Door[1]=西　Door[2]=南 Door[3]=東
  //Door=0 通路　Door=1 鍵　Door=2 壁
}Tokimeki_dungeon;

typedef struct Princess_enemy{
  char name[256];
  int Hp;
  int Mp;
  int Atk;
  int Def;
  int Spd;
  int Skill;
}Princess_enemy;

typedef struct Prince{
  char name[256];
  int Hp;
  int Mp;
  int Atk;
  int Def;
  int Spd;
  int Skill;
  int item;
  int weapon;
  int key;
  int x;
  int y;
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
  int Mp;
}Item;
