#include <stdio.h>

struct Test
{
    char name[128];
    int Japanese;
    int Math;
    int English;
};

typedef struct
{
    // なんかいろいろ
} Fruits; // こうすることで　Fruits store; のみでよくなる struct Fruits store;　でなくね

void line(void); // 線を引く

void show(void); // 名前　成績を出力する

struct Test student[3] = {
    {"太郎", 40, 50, 60},
    {"次郎", 20, 15, 27},
    {"三郎", 95, 89, 100},
}; // 今回は三人なので三個分Testのデータ型を作る

int main(void)
{ // 表を作ろう
    printf("%10s%10s%10s%10s\n", "名前", "国語", "数学", "英語");
    line();
    show();

    typedef unsigned int seinokazu; // 符号なし　つまり正の数限定//関数の名前を変更
    seinokazu number = 15;
    printf("%d", number);

    return 0;
}

void line(void)
{
    for (int i = 0; i < 50; i++)
    {
        printf("_");
    }
    printf("\n");

    return;
}

void show(void)
{

    for (int i = 0; i < 3; i++)
    {
        printf(" %8d %8d %8d %8d\n",
               student[i].name, student[i].Japanese, student[i].Math, student[i].English);
    }
    return;
}
