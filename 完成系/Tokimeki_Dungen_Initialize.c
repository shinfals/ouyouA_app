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
	for(int i=0;i<5;i++){
		p[i][0].Door[0]=2;
		p[i][4].Door[2]=2;
		p[0][i].Door[1]=2;
		p[4][i].Door[3]=2;
	}
	p[1][1].PrincessEnemyNum=2;
	p[2][0].PrincessEnemyNum=1;
	p[4][0].TresureChest=2;
	p[0][2].PrincessEnemyNum=3;
	p[2][2].PrincessEnemyNum=5;
	p[2][2].TresureChest=1;
	p[3][3].TresureChest=4;
	p[4][3].PrincessEnemyNum=6;
	p[4][3].Door[2]=1;
	p[0][4].PrincessEnemyNum=7;
	p[0][4].TresureChest=3;
	p[3][4].PrincessEnemyNum=4;
	p[3][4].Door[3]=1;
	p[4][4].PrincessEnemyNum=8;
}
