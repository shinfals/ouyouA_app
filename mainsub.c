#include <stdio.h>
#include "initialize.h"
#include "combat.h"

int main(){
  Prince prince = {"Prince",10000,1000,6000,4500,5,1,1,2,0,0,0};
  Princess_enemy p_enemy = {"enemy",8000,800,6000,3000,3,1};
  Princess_support p_support = {8000,4000,2000,3};
  Item item[4] = {
    {0,0},
    {300,0},
    {100,0},
    {0,300}
  };
  Weapon weapon[4] = {
    {"",0,0,0},
    {"銅の剣",100,0,0},
    {"鉄の剣",500,0,0},
    {"勇者の剣",1500,0,1}
  };
  combat(&prince,&p_enemy,&p_support,item,weapon);
  return 0;
}
