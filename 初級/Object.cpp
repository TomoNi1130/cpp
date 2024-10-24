-#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
// 座学ターイム
//
// データ型＞＞ユーザー定義型＞＞構造体＞＞クラス
//
// データ型は構造体と違い変数だけでなく関数をも扱える

// なぜクラスはできたのか
// 多くの関数と変数をセットで処理してわかりやすくするため

// オブジェクト指向＜－－クラスを使って効率的にプログラムを作ろう

void show();

struct K
{ // typedefにより データ型として使うときにStructがいらない//これは構造体
    int year;
    int num;
};

class Student // これこそがクラスである！！
{
public:
    int num;
    int year;
    void show();
};

void Student::show() // 　::　はスコープ解決演算子と言ってデータ型Studentの中のshow関数という意味になる
{
    cout << "番号:" << num << "\n"; // show関数の役割を決めてる(こうしなくとも直接クラスを決める際に関数の中身を決めることもできる)
    cout << "年齢:" << year << "\n";
}

class Point // ポインタも使いましょう
{
public:
    int kazu;
};

// 関数の引数として構造体を入れるとき

int main()
{
    K Tarou;
    Tarou.year = 10;

    cout << Tarou.year << "\n";

    Student Hanako;
    Hanako.num = 10;
    Hanako.year = 128;
    Hanako.show();

    Point x, *p; // ここはPointのクラスを使ってxの枠を作り、*pでアドレスを保存している
    p = &x;      // 復習　*をつけないのはpの先(この場合xになる)に代入しないようにするため//＆はそのアドレスを取り出すという意味

    (*p).kazu = 10; // ここってアドレスを使う意味ってあるの？
    cout << (*p).kazu << "\n";

    return 0;
}