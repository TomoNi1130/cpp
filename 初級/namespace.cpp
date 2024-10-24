#include <iostream>
#include <cmath>
// std::sinは360度表記では使えない
namespace unstd
{
    float sin(int deg)
    {                                   // unstd名前空間のsin関数
        float red = deg * M_PI / 180.0; // 360度表記を弧度法ラジアンに直した
        return std::sin(red);
    }
}

int main()
{
    // std::cout <<std::sin(30)←これでは使えない
    std::cout << unstd::sin(30) << "\n";
    return 0;
}