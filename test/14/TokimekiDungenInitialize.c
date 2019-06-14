#include <stdio.h>
#include "func.h"
void tokimeki_Dungeon_Initialize(struct Tokimeki (*p)[5]){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			p[i][j].PrincessEnemyNum=0;
			p[i][j].TreasureChest=0;
			p[i][j].DungeonDoor[0]=0;
			p[i][j].DungeonDoor[1]=0;
			p[i][j].DungeonDoor[2]=0;
			p[i][j].DungeonDoor[3]=0;
		}
	}
	
}
