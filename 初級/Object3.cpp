#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

// 座学ターイム
// オブジェクト指向とは・・
//  A 人によって答えは様々
//
// ここではひとまず「クラスを使ったプログラムの +a」である

// その代表例が　継承　カプセル化　多態性　の三つ
// 継承は飛ばす＜－－先輩の思し召しだ受け入れろ

// しかしこれらはクラスの発展形でしかないので必要になったときに知ればいい

// このウィンドウではカプセル化をします

// カプセル化とは・・
// 必要でない内部の知識を隠しシンプルにする手法←これによりより分かりやすく簡潔にプログラムを書くことができる

// アクセス指定子とは・・
// public,private,protected　の三つのみ。それぞれどこからでも読み書きできる、そのクラス内のみ、継承したクラスでも、という意味になっている

class pri // クラスはデータ型なのでその中で変数に値を代入することはできない＜－－のでメンバ関数を使って代入する
{         // 実は業界内ではクラスは原則privateで書くことになっているらしい　理由　わかりやすいから
private:
    int num; // this is メンバ変数//この部分は変わってしまうと困るのでprivateで変更できないようにしている　privateはメンバ関数でしか変えられない

public:                 //                                                          ↓名前だけで実際はなにも変わらない
    void SetNum(int x); // this is メンバ関数//これまた実はメンバ関数にはSetとGetの役割が与えられることが多い　理由　わかりやすいから(諸説あり)
    int GetNum();       // privateのものは出力もできないらしい←コピーできないからじゃねの
};

void pri::SetNum(int x)
{
    if (x >= 3000 && x <= 100000000000000000) // こうして範囲外の値が入ることも制限できる
    {
        num = x;
        cout << "値を入れたぞ\n";
    }
    else
    {
        cout << "そんなに小さな数受け入れない\n";
    }
}

int pri::GetNum()
{
    return num;
}

int nedan = 0;

int main()
{
    char v = 101;
    while (v == 101)
    {
        cout << "このappleの値段はいかほど？\n";
        cin >> nedan;

        pri a;
        a.SetNum(nedan);

        int result = a.GetNum();

        if (result >= 3000)
        {
            cout << "ああそうだよ" << result << "円だよ！！\n";
            // cout << "ああそうだよ" << a.num << "円だよ！！\n";<--これではだめなのだらしい

            v = 102;
        }
    }
    return 0;
}
