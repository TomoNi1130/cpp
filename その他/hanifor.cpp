#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <array>

// 範囲for文について書く
int main()
{
   std::array<int, 5> array = {0, 6, 5, 8, 4};
   for (const auto &e : array) // ここが範囲for文
   {
      std::cout << e << std::endl;
   }
}