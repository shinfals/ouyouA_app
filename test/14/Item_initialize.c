#include <stdio.h>
#include "func.h"
void Item_initialize(Weapon *pWep,Item *pItem){
	pWep[0].name[]="銅の剣";
	pWep[0].Atk=50;
	pWep[0].Def=0;
	pWep[0].skill=0;

	pWep[1].name[]="鉄の剣";
	pWep[1].Atk=100;
	pWep[1].Def=0;
	pWep[1].skill=0;

	pWep[2].name[]="勇者の剣";
	pWep[2].Atk=150;
	pWep[2].Def=0;
	pWep[2].skill=0;
}
