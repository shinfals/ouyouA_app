#include <stdio.h>
#include "func.h"

void gameStart(){
	printf("game start!\n");
	for(;;){
		int s;
		printf(u8"１：ゲームルール表示\n");
		printf(u8"２：ゲームスタート\n");
		printf(u8"上記の中から数字を選択してください：");
		fflush(stdin);
		scanf("%d",&s);
		if(s == 1){
			// system("clear");
			//windowsの場合は下記を使用
			system("cls");
			game_rule();//ルールを表示する関数
		}else if(s == 2){
			// system("clear");
			//windowsの場合は下記を使用
			system("cls");
			break;
		}
	}
}

