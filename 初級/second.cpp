#include <iostream>
#include <stdio.h>
using namespace std;
int main() // 分岐処理群
{
    int x;

    if (10) // 数値のみの場合は０or０でないかで決まる。
        cout << "zikkou sareru\n";
    if (0)
        cout << "Not zikkou\n";

    // 等値:関係演算子
    cout << "Kazu Tokutei game\n";
    cout << "NyuuRyoku";
    cin >> x;
    if (x == 10)
        cout << "oK\n";
    if (x != 10)
        cout << "NoToK\n";
    if (x > 10)
        cout << "OOsugi\n"
             << "\n";
    if (x < 10)
        cout << "SukunaSugi\n"
             << "\n";

    int num;
    cout << "NyuuryokuSiro";
    cin >> num;
    if (num >= 5 && num <= 10)
    { // 論理演算子(ほかにも　||　と　!　でもできる。)意味は調べろ
        cout << "Naka\n";
    }
    else
    {
        cout << "sOtO\n";
    }

    int s;
    cout << "BanngouWoNyuuryokuSiro";
    cin >> s;
    switch (s)
    {
    case 1: // スイッチ文(ケースの後はコロン)
        cout << "hally\n";
        break;
    case 2:
        cout << "Ron\n";
        break;
    default:
        cout << "Bol";
        break;
    }

    return 0;
}