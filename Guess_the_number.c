/* 数当てゲーム */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
   int i, n, x, ch;
   time_t t;
   
   do {
      /* 乱数系列の初期化 */
      srand((unsigned) time(&t));
      /* 1から100の間の乱数 */
      x=rand()%100 + 1;
      printf("計算機は 1 から 100 までの整数を発生しました。\n");
      printf("この数を6回以内で当てて下さい。\n");
      for (i=1; i<=6; i++) {
           printf("%d 回目:この数はいくつでしょう？",i);
           scanf("%d",&n);
           if (n==x) {
               break;
           }
           else if(x>n) {
               printf("もっと大きい数です。\n");  
           }  
           else {
               printf("もっと小さい数です。\n");
           }
      }
      if (i<=6) {
          printf("大当たり！！！");
          printf("あなたの得点は %d 点です。\n",(11-i)*10);
      }
      else {
          printf("残念ながらはずれです。答えは %d です。\n",x);
      } 

      printf("\n続けますか(y/'n') ？");
      ch = getchar();
      ch = getchar();
   }while(ch=='y' || ch=='n' || ch=='\n');
    return 0;
}