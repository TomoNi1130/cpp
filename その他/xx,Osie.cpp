#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
// 先輩からの教え

class Student // 構造体
{
public:
    int num;
    int year;

    void show() const // 関数
    {
        cout << "番号:" << num << "\n";
        cout << "年齢:" << year << "\n";
    }
    void show2(const Student &x) const // 関数
    {
        cout << "番号:" << num << "\n";
        cout << "年齢:" << year << "\n";
        cout << "番号:" << x.num << "\n";
        cout << "年齢:" << x.year << "\n";
    }
};

class Teacher
{
};

class Class
{
    Teacher tea;
    Student stu[20];

    void do_class()
    {
        int iq = tea.get_iq();
        for (int i = 0; i < 20; ++i)
        {
            stu[i].up_iq(iq);
        }
    }
}

class Motor;
class Omni
{
    Motor motor[3];

    void move(x, y, rotate)
    {
        motor[0].power(x);
        motor[1].power(y);
        motor[2].power(rotate);
    }
}

int
main()
{
    Student Tanaka = {10, 15};
    Student Suzuki = {};

    tanaka.show();
    tanaka.show2(Suzuki);

    Suzuki.show();

    Omni omni = {};

    omni.move(100, 1, -10);

    return 0;
}
