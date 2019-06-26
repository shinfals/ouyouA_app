#include <stdio.h>
#include "func.h"

int game_event(Tokimeki_dungeon (*p)[5],Prince *prince,Princess_enemy *p_enemy,Princess_support *p_support,Princess_support *prince_support,Item *item,Weapon *weapon){
	int ResCom,ItemGet,EneNum;
	char cmnd;
	EneNum=p[prince->x][prince->y].PrincessEnemyNum;
	if(EneNum > 0){
		ResCom=combat(prince,p_enemy,prince_support,item,weapon,EneNum-1);
		if(EneNum == 8 && ResCom == 1){
			return 3;
		}
		
		switch(ResCom){
			case 1:
				if(EneNum > 4 ){
					printf("鍵を拾った!\n");
					prince->key++;
					if(prince->key == 2){
						printf("二本のカギが合体してﾎﾞｽ部屋のカギになった!\n");
						printf("※宝箱はそのまま開けられます\n");
					}
				}
				p[prince->x][prince->y].PrincessEnemyNum=0;
				break;
			case 2:
				prince_support->Hp=p_support[EneNum].Hp;
				prince_support->Atk=p_support[EneNum].Atk;
				prince_support->Def=p_support[EneNum].Def;
				p[prince->x][prince->y].PrincessEnemyNum=0;
				break;
			case 3:
				gameEnd();
				return 1;
			default :
				printf("error combat\n");
				system("pause");
				return 1;
				break;
		}
		ItemGet=prince->Hp%10;
		if(ItemGet <7){
			if(ItemGet <2){
				printf("ポーションをゲットしました：HP回復量%d,SP回復量%d\n",item[1].Hp,item[1].Mp);
				printf("アイテムを拾いますか？y/n※現在所持している場合は交換されます.\n");
				for(;;){
					fflush(stdin);
					scanf("%c",&cmnd);
					if(cmnd=='y'){
						printf("アイテムを拾いました\n");
						prince->item=1;
						break;
					}else if(cmnd=='n'){
						printf("アイテムを拾いませんでした\n");
						break;
					}else{
						printf("入力を間違えています\n");
					}
				}
			}else if(ItemGet < 4){
				printf("ポーションをゲットしました：HP回復量%d,SP回復量%d\n",item[2].Hp,item[2].Mp);
				printf("アイテムを拾いますか？y/n※現在所持している場合は交換されます.\n");
				for(;;){
					fflush(stdin);
					scanf("%c",&cmnd);
					if(cmnd=='y'){
						printf("アイテムを拾いました\n");
						prince->item=2;
						break;
					}else if(cmnd=='n'){
						printf("アイテムを拾いませんでした\n");
						break;
					}else{
						printf("入力を間違えています\n");
					}
				}
			}else if(ItemGet < 6){
				printf("ポーションをゲットしました：HP回復量%d,SP回復量%d\n",item[3].Hp,item[3].Mp);
				printf("アイテムを拾いますか？y/n※現在所持している場合は交換されます.\n");
				for(;;){
					fflush(stdin);
					scanf("%c",&cmnd);
					if(cmnd=='y'){
						printf("アイテムを拾いました\n");
						prince->item=3;
						break;
					}else if(cmnd=='n'){
						printf("アイテムを拾いませんでした\n");
						break;
					}else{
						printf("入力を間違えています\n");
					}
				}
			}else{
				printf("ポーションをゲットしました：HP回復量%d,SP回復量%d\n",item[4].Hp,item[4].Mp);
				printf("アイテムを拾いますか？y/n※現在所持している場合は交換されます.\n");
				for(;;){
					fflush(stdin);
					scanf("%c",&cmnd);
					if(cmnd=='y'){
						printf("アイテムを拾いました\n");
						prince->item=4;
						break;
					}else if(cmnd=='n'){
						printf("アイテムを拾いませんでした\n");
						break;
					}else{
						printf("入力を間違えています\n");
					}
				}
			}
			system("pause");
		}
	}
	if(p[prince->x][prince->y].TresureChest >0){
		printf("宝箱を見つけた!\n");
		if(prince->key > 0){
			switch (p[prince->x][prince->y].TresureChest){
				case 1:
					printf("鍵を使って宝箱を開けた！中身は銅の剣でした\n");
					if(prince->wep < 1){
						printf("装備しました!\n");
					}else{
						printf("必要なかったので捨てました\n");
					}
					break;
				case 2:
					printf("鍵を使って宝箱を開けた！中身は鉄の剣でした\n");
					if(prince->wep < 2){
						printf("装備しました!\n");
					}else{
						printf("必要なかったので捨てました\n");
					}
					break;
				case 3:
					printf("鍵を使って宝箱を開けた！中身は勇者の剣でした\n");
					if(prince->wep < 3){
						printf("装備しました!\n");
					}else{
						printf("必要なかったので捨てました\n");
					}
					break;
				case 4:
					printf("鍵を使って宝箱を開けた！中身は空でした...\n");
					break;
				default:
					printf("TresureChestNum error\n");
					break;
			}
		}else{
			printf("鍵がないため開けられませんでした...\n");
		}
		system("pause");
	}
	return 0;
}