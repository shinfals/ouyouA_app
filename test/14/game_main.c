#include <stdio.h>
#include "func.h"

void gameMain(){
	Tokimeki_dungeon Tokimeki[MAP_WIDTH][MAP_HEIGHT];
	Princess_enemy PEnemy[NUM_OF_ENEMY];
	Princess_support PSupport[NUM_OF_ENEMY-1];
	Prince prince;
	//Prince prince = {"Prince",1000,1000,500,500,5,1,0,0,0};
	Weapon weapon[3];
	Item item[4];
	gameStart();
	tokimeki_Dungeon_Initialize(&Tokimeki);//ダンジョン情報初期化
	char_initialize(&prince,&PEnemy,&PSupport);//キャラクター初期化
	Item_initialize(&weapon,&Item);
	int end_flag = end_initialize();//終了条件初期化
	game_Play(prince,end_flag);//ゲーム本体の関数
	
}
