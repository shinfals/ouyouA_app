#include <stdio.h>
#include <unistd.h>
#include <conio.h>
#include "func.h"

void room_move(Prince *prince,Tokimeki_dungeon (*p)[5],int (*mp)[MAP_HEIGHT]){

    for(;;){
		char dir;
		printf("移動する方向をWASDで選択してください\n");
		fflush(stdin);
		dir=_getch();
		switch(dir){
			case 'w':
			case 'W':
				if(p[prince->x][prince->y].Door[0] == 2){
					printf("進めません\n");
				}else if (p[prince->x][prince->y].Door[0] == 1){
					if(prince->key <2){
						printf("進めません\n");
					}else{
						prince->y--;
						return;
					}
				}else{
					prince->y--;
					return;
				}
				break;
			case 'a':
			case 'A':
				if(p[prince->x][prince->y].Door[1] == 2){
					printf("進めません\n");
				}else if (p[prince->x][prince->y].Door[1] == 1){
					if(prince->key <2){
						printf("進めません\n");
					}else{
						prince->x--;
						return;
					}
				}else{
					prince->x--;
					return;
				}
				break;
			case 's':
			case 'S':
				if(p[prince->x][prince->y].Door[2] == 2){
					printf("進めません\n");
				}else if (p[prince->x][prince->y].Door[2] == 1){
					if(prince->key <2){
						printf("進めません\n");
					}else{
						prince->y++;
						return;
					}
				}else{
					prince->y++;
					return;
				}
				break;
			case 'd':
			case 'D':
				if(p[prince->x][prince->y].Door[3] == 2){
					printf("進めません\n");
				}else if (p[prince->x][prince->y].Door[3] == 1){
					if(prince->key <2){
						printf("進めません\n");
					}else{
						prince->x++;
						return;
					}
				}else{
					prince->x++;
					return;
				}
				break;
			default:
				printf("WASDで入力してください\n");
				break;
		}
    }
}
