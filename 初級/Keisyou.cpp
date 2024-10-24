#include <iostream>
#include <stdio.h>
#include <iomanip>
// 継承もしたい！！
// 継承とは、、クラスを続けて使いまわすこと//継承するときに付け足すことはできるが引けない　←　なぜか、元のクラスが書き換えられるとどこがまちがっているのかわかりずらいから
// 良い点　関係の深いクラスを効率よく作れる(ROSで使う)

// 基本クラス→派生クラス

class Oyaclass // これを基本クラスとする
{
private:
    int num;

public:
    void show()
    {
        std::cout << num << "\n";
    }

    void Setnum(int x)
    {
        num = x;
        std::cout << "渡された引数は" << x << "\n";
    }

    int Getnum()
    {
        return num;
    }
    Oyaclass()
    {
        std::cout << "親のコンスト\n"; // コンストラクタは継承されないが呼び出しはできる　。
    } //                             なぜか、コンストラクタ名が違うのでコンストラクトできないが初期化はしたいから
};
// 　　　　　　↓「:」が継承の証
class Koclass : public Oyaclass
{ // 　　　　　　　　↑ここのタイプによって基本クラスのメンバの扱い方が決まる(何もなしだとprivate扱いになる)(publicにしとけばそのまま継承できる)

    // 中に何もなくともこの中には基本クラスと同じメンバがいる

public:
    int sinnka;
    Koclass()
    {
        std::cout << "このこんすと\n";
    };
};
// 指定するコンストラクタの呼び出し
class Oya2class
{
public:
    Oya2class()
    {
        std::cout << "NotHikis\n";
    };
    Oya2class(int x)
    {
        std::cout << x << "::YesHikis\n";
    }; // 二つのコンストラクタがある
};

class Ko2class : public Oya2class
{
public:
    Ko2class() : Oya2class(10) {}; // 引数をつけることでOya2classの中の引数のあるコンストラクタを呼び出せる
};

int main()
{
    Koclass obj;

    obj.Setnum(1185);
    obj.show(); // これにより派生クラスがしっかりとメンバを受け継いでいるのがわかる

    obj.sinnka = 1192;
    std::cout << obj.sinnka << "\n"; // ここから派生クラスのみに付け加えた変数も使えることがわかる

    Ko2class A;

    return 0;
}
