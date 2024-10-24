// いつまでc言語やねーーｎ
#include <stdio.h>

// 座学ターイム
// データ型とはーー＞実体(データや文字列)がなく、役割を指定するだけ
// ユーザー定義型のデータ型ーー＞これから使うデータ型を自由に作れる！！
// 　　　　　　　　　　　↓
// 　　　　　　　　　　構造体
// 構造体を作るには３っつのステップが
// 1　どんなデータを扱うかを決める　　　(intの部分と同じ)
// 2　実体のあるデータを入れていく　　　(int number; と同じ)
// 3　数値を格納する

//       ↓データではない
struct Student
{              // 　this is 構造体
     int year; // このようなメンバ関数の宣言をフィールド宣言という
     // 　　int や char の中身を決めているのと一緒<-この場合24バイトって、こと！？
     double weight;
     double height; // doubleは浮動小数点数型の８バイト
};

struct alpha
{
     int kazu;
     char mozi[]; // mozi[]の意味はcharは1バイトのデータしか入らないため配列にして対応している
} A, B;           // こうすることで簡単にメンバーを増やせるｖ

struct Al
{
     int kazu;
     char mozi[];
}; // 実はここが書かれているとこの構造体は　C D G に使うことがわかるので変数名はいらない(しかし後から変数を宣言することができない)

int main(void)
// 構造体を使っていく
{
     struct Student Nande;
     Nande.year = 0;
     printf("%d才\n", Nande.year); // 変数名の前に　,　つけるの忘れずに
     //             ↓変数(int a;と同じ)
     struct alpha A; // 変数の宣言
     A.kazu = 10;
     printf("kazuA:%d\n", A.kazu);

     B.kazu = 20;
     printf("kazuB:%d\n", B.kazu);

     struct Al C;
     struct Al G;

     C.kazu = 10;
     printf("kazuC:%d\n", C.kazu);

     // D.mozi = "yokuyatta";
     // printf("kazuD:%s\n", D.mozi);//文字列を入力するのは難しいよ

     G.kazu = 55;
     // G.mozi = "guhehe";
     printf("kazuG:%d\n", G.kazu);
     // printf("kazuG:%s\n", G.mozi);

     return 0;
}