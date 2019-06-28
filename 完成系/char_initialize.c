#include <stdio.h>
#include "func.h"
#include <stdlib.h>
#include <time.h>
void char_initialize(Prince *pPri){
	srand((unsigned)time(NULL));
	pPri->name="Prince";
	pPri->Hp=rand()%701+500;
	pPri->Mp=rand()%6+5;
	pPri->Atk=rand()%151+150;
	pPri->Def=rand()%151+150;
	pPri->Spd=rand()%5+1;
	pPri->Skill=rand()%2;
	pPri->item=0;
	pPri->key=0;
	pPri->x=0;
	pPri->y=0;
	pPri->wep=0;
}
