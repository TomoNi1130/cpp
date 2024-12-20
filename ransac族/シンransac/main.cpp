
#include <iostream>
#include <vector>
#include <random>
#include "sbb.cpp"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int all_points_number = 750;
int line_num = 1;

int main()
{
   while (1)
   {
      plt::clf(); // 現在のプロットをクリア
      std::vector<double> x, y;

      std::random_device rad;
      std::mt19937 random(rad());
      std::uniform_real_distribution<double> dist(-0.05f, 0.05f);

      // x.resize(all_points_number);
      // y.resize(all_points_number);
      for (int i = 0; i < all_points_number; i++)
      {
         x.push_back((5.0 / (double)all_points_number) * (double)i + dist(random) - 2.0);
         y.push_back(x[i] * (2.0 / 3.0) + dist(random) - 1.0);
      }
      pointsProcess cloud{x, y}; // コンストラクタと同時に線の数を宣言
      drow_axes(5);              // 座標軸を描写
      plt::scatter(x, y);

      cloud.ransac(1, 300, 0.05, 100); // ransacの使用//引数は，試行回数，闘値，最低inlier
      // cloud.draw_ransac_lines();   // 描写

      plt::xlabel("X");
      plt::ylabel("Y");
      plt::pause(0.01); // 少し待つ
   }
   plt::show();
   return 0;
}