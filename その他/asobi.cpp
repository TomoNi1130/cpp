#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

// 入力した数で累乗の計算ができるマシン
long zyou(long num, int com)
{
    long pre_num = num;
    for (int i = 0; i < com; i++)
    {
        num *= pre_num;
    }
    return num;
}

int main()
{
    int num;
    int copy;
    cout << "objectNumber:\n";
    cin >> num;
    cout << "count:\n";
    cin >> copy;
    long Hairetu[copy];
    for (int i = 0; i < copy; i++)
    {
        Hairetu[i] = zyou(num, i);
    }

    for (int i = 0; i < copy; i++)
    {
        printf("%d-->%d\n", i + 1, Hairetu[i]);
    }
}