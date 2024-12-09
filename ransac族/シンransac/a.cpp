
#include <iostream>
#include <vector>
#include <random>
#include "sbb.cpp"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main()
{
   pointsProcess cloud{20, 750}; // 線,点の数を宣言

   cloud.make_points_cloud();  // 点群を作成
   cloud.draw_points_cloud();  // 描写
   cloud.ransac(100, 0.5, 40); // ransacの使用
   cloud.draw_ransac_lines();  // 描写

   plt::xlabel("X");
   plt::ylabel("Y");
   plt::show();

   return 0;
}