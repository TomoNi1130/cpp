
#include <iostream>
#include <vector>
#include <random>
#include "sbb.cpp"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main()
{
   pointsProcess cloud{1, 750}; // 線,点の数を宣言

   std::vector<double> x, y;

   make_points_cloud(x, y, 750);
   cloud.set_points_cloud(x, y);
   cloud.draw_points_cloud();
   cloud.ransac(50, 0.5);

   plt::xlabel("X");
   plt::ylabel("Y");
   plt::show();

   return 0;
}