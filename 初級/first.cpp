#include <iostream>
#include <stdio.h>
using namespace std;

int main() // 順次処理
{
    // ストリーム群
    cout << "ストリーム\n";
    cout << "yokuyatta\n";

    cout << "こんにちは";
    cout << 1000 << "円あげる\n"; // std::coutを省略している
    cout << 10 + 5 << "\n";
    cout << 10 - 5 << "\n";
    cout << 10 * 5 << "\n";
    cout << 10 / 5 << "\n";
    // 変数群
    cout << "変数\n";
    int r;
    r = 3;                        // 半径
    cout << r * r * 3.14 << "\n"; // 円の面積

    int apple = 10; //<<初期化　　｛int は　整数型(４バイト)｝
    apple += 5;     // 複合演算代入子

    int value;
    value = 100;
    cout << value << "\n";

    double pi; // double　は　少数型(８バイト)
    pi = 3.1415;
    cout << (int)pi << "\n"; // キャスト(型を変換する)

    int x = 10;
    int y = 10;
    x++;
    y++;
    cout << "xの値:" << x;
    cout << "yの値:" << y << "/n";

    const int teisuu = 10; // コンスト定数(決まった変数、後から変更できない)
    cout << teisuu << "\n";
    // 入力するぞ！！
    cout << "数を入力してください\n";
    int nyuuryoku;
    cin >> nyuuryoku; // c"out"とc"in" 矢印は逆
    cout << "入力された数:" << nyuuryoku << "\n";

    return 0;
}