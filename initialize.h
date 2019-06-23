typedef struct Tokimeki_dungeon{
  int PrincessEnemyNum;
  int TresureChest;
  int Door[4];
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
