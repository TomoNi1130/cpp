
#include <iostream>
#include <vector>
#include <random>
#include "sbb.cpp"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main()
{
   pointsProcess cloud{5, 750}; // コンストラクタと同時に,線,点の数を宣言

   drow_axes(5); // 座標軸を描写

   cloud.make_points_cloud();  // 点群を作成コ
   cloud.draw_points_cloud();  // 描写
   cloud.ransac(10, 0.1, 100); // ransacの使用//引数は，試行回数，闘値，最低品質
   cloud.draw_ransac_lines();  // 描写

   plt::xlabel("X");
   plt::ylabel("Y");
   plt::show();

   return 0;
}