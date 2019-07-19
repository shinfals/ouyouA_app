#include <stdio.h>
#include "func.h"
#include <unistd.h>
#include <conio.h>
#include <windows.h>
//グローバル変数などあれば
void main (){
	system("chcp 65001");
	
	for(;;){
		int s;
		game_title();
		system("cls");
		printf("このゲームはフルスクリーン推奨です\n");
		printf(u8"１：ゲームプレイ\n");
		printf(u8"２：ゲームス終了\n");
		printf(u8"上記の中から数字を選択してください：");
		fflush(stdin);
		scanf("%d",&s);
		if(s == 1){
			// system("clear");
			//windowsの場合は下記を使用
			system("cls");
			gameMain();//ルールを表示する関数
		}else if(s == 2){
			// system("clear");
			//windowsの場合は下記を使用
			system("cls");
			printf("ゲームを終了します");
			sleep(3);
			break;
		}
	}
}