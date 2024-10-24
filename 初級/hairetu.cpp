#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

int stuNum;

int main()
{
    int array[3]; // 先に配列を宣言してからする方法　一つ一つ入れていかなくちゃならない
    array[0] = 10;
    array[1] = 20;
    array[2] = 30;
    cout << array[0] << "\n";
    cout << array[1] << "\n";
    cout << array[2] << "\n";

    int hairetu[3] = {1, 2, 3}; // 配列の宣言と同時に値を入れる方法
    cout << hairetu[0] << "\n";
    cout << hairetu[1] << "\n";
    cout << hairetu[2] << "\n";

    int syou[] = {11, 22, 33}; // 要素数を省略
    cout << syou[0] << "\n";
    cout << syou[1] << "\n";
    cout << syou[2] << "\n";

    int ifu[5] = {10, 20, 30, 40, 50}; // 配列とfor文の融合
    int i;
    for (i = 0; i < 5; i++)
    {
        cout << i << "番目:" << ifu[i] << "\n";
    }

    int num;
    int nyuuryoku[num];
    int x;
    cout << "要素数は\n";
    cin >> num;
    for (x = 0; x < num; x++)
    {
        cout << x + 1 << "番目の要素の値は？\n";
        cin >> nyuuryoku[x];
    }
    for (x = 0; x < num; x++)
    {
        cout << x + 1 << "番目:" << nyuuryoku[x] << "\n";
    }
    // 生徒全員の平均点出し機

    cout << "生徒の総数:";
    cin >> stuNum;
    
    int stuPoint[stuNum];
    int goukei=0;

    for (int y = 0; y < stuNum; y++)
    {
        cout << y + 1 << "人目の成績は";
        cin >> stuPoint[y];
    }
    for (int y = 0; y < stuNum; y++)
    {
        goukei = goukei+stuPoint[y];
    }
    cout << "平均点は"<<goukei/stuNum<<"点\n";
    return 0;
}