#include <stdio.h>

struct Fruits
{
    int apple;
    int orange;
    int banana;
}; // ここのセミコロン忘れるな　あの時の自分へ

void price(struct Fruits store1); // プロトタイプ宣言

int main(void)
{
    struct Fruits store1 = {100, 200, 250}; // なんかバグるんだが
    struct Fruits store2 = {200, 400, 500};
    struct Fruits store3;

    store1 = store3; // 構造体への代入

    printf("store1\n");
    price(store1);

    printf("store2\n");
    printf("リンゴの値段：%d\n", store2.apple);
    printf("オレンジの値段：%d\n", store2.orange); // ぜったいもっとよくできるーーー
    printf("バナナの値段：%d\n", store2.banana);

    printf("store3\n");
    printf("リンゴの値段：%d\n", store3.apple);
    printf("オレンジの値段：%d\n", store3.orange);
    printf("バナナの値段：%d\n", store3.banana);

    return 0;
}

void price(struct Fruits store1)
{
    printf("リンゴの値段：%d\n", store1.apple);
    printf("オレンジの値段：%d\n", store1.orange);
    printf("バナナの値段：%d\n", store1.banana);

    return;
}