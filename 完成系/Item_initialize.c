#include <stdio.h>
#include "func.h"
void Item_initialize(Weapon *pWep,Item *pItem){
	pWep[0].name="";//武器を持っていない時
	pWep[0].Atk=0;//
	pWep[0].Def=0;//
	pWep[0].Skill=0;//
	
  pWep[1].name="銅の剣";//武器１の名前
  pWep[1].Atk=50;//武器１のATK
  pWep[1].Def=0;//武器１のDEF
  pWep[1].Skill=0;//武器１のスキル

  pWep[2].name="鉄の剣";//武器２の名前
  pWep[2].Atk=100;//武器２のATK
  pWep[2].Def=25;//武器２のDEF
  pWep[2].Skill=0;//武器２のスキル

  pWep[3].name="勇者の剣";//武器３の名前
  pWep[3].Atk=150;//武器３のATK
  pWep[3].Def=50;//武器３のDEF
  pWep[3].Skill=6;//武器３のスキル

  pItem[0].Hp=0;//アイテムを持っていない
  pItem[0].Mp=0;//

  pItem[1].Hp=300;//アイテム１のHp回復量
  pItem[1].Mp=0;//なし

  pItem[2].Hp=500;//アイテム２のHp回復量
  pItem[2].Mp=0;//なし

  pItem[3].Hp=0;//なし
  pItem[3].Mp=3;//アイテム３のMp回復量

  pItem[4].Hp=0;//なし
  pItem[4].Mp=5;//アイテム４のMp回復量
}
