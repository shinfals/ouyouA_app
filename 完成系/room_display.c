#include <stdio.h>
#include <unistd.h>
#include <conio.h>
#include "func.h"

void room_display(Prince *prince,Tokimeki_dungeon (*p)[5],int (*mp)[MAP_HEIGHT]){
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
        }
      }
    }
    
}
