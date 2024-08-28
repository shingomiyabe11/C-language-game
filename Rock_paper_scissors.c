/* じゃんけんゲーム */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct {
    char *name;
    int  wincount;
} pc, user;


char* show_hand(int hd_num) {
    char *hd_name[] = {"グー", "チョキ", "パー"};
    return hd_name[hd_num - 1];
}

/* じゃんけんの対戦結果 */
void judge(int cp_hand, int hand) {
    printf("%s　対　%s で　", show_hand(cp_hand), show_hand(hand));
    if (cp_hand == hand) {
        printf("引き分けです。\n");
        return;
    }
    if ((3 + cp_hand - hand) % 3 == 2) {
        printf("%s", pc.name);
        pc.wincount++;
    } else {
        printf("%s", user.name);
        user.wincount++;
    }
    printf("の勝ちです。\n");
}

void game(int n) {
    char a[20];
    int  hand, cp_hand;
    
    printf("*** %d回戦 ***\n", n);
    
    do {
        printf("%sの手を入力して下さい（1:グー, 2:チョキ, 3:パー）：", user.name);
        scanf( "%s", a);
        if (!strcmp(a, "1") || !strcmp(a, "2") || !strcmp(a, "3")) hand = atoi(a);
        else hand = 0;
    } while (!hand);
    /* 1から3の乱数 */
    cp_hand = rand() % 3 + 1;
    
    judge(cp_hand, hand);
}

void final_winner() {
    /* 最終結果を表示する */
    printf("\n*** 最終結果 ***\n");
    printf("%d 対 %d で　", pc.wincount, user.wincount);
    if (pc.wincount == user.wincount) {
        printf("引き分けです。\n");
        return;
    }
    if (pc.wincount > user.wincount) printf("%s", pc.name);
    else printf("%s", user.name);
    printf("の勝ちです。\n");
}

int main() {
    /* 乱数のシードを time で与える */
    srand((unsigned)time(NULL));
    
    pc.wincount   = 0;
    user.wincount = 0;
    
    pc.name = "Computer";
    
    /* 最大30字の文字数が表示可能 */
    char st[30];
    /* ユーザ名を入力する */
    printf("あなたの名前を入力して下さい：");
    scanf("%s", st);
    user.name = st;
    printf("%s　対　%s　：じゃんけん開始\n\n", pc.name, user.name);
    
    for (int n = 1; n <= 5; n++) game(n);
    
    final_winner();
    
    return 0;
}