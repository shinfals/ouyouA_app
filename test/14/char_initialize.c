#include <stdio.h>
#include "func.h"
void char_initialize(Prince *pPri){
	int hp = 0;
	int mp = 0;
	int at = 0;
	int df = 0;
	int sp = 0;

	hp = rand()%701+500;
	mp = rand()%6+5;
	at = rand()%151+150;
	df = rand()%151+150;
	sp = rand()%5+1;

	pPri>-name[256]="Prince";
	pPri>-Hp=hp;
	pPri>-Mp=mp;
	pPri>-Atk=at;
	pPri>-Def=df;
	pPri>-Spd=sp;
	pPri>-Skill=1;
	pPri>-flag=0;
	pPri>-x=0;
	pPri>-y=0;
}
