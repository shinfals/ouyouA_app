#include <stdio.h>
#include "func.h"
#include <stdlib.h>
#include <time.h>
void char_initialize(Prince *pPri){
	int num;
	num = rand()%1000000+1;
	srand((unsigned)time(NULL));
	if(num == 689263){
		pPri->name="Prince";
		pPri->Hp=9999999;
		pPri->Mp=9999999;
		pPri->Atk=9999999;
		pPri->Def=9999999;
		pPri->Spd=9999999;
		pPri->Skill=rand()%2;
		pPri->item=0;
		pPri->key=0;
		pPri->x=0;
		pPri->y=0;
		pPri->wep=0;
	}else{
		pPri->name="Prince";
		pPri->Hp=rand()%501+1000;
		pPri->Mp=rand()%6+5;
		pPri->Atk=rand()%71+150;
		pPri->Def=rand()%101+100;
		pPri->Spd=rand()%5+1;
		pPri->Skill=rand()%2;
		pPri->item=0;
		pPri->key=0;
		pPri->x=0;
		pPri->y=0;
		pPri->wep=0;
	}
}
