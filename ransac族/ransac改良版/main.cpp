#include "functions.cpp" //関数が入っている
#include "matplotlibcpp.h"

#include <iostream>
#include <vector>
#include <random>
#include <vector>

namespace plt = matplotlibcpp;

int main()
{
   // 点群描写
   line first_line = {1.0, 30.0};
   line second_line = {-0.5, -60.0}; // 傾き，切片
   line third_line = {-1.0, 100};
   std::vector<double> points_cloud_x, points_cloud_y; // 点の座標を格納する配列
                                                       // すでに直線測定に使われた点をマークするための配列
   make_random_points(first_line, 10.0, points_cloud_x, points_cloud_y);
   make_random_points(second_line, 10.0, points_cloud_x, points_cloud_y); // 上で作った直線に沿ってランダムに点を散らす
   make_random_points(third_line, 10.0, points_cloud_x, points_cloud_y);
   make_outliners(points_cloud_y, points_cloud_y.size() / 4);
   make_outliners(points_cloud_x, points_cloud_x.size() / 4);
   drow_axes(points_number);
   plt::scatter(points_cloud_x, points_cloud_y, 1.0); // 点群を描写
   std::cout << "傾き(目標1):" << first_line.slope << "切片(目標1):" << first_line.intercept << std::endl;
   std::cout << "傾き(目標2):" << second_line.slope << "切片(目標2):" << second_line.intercept << std::endl;
   std::cout << "傾き(目標3):" << third_line.slope << "切片(目標3):" << third_line.intercept << std::endl;
   std::vector<bool> is_inlier(points_cloud_x.size(), false);

   // ransac---------
   for (int i = 0; i < line_number; i++)
   {
      line gess_line = ransac(points_cloud_x, points_cloud_y, is_inlier);
      drow_function(gess_line);
      std::cout << "傾き(予測" << i + 1 << "):" << gess_line.slope << "切片(予測" << i + 1 << "):" << gess_line.intercept << std::endl;
   }
   //-------------

   plt::xlabel("X");
   plt::ylabel("Y");
   plt::show();
}