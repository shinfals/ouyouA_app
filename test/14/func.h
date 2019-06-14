#pragma once
//関数はここにまとめます
#include "define.h"
#include "initialize.h"

void gameMain();
void gameStart();
void game_rule();
int end_initialize();
void game_Play(Prince prince,int end_flag);
void tokimeki_Dungeon_Initialize(struct Tokimeki (*p)[5]);