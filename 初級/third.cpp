#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
int main() // 繰り返し処理
{
    int i;
    for (i = 0; i < 5; i++)
    {
        cout << i + 1 << "回目のyouyatta\n";
    }

    int tate;
    int yoko;
    for (tate = 1; tate <= 9; tate++)
    {
        cout << tate << "の段\n";
        for (yoko = 1; yoko <= 9; yoko++)
        {
            cout << setw(3) << tate * yoko; // セットワードは字間を開ける　iomanip　をインクルード
        }
        cout << "\n";
    }

    int a = 1;
    int count = 0;
    while (a < 1000)
    {
        a = a * 2; // この式は　a*=2　でもいい
        count++;
        cout << count << "回目:" << a << "\n";
    }
    cout << count << "回目で千を越えます\n";

    do
    { // do while　構文は　do部分　が一度実行されるwhile文
        cout << "とりあえず言っとくか\n";
    } while (a == 1000);
    while (a == 1000)
    {
        cout << "言わん\n";
    }

    return 0;
}