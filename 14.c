#include <stdio.h>

#define NUM_OF_PRINCESSES 4
#define NUM_OF_MIDDLE_PRINCESSES 3
#define NUM_OF_LAST_PRINCESSES 1

rule();
game_start();

int main(){
  for(;;){
    int s
    printf("１：ゲームルール表示\n");
    printf("２：ゲームスタート\n");
    printf("上記の中から数字を選択してください：");
    scanf("%d",&s);
    if(s == 1){
      rule();//ルールを表示する関数
    }else if(s == 2){
      game_start();
    }
  }
  return 0;
}
