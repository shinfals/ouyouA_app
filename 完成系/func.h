#pragma once
//関数はここにまとめます
#include "define.h"
#include "initialize.h"

void gameMain();
void gameStart();
void game_rule();
void game_end();
int end_initialize();
void room_move(Prince *prince,Tokimeki_dungeon (*p)[5],int (*mp)[MAP_HEIGHT]);
void tokimeki_Dungeon_Initialize(Tokimeki_dungeon (*p)[5]);
void char_initialize(Prince *pPri);
void Item_initialize(Weapon *pWep,Item *pItem);
void enemy_char_initialize(Princess_enemy *pPriE,Princess_support *pPriS);
int game_event(Tokimeki_dungeon (*p)[5],Prince *prince,Princess_enemy *p_enemy,Princess_support *p_support,Princess_support *prince_support,Item *item,Weapon *weapon);
int combat(Prince *prince,Princess_enemy *p_enemy,Princess_support *p_support,Item *item,Weapon *weapon,int EneNum);