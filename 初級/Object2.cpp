#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

class Student
{
public: //<--これはアクセス指定子という
    int num;
    int year;
};

void show(Student x) // 構造体やクラスを引数にするときも仮引数のデータ型はそろえよう
{
    cout << "番号:" << x.num << "\n";
}

int main()
{
    Student Tanaka;           // クラスのデータ型でTanakaを作る
    Tanaka.num = 10;          // Tanakaのnumに10を入れる
    Student *p;               // pポインタの先もクラスと同じ大きさの枠で作る
    p = &Tanaka;              // pポインタにTanakaのアドレスを入れる
    cout << (*p).num << "\n"; // pの先のものの中のnumの値を出力する(こうすることで関数にいちいち代入する必要がなくなっていいらしい)

    Ful apple;
    apple.taste = 10;
    show(apple);

    return 0;
}