#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

void hello() // 戻り値:なし　関数名:hello　引数:なし
{
    cout << "Hello World";
}
// これ仮引数↓
void nibai(int x) // 戻り値:なし　関数名:hello　引数:あり
{
    cout << x * 2 << "\n";
}

void tasu(int x, int y) // 戻り値:なし　関数名:tasu　引数:二つ
{
    int goukei;
    goukei = x + y;
    cout << goukei << "\n";
}

int tasu2(int a) // 戻り値:あり　関数名:tasu2　引数:あり
{
    int goukei = a * 200;
    return goukei;
}

void evening(); // プロトタイプ宣言(変数を一覧にできてキレイ)

int main() // メイン関数の下に作ると変数が認知されない(プロトタイプ宣言すればできる)
{
    hello();
    hello();
    hello();
    hello();
    hello(); // 関数の呼び出し

    evening();

    int num;
    cout << "\n二倍したい数";
    cin >> num;
    nibai(num);

    int t;
    int r;
    cout << "\n足される数";
    cin >> t;
    cout << "足す数";
    cin >> r;
    tasu(t, r);

    int apple;
    cout << "リンゴの個数";
    cin >> apple;
    int judge = tasu2(apple); // 変数の戻り値の利用
    if (judge > 4000)
    {
        cout << "予算外です";
    }
    else
    {
        cout << "予算内です";
    }

    return 0;
}

void evening()
{
    cout << "good evening";
}