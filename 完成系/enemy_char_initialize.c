#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

 void enemy_char_initialize(Princess_enemy *pPriE,Princess_support *pPriS){
   int hp=0;//モブHPの入れ物
   int at=0;//モブATKの入れ物
   int df=0;//モブDEFの入れ物
   int sp=0;//モブSPDの入れ物
   srand((unsigned)time(NULL));

   hp=rand()%251+250;//モブのHP２５０〜５００でランダム
   at=rand()%151+150;//モブのATK１５０〜３００でランダム
   df=rand()%31+20;//モブのDEF２０〜５０でランダム
   sp=rand()%5+1;//モブのSPD１〜５でランダム

   pPriE[0].name="Princess";//モブ１の名前
   pPriE[0].Hp=800;//モブ１のHP
   pPriE[0].Atk=120;//モブ１のATK
   pPriE[0].Def=70;//モブ１のDEF
   pPriE[0].Spd=3;//モブ１のSPD
   pPriE[0].Skill=0;
   pPriE[0].Mp=0;


   hp=rand()%251+250;//モブのHP２５０〜５００でランダム
   at=rand()%151+150;//モブのATK１５０〜３００でランダム
   df=rand()%31+20;//モブのDEF２０〜５０でランダム
   sp=rand()%5+1;//モブのSPD１〜５でランダム

   pPriE[1].name="月姫";//モブ２の名前
   pPriE[1].Hp=hp;//モブ２のHP
   pPriE[1].Atk=at;//モブ２のATK
   pPriE[1].Def=df;//モブ２のDEF
   pPriE[1].Spd=sp;//モブ２のSPD
   pPriE[1].Skill=0;
   pPriE[1].Mp=0;


   hp=rand()%251+250;//モブのHP２５０〜５００でランダム
   at=rand()%151+150;//モブのATK１５０〜３００でランダム
   df=rand()%31+20;//モブのDEF２０〜５０でランダム
   sp=rand()%5+1;//モブのSPD１〜５でランダム

   pPriE[2].name="亀姫";//モブ３の名前
   pPriE[2].Hp=hp;//モブ３のHP
   pPriE[2].Atk=at;//モブ３のATK
   pPriE[2].Def=df;//モブ３のDEF
   pPriE[2].Spd=sp;//モブ３のSPD
   pPriE[2].Mp=0;
   pPriE[2].Skill=0;


   hp=rand()%251+250;//モブのHP２５０〜５００でランダム
   at=rand()%151+150;//モブのATK１５０〜３００でランダム
   df=rand()%31+20;//モブのDEF２０〜５０でランダム
   sp=rand()%5+1;//モブのSPD１〜５でランダム

   pPriE[3].name="星姫";//モブ４の名前
   pPriE[3].Hp=hp;//モブ４のHP
   pPriE[3].Atk=at;//モブ４のATK
   pPriE[3].Def=df;//モブ４のDEF
   pPriE[3].Spd=sp;//モブ４のSPD
   pPriE[3].Mp=0;
   pPriE[3].Skill=0;


   pPriS[0].Hp=0;//味方がいない場合に使う
   pPriS[0].Atk=0;//
   pPriS[0].Def=0;//

   pPriS[1].Hp=pPriE[0].Hp;//モブ１を仲間にした時
   pPriS[1].Atk=pPriE[0].Atk;//数値はモブ１から引用
   pPriS[1].Def=pPriE[0].Def;//

   pPriS[2].Hp=pPriE[1].Hp;//モブ２を仲間にした時
   pPriS[2].Atk=pPriE[1].Atk;//数値はモブ２から引用
   pPriS[2].Def=pPriE[1].Def;//

   pPriS[3].Hp=pPriE[2].Hp;//モブ３を仲間にした時
   pPriS[3].Atk=pPriE[2].Atk;//数値はモブ３から引用
   pPriS[3].Def=pPriE[2].Def;//

   pPriS[4].Hp=pPriE[3].Hp;//モブ４を仲間にした時
   pPriS[4].Atk=pPriE[3].Atk;//数値はモブ４を引用
   pPriS[4].Def=pPriE[3].Def;//

   int Mhp;//中ボスHPの入れ物
   int Mat;//中ボスATKの入れ物
   int Mdf;//中ボスDEFの入れ物
   int Msp;//中ボスSPDの入れ物

   Mhp=rand()%701+700;//中ボスのHP７００〜１４００でランダム
   Mat=rand()%151+200;//中ボスのATK２００〜３５０でランダム
   Mdf=rand()%41+35;//中ボスのDEF３５〜７５でランダム
   Msp=rand()%5+1;//中ボスのSPD１〜５でランダム

   pPriE[4].name="魚姫";//中ボス１の名前
   pPriE[4].Hp=Mhp;//中ボス１のHP
   pPriE[4].Mp=3;//中ボス１のMP
   pPriE[4].Atk=Mat;//中ボス１のATK
   pPriE[4].Def=Mdf;//中ボス１のDEF
   pPriE[4].Spd=Msp;//中ボス１のSPD
   pPriE[4].Skill=1;//中ボス１のスキル

   Mhp=rand()%701+700;//中ボスのHP７００〜１４００でランダム
   Mat=rand()%151+200;//中ボスのATK２００〜３５０でランダム
   Mdf=rand()%41+35;//中ボスのDEF３５〜７５でランダム
   Msp=rand()%5+1;//中ボスのSPD１〜５でランダム

   pPriE[5].name="桃姫";//中ボス２の名前
   pPriE[5].Hp=Mhp;//中ボス２のHP
   pPriE[5].Mp=3;//中ボス２のMP
   pPriE[5].Atk=Mat;//中ボス２のATK
   pPriE[5].Def=Mdf;//中ボス２のDEF
   pPriE[5].Spd=Msp;//中ボス２のSPD
   pPriE[5].Skill=2;//中ボス２のスキル

   Mhp=rand()%701+700;//中ボスのHP７００〜１４００でランダム
   Mat=rand()%151+200;//中ボスのATK２００〜３５０でランダム
   Mdf=rand()%41+35;//中ボスのDEF３５〜７５でランダム
   Msp=rand()%5+1;//中ボスのSPD１〜５でランダム

   pPriE[6].name="雪姫";//中ボス３の名前
   pPriE[6].Hp=Mhp;//中ボス３のHP
   pPriE[6].Mp=3;//中ボス３のMP
   pPriE[6].Atk=Mat;//中ボス３のATK
   pPriE[6].Def=Mdf;//中ボス３のDEF
   pPriE[6].Spd=Msp;//中ボス３のSPD
   pPriE[6].Skill=3;//中ボス３のスキル

   pPriS[5].Hp=pPriE[4].Hp;//中ボス１を仲間にした時
   pPriS[5].Atk=pPriE[4].Atk;//数値は中ボス１を引用
   pPriS[5].Def=pPriE[4].Def;//

   pPriS[6].Hp=pPriE[5].Hp;//中ボス２を仲間にした時
   pPriS[6].Atk=pPriE[5].Atk;//数値は中ボス２を引用
   pPriS[6].Def=pPriE[5].Def;//

   pPriS[7].Hp=pPriE[6].Hp;//中ボス３を仲間にした時
   pPriS[7].Atk=pPriE[6].Atk;//数値は中ボス３を引用
   pPriS[7].Def=pPriE[6].Def;//

   pPriE[7].name="極姫";//ラスボスの名前
   pPriE[7].Hp=3500;//ラスボスのHP
   pPriE[7].Mp=3;//ラスボスのMP
   pPriE[7].Atk=500;//ラスボスのATK
   pPriE[7].Def=0;//ラスボスのDEF
   pPriE[7].Spd=5;//ラスボスのSPD
   pPriE[7].Skill=4;//ラスボスのスキル

}
