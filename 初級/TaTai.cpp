#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
// 多態性について(たたいせいって読むんだぜ)
// 多態性とは、、同じ名前の関数で状況によって異なる処理を行えるテクニック　←　関数がわかりやすくなる(似た機能の関数をまとめられる)

// オーバーロード//引数が異なるなら関数名がかぶっていてもよい　多重主義
void nibai(int x)
{
    cout << x * 2 << "\n";
}

void nibai(double x)
{
    cout << x * 2 << "\n";
}

class Class // クラスのメンバ関数にもオーバーロードが使える
{
public:
    void hello()
    {
        cout << "こんにちは\n";
    };
    void hello(string name)
    {
        cout << name << "、さんこんにちは\n";
    };
};
// オーバーライド//継承用のやつやんけ！！

int main()
{
    nibai(22);
    nibai(3.14);

    Class Tanaka;
    Tanaka.hello("田中");

    return 0;
}