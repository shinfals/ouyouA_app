#define MAP_WIDTH 5
#define MAP_HEIGHT 5
#define ROOM_WIDTH 16
#define ROOM_HEIGHT 7

void game_start(Prince prince,int end_flag){

  int count = 0;
  int map[MAP_WIDTH][MAP_HEIGHT] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
  };
  char draw_map[ROOM_HEIGHT][ROOM_WIDTH] = {
    "***************",
    "*             *",
    "*             *",
    "*             *",
    "*             *",
    "*             *",
    "***************"
  };
  char draw_hidden[ROOM_HEIGHT][ROOM_WIDTH] = {
    "               ",
    "               ",
    "               ",
    "               ",
    "               ",
    "               ",
    "               "
  };

  for(;;){
    map[prince.y][prince.x] = 1;
    for(int h = 0; h < MAP_HEIGHT; h++){
      for(int i = 0; i < ROOM_HEIGHT; i++){
        for(int j = 0; j < MAP_WIDTH; j++){
          if(map[h][j] == 0){
            printf("%s   ",draw_hidden[i]);
          }else{
            if(h == prince.y && j == prince.x){
              draw_map[3][7] = 'P';
            }else{
              draw_map[3][7] = ' ';
            }
            printf("%s   ",draw_map[i]);
          }
        }
        printf("\n");
        count++;
        if(count%ROOM_HEIGHT == 0){
          printf("\n");
        }
      }
      printf("\n");
    }
    for(;;){
      char dir;
      int flag;
      printf("移動する方向をWASDで選択してください\n");
      printf("(/*ゲームを途中で終える際には「/」を入力してください*/):");
      scanf("%c",&dir);
      if(dir == '\n'){
        scanf("%c",&dir);
      }
      switch(dir){
        case 'w':
        case 'W':
          if(prince.y == 0){
            printf("これより上には進めません\n");
            flag = 0;
          }else{
            prince.y--;
            flag = 1;
          }
          break;
        case 'a':
        case 'A':
          if(prince.x == 0){
            printf("これより左には進めません\n");
            flag = 0;
          }else{
            prince.x--;
            flag = 1;
          }
          break;
        case 's':
        case 'S':
          if(prince.y == 4){
            printf("これより下には進めません\n");
            flag = 0;
          }else{
            prince.y++;
            flag = 1;
          }
          break;
        case 'd':
        case 'D':
          if(prince.x == 4){
            printf("これより右には進めません\n");
            flag = 0;
          }else{
            prince.x++;
            flag = 1;
          }
          break;
        case '/':
          flag = 1;
          end_flag = 1;
          break;
        default:
          printf("WASDで入力してください\n");
          flag = 0;
          break;
      }
      if(flag){
        break;
      }else{
        continue;
      }
    }
    //system("clear");
    //windowsの場合は下記を使用
    system("cls");
    if(end_flag){
      break;
    }
  }
}
