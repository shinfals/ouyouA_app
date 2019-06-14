#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "initialize.h"

float GetRandom(float min,float max);
int GetRandomInt(int min,int max);

int main(){
  srand((unsigned int)time(NULL));
  for(int j = 0; j < 3; j++){
    int count = 0;
    float win;
    switch(j){
      case 0:
        for(int i = 0; i < 1000; i++){
          Prince prince = {
            "hero",
            GetRandomInt(500,1200),
            GetRandomInt(5,10),
            GetRandomInt(150,300),
            GetRandomInt(50,100),
            GetRandomInt(1,5),
            0,
            0,
            0
          };
          Princess_enemy p_enemy = {
            "enemy",
            GetRandomInt(250,500),
            0,
            GetRandomInt(150,300),
            GetRandomInt(20,50),
            GetRandomInt(1,5),
            0
          };

          if(prince.Spd > p_enemy.Spd){
            for(;;){
              p_enemy.Hp = p_enemy.Hp - (int)((prince.Atk - p_enemy.Def) * GetRandom(0.75,1.25));
              if(p_enemy.Hp <= 0){
                count += 1;
                break;
              }
              prince.Hp = prince.Hp - (int)((p_enemy.Atk - prince.Def) * GetRandom(0.75,1.25));
              if(prince.Hp <= 0){
                break;
              }
            }
          }else if(prince.Spd <= p_enemy.Spd){
            for(;;){
              prince.Hp = prince.Hp - (int)((p_enemy.Atk - prince.Def) * GetRandom(0.75,1.25));
              if(prince.Hp <= 0){
                break;
              }
              p_enemy.Hp = p_enemy.Hp - (int)((prince.Atk - p_enemy.Def) * GetRandom(0.75,1.25));
              if(p_enemy.Hp <= 0){
                count += 1;
                break;
              }
            }
          }
        }
        win = (count / 1000.0) * 100.0;
        printf("prince win rate(none) : %f\n",win);
        count = 0;
        for(int i = 0; i < 1000; i++){
          Prince prince = {
            "hero",
            GetRandomInt(500,1200),
            GetRandomInt(5,10),
            GetRandomInt(150,300),
            GetRandomInt(50,100),
            GetRandomInt(1,5),
            0,
            0,
            0
          };
          Princess_enemy p_enemy = {
            "enemy",
            GetRandomInt(250,500),
            0,
            GetRandomInt(150,300),
            GetRandomInt(20,50),
            GetRandomInt(1,5),
            0
          };

          if(prince.Spd > p_enemy.Spd){
            for(;;){
              p_enemy.Hp = p_enemy.Hp - (int)(((prince.Atk + 75) - p_enemy.Def) * GetRandom(0.75,1.25));
              if(p_enemy.Hp <= 0){
                count += 1;
                break;
              }
              prince.Hp = prince.Hp - (int)((p_enemy.Atk - (prince.Def + 25)) * GetRandom(0.75,1.25));
              if(prince.Hp <= 0){
                break;
              }
            }
          }else if(prince.Spd <= p_enemy.Spd){
            for(;;){
              prince.Hp = prince.Hp - (int)((p_enemy.Atk - (prince.Def + 25)) * GetRandom(0.75,1.25));
              if(prince.Hp <= 0){
                break;
              }
              p_enemy.Hp = p_enemy.Hp - (int)(((prince.Atk + 75) - p_enemy.Def) * GetRandom(0.75,1.25));
              if(p_enemy.Hp <= 0){
                count += 1;
                break;
              }
            }
          }
        }
        win = (count / 1000.0) * 100.0;
        printf("prince win rate(weapon) : %f\n",win);
        break;
      case 1:
        for(int i = 0; i < 1000; i++){
          Prince prince = {
            "hero",
            GetRandomInt(500,1200),
            GetRandomInt(5,10),
            GetRandomInt(150,300),
            GetRandomInt(50,100),
            GetRandomInt(1,5),
            0,
            0,
            0
          };
          Princess_enemy p_enemy = {
            "enemy",
            GetRandomInt(700,1400),
            0,
            GetRandomInt(200,350),
            GetRandomInt(35,75),
            GetRandomInt(1,5),
            0
          };

          if(prince.Spd > p_enemy.Spd){
            for(;;){
              p_enemy.Hp = p_enemy.Hp - (int)((prince.Atk - p_enemy.Def) * GetRandom(0.75,1.25));
              if(p_enemy.Hp <= 0){
                count += 1;
                break;
              }
              prince.Hp = prince.Hp - (int)((p_enemy.Atk - prince.Def) * GetRandom(0.75,1.25));
              if(prince.Hp <= 0){
                break;
              }
            }
          }else if(prince.Spd <= p_enemy.Spd){
            for(;;){
              prince.Hp = prince.Hp - (int)((p_enemy.Atk - prince.Def) * GetRandom(0.75,1.25));
              if(prince.Hp <= 0){
                break;
              }
              p_enemy.Hp = p_enemy.Hp - (int)((prince.Atk - p_enemy.Def) * GetRandom(0.75,1.25));
              if(p_enemy.Hp <= 0){
                count += 1;
                break;
              }
            }
          }
        }
        win = (count / 1000.0) * 100.0;
        printf("middle prince win rate(none) : %f\n",win);
        count = 0;
        for(int i = 0; i < 1000; i++){
          Prince prince = {
            "hero",
            GetRandomInt(500,1200),
            GetRandomInt(5,10),
            GetRandomInt(150,300),
            GetRandomInt(50,100),
            GetRandomInt(1,5),
            0,
            0,
            0
          };
          Princess_enemy p_enemy = {
            "enemy",
            GetRandomInt(700,1400),
            0,
            GetRandomInt(200,350),
            GetRandomInt(35,75),
            GetRandomInt(1,5),
            0
          };

          if(prince.Spd > p_enemy.Spd){
            for(;;){
              p_enemy.Hp = p_enemy.Hp - (int)(((prince.Atk + 75) - p_enemy.Def) * GetRandom(0.75,1.25));
              if(p_enemy.Hp <= 0){
                count += 1;
                break;
              }
              prince.Hp = prince.Hp - (int)((p_enemy.Atk - (prince.Def + 25)) * GetRandom(0.75,1.25));
              if(prince.Hp <= 0){
                break;
              }
            }
          }else if(prince.Spd <= p_enemy.Spd){
            for(;;){
              prince.Hp = prince.Hp - (int)((p_enemy.Atk - (prince.Def + 25)) * GetRandom(0.75,1.25));
              if(prince.Hp <= 0){
                break;
              }
              p_enemy.Hp = p_enemy.Hp - (int)(((prince.Atk + 75) - p_enemy.Def) * GetRandom(0.75,1.25));
              if(p_enemy.Hp <= 0){
                count += 1;
                break;
              }
            }
          }
        }
        win = (count / 1000.0) * 100.0;
        printf("middle prince win rate(weapon) : %f\n",win);
        break;
      case 2:
        for(int i = 0; i < 1000; i++){
          Prince prince = {
            "hero",
            GetRandomInt(500,1200),
            GetRandomInt(5,10),
            GetRandomInt(150,300),
            GetRandomInt(50,100),
            GetRandomInt(1,5),
            0,
            0,
            0
          };
          Princess_enemy p_enemy = {
            "enemy",
            3500,
            0,
            500,
            0,
            5,
            0
          };

          if(prince.Spd > p_enemy.Spd){
            for(;;){
              p_enemy.Hp = p_enemy.Hp - (int)((prince.Atk - p_enemy.Def) * GetRandom(0.75,1.25));
              if(p_enemy.Hp <= 0){
                count += 1;
                break;
              }
              prince.Hp = prince.Hp - (int)((p_enemy.Atk - prince.Def) * GetRandom(0.75,1.25));
              if(prince.Hp <= 0){
                break;
              }
            }
          }else if(prince.Spd <= p_enemy.Spd){
            for(;;){
              prince.Hp = prince.Hp - (int)((p_enemy.Atk - prince.Def) * GetRandom(0.75,1.25));
              if(prince.Hp <= 0){
                break;
              }
              p_enemy.Hp = p_enemy.Hp - (int)((prince.Atk - p_enemy.Def) * GetRandom(0.75,1.25));
              if(p_enemy.Hp <= 0){
                count += 1;
                break;
              }
            }
          }
        }
        win = (count / 1000.0) * 100.0;
        printf("last prince win rate(none) : %f\n",win);
        count = 0;
        for(int i = 0; i < 1000; i++){
          Prince prince = {
            "hero",
            GetRandomInt(500,1200),
            GetRandomInt(5,10),
            GetRandomInt(150,300),
            GetRandomInt(50,100),
            GetRandomInt(1,5),
            0,
            0,
            0
          };
          Princess_enemy p_enemy = {
            "enemy",
            3500,
            0,
            500,
            0,
            5,
            0
          };

          if(prince.Spd > p_enemy.Spd){
            for(;;){
              p_enemy.Hp = p_enemy.Hp - (int)(((prince.Atk + 75) - p_enemy.Def) * GetRandom(0.75,1.25));
              if(p_enemy.Hp <= 0){
                count += 1;
                break;
              }
              prince.Hp = prince.Hp - (int)((p_enemy.Atk - (prince.Def + 25)) * GetRandom(0.75,1.25));
              if(prince.Hp <= 0){
                break;
              }
            }
          }else if(prince.Spd <= p_enemy.Spd){
            for(;;){
              prince.Hp = prince.Hp - (int)((p_enemy.Atk - (prince.Def + 25)) * GetRandom(0.75,1.25));
              if(prince.Hp <= 0){
                break;
              }
              p_enemy.Hp = p_enemy.Hp - (int)(((prince.Atk + 75) - p_enemy.Def) * GetRandom(0.75,1.25));
              if(p_enemy.Hp <= 0){
                count += 1;
                break;
              }
            }
          }
        }
        win = (count / 1000.0) * 100.0;
        printf("last prince win rate(weapon) : %f\n",win);
        break;
    }
  }
  return 0;
}

float GetRandom(float min,float max)
{
	return min + (rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

int GetRandomInt(int min,int max)
{
	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
