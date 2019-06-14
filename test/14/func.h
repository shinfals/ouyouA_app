#pragma once
//関数はここにまとめます
#include "define.h"
#include "initialize.h"

void gameMain();
void gameStart();
void game_rule();
int end_initialize();
void game_Play(Prince prince,int end_flag);
void tokimeki_Dungeon_Initialize(Tokimeki_dungeon (*p)[5]);
void char_initialize(Prince *pPri);
//void char_initialize(Prince *pPri,Princess_enemy *pEne,Princess_support *pSup);
void Item_initialize(Weapon *pWep,Item *pItem);