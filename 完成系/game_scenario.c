﻿#include <stdio.h>
#include "func.h"
#include <unistd.h>

void game_scenario(){
  int secound=2;
  int slow=15;
  int Vslow=20;
  printf("主人公は大国の王子であり、ルックス最強・性格も最強の完璧超人である。\n");
  printf("そのため、他国の姫達から求婚をされることも日常茶飯事である。\n");
  printf("しかし王子には心に決めた人である幼馴染がいるため、これらの求婚をいつも拒否していた。\n");
  sleep(slow);
  printf("あのような悲劇が起こるとも知らずに．．．\n");
  sleep(secound);
  printf("次の日、いつも通りの暮らしをしていた王子だが、他国の姫たちが王子を殺すために城に押し寄せてきたと知らせを受けるのだった。\n");
  printf("求婚を拒否した姫達から命からがら逃げた王子だが逃げ込んだ先は・・・\n");
  sleep(slow);
  printf("なんとダンジョンだった！？\n");
  sleep(secound);
  printf("さて、王子は追ってきた姫が蔓延るダンジョンから抜け出し、幼馴染と結婚することができるのでしょうか．．．\n");
  printf("----------------------------------------------------------------------\n");
}