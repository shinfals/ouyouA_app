#include <stdio.h>
#include "func.h"
void tokimeki_Dungeon_Initialize(Tokimeki_dungeon (*p)[5]){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			p[i][j].PrincessEnemyNum=0;
			p[i][j].TresureChest=0;
			p[i][j].Door[0]=0;
			p[i][j].Door[1]=0;
			p[i][j].Door[2]=0;
			p[i][j].Door[3]=0;
		}
	}
	
}
