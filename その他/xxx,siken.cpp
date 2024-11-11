#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
// 先輩に作ってみろと言われたもの
// 内容　関数の引数として構造体を入れるーー＞擬似クラスを作る
// Object.cppと同じ結果のコードを書く

struct Student // 構造体
{
public:
    int num;
    int year;
};
// 　　　　　↓構造体はデータ型の一種なので、実体を作る必要がある
//           ↓const とはその後ろにある変数を変化しないようにするためのもの
//                      ↓&を使うことで代入を行わずに持ってくることができる＜－－軽くなるらしい
void show(const Student &x) // 関数
{
    cout << "番号:" << x.num << "\n";
    cout << "年齢:" << x.year << "\n";
}

int main()
{
    struct Student Tanaka = {10, 15};
    // 　　　　↓ここは型番
    show(Tanaka);

    int arr[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 25;

    for (int i = 0; i <= 100; ++i)
    {
        arr[i];
    }

    return 0;
}
