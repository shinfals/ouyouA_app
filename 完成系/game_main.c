#include <stdio.h>
#include "func.h"

void gameMain(){
	Tokimeki_dungeon Tokimeki[MAP_WIDTH][MAP_HEIGHT];
	Princess_enemy PEnemy[8];
	Princess_support PSupport[8];
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
	for(;;){
		room_move(&prince,&Tokimeki,&map);//ゲーム本体の関数
		printf("主人公|ステータス  :  NAME:%s | HP:%d | MP:%d | ATK:%d | DEF:%d\n",prince.name,prince.Hp,prince.Mp,prince.Atk,prince.Def);
		//printf("所持装備:%s 所持アイテム:ポーションHP:%dMP:%d",weapon.name,item)
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
