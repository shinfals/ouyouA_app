#include <stdio.h>
#include "func.h"

void room_move(Prince *prince,Tokimeki_dungeon (*p)[5],int (*mp)[MAP_HEIGHT]){
  int count = 0;
  char draw_map[ROOM_HEIGHT][ROOM_WIDTH] = {
    "***************",
    "*             *",
    "*             *",
    "*             *",
    "*             *",
    "*             *",
    "***************"
  };
  char draw_hidden[ROOM_HEIGHT][ROOM_WIDTH] = {
    "               ",
    "               ",
    "               ",
    "               ",
    "               ",
    "               ",
    "               "
  };
	mp[prince->y][prince->x] = 1;
	system("cls");
    for(int h = 0; h < MAP_HEIGHT; h++){
      for(int i = 0; i < ROOM_HEIGHT; i++){
        for(int j = 0; j < MAP_WIDTH; j++){
          if(mp[h][j] == 0){
            printf("%s",draw_hidden[i]);
          }else{
            if(h == prince->y && j == prince->x){
              draw_map[3][7] = 'P';
            }else{
              draw_map[3][7] = ' ';
            }
            printf("%s",draw_map[i]);
          }
        }
        printf("\n");
        count++;
        if(count%ROOM_HEIGHT == 0){
          //printf("\n");
        }
      }
      //printf("\n");
    }
    for(;;){
		char dir;
		printf("移動する方向をWASDで選択してください\n");
		fflush(stdin);
		scanf("%c",&dir);
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
