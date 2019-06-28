#include <stdio.h>
#include "func.h"

void gameMain(){
	Tokimeki_dungeon Tokimeki[MAP_WIDTH][MAP_HEIGHT];
	Princess_enemy PEnemy[9];
	Princess_support PSupport[7];
	Princess_support Prince_support={0,0,0};
	Prince prince;
	int map[MAP_WIDTH][MAP_HEIGHT] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
	};
	Weapon weapon[4];
	Item item[5];
	gameStart();
	tokimeki_Dungeon_Initialize(&Tokimeki);//ダンジョン情報初期化
	char_initialize(&prince);//キャラクター初期化
	Item_initialize(&weapon,&item);
	int end_flag = end_initialize();//終了条件初期化
	enemy_char_initialize(&PEnemy,&PSupport);
	PEnemy[0].name="フィーナ姫";
	for(;;){
		room_move(&prince,&Tokimeki,&map);//ゲーム本体の関数
		end_flag=game_event(&Tokimeki,&prince,&PEnemy,&PSupport,&Prince_support,&item,&weapon);
		if(end_flag==1){
			system("pause");
			return ;
		}else if(end_flag==3){
			printf("ゲームクリア!\n");
			system("pause");
			return ;
		}
	}
	
}
