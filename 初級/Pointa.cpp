#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;
// ポインタの存在意義
// その壱♡　ーーーーーーーーー①別々の関数からでも変数の変換ができるように　②複数の戻り値を出す場合

// C++ってゅぅのゎ。。

// 関数から複数の値を返せないのぉ。。。

// そして言語仕様も複雑。。。

// もぅﾏﾁﾞ無理ぽ。。。

// Pythonしょ。。。とならないには、しっかり勉強しようねぇ。

// その弐♡　ーーーーーーーーーー配列にアクセスする　←　配列はその先頭要素へのポインタ

// その参♡　ーーーーーーーーーーデータ構造を作るため　←　データ構造とはデータを扱いやすくするための仕組み

int apple = 10; // この値はメモリに保存される
// メモリICの仕組み
// 　on or off のどちらかを記憶できるピンがあり２^n通りのアドレスがある(詳しくは調べロ)

int *a = &apple;
// 　↑ポインタ
// 　&はその後の変数が格納されているメモリのアドレスを出す//int appleで用意されたメモリたちの中の先頭のアドレスが入っている//int* a という書き方もあるが、int *a のほうがわかりやすいと思いま

void Henkan(int x)
{
    x = 55; // ここでは確かに 引数として入った10に55が代入されているがappleに55が代入されているわけではない。それすなわちこれではmain内の変数は変えられない
}

void SinHenkan(int *x)
{
    *x = 55; // xの先に55を押し付ける
}

void Hutatu(int x, int *a, int *b)
{
    *a = x * 2; // ポインタを使うことで無理やり関数外に値を返している
    *b = x * x; // a b はポインタのため数値は入らない
}

struct kouzou
{
    char name[128];
    int nedan;
    int zaiko;
};

int main()
{
    cout << *a << "\n"; //*は「その先のもの」という意味
    cout << apple << "\n";

    // apple変数それ自体を変えてみようゾーン

    cout << apple << "\n"; // これは１０
    Henkan(apple);
    cout << apple << "\n"; // これは１０//理由　関数で仮引数に代入されているから(普段はこうなってる)
    SinHenkan(&apple);
    cout << apple << "\n"; // ここで５５にできる//理由　関数にアドレスを送って関数側がそのアドレスを使いappleのメモリを書き換えたから
    SinHenkan(a);
    cout << apple << "\n"; // ここでも　//理由　上でaに対してappleのアドレスを入れているため
    // SinHenkan(*a);
    // cout << apple << "\n";//これはだめらしい

    // 二つの引数を返してみようゾーン//二倍と二乗
    int num1 = 33;
    int nib; // 向こうで答えを格納するための箱
    int niz;
    Hutatu(num1, &nib, &niz);
    cout << "二倍:" << nib << "二乗:" << niz << "\n";

    // 構造体をポインタで指し示そう
    struct kouzou store = {"apple", 150, 10};

    struct kouzou *p = &store; // pはポインタなのでアドレスしか入らないはず、ではなぜデータ型の大きさが同じなのか。←取り出す先のデータの大きさが分らなければならないから
    cout << "名前:" << (*p).name << "\n";
    //                  ↑()がないとp.nameの先を目指すことになってしまう

    // その弐　配列へのアクセスその方法
    const char *pointa[] = {"assuma", "ichimura", "yosida"}; // それぞれの文字列が保存されているメモリの先頭メモリのアドレスがpointa配列のそれぞれに保存される//ポインタ配列
    const char **pointaMatome = pointa;                      // これで上で作ったpointa配列の先頭のメモリのアドレスをpointaMatomeに保存できる。つまりポインタのポインタにできる//ダブルポインタ
    for (int i = 0; i > 3; i++)
    {
        cout << *pointa[i] << "\n";
    }

    return 0;
}