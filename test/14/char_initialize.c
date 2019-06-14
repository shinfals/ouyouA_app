#include <stdio.h>
#include "func.h"
void char_initialize(Prince *pPri){
	pPri->name[256]="Prince";
	pPri->Hp=1000;
	pPri->Mp=1000;
	pPri->Atk=500;
	pPri->Def=500;
	pPri->Spd=5;
	pPri->Skill=1;
	pPri->flag=0;
	pPri->x=0;
	pPri->y=0;
}
