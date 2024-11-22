#include "CoordinateUnit.cpp" //関数が入っている
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
   line second_line = {-0.5, -60.0};
   line third_line = {-1.0, 100};
   std::vector<double> points_cloud_x(points_number), points_cloud_y(points_number);
   std::vector<bool> is_inlier;
   make_random_points(first_line, 30.0, points_cloud_x, points_cloud_y, is_inlier);
   make_random_points(second_line, 30.0, points_cloud_x, points_cloud_y, is_inlier);
   make_random_points(third_line, 30.0, points_cloud_x, points_cloud_y, is_inlier);
   make_outliners(points_cloud_y, 200);
   make_outliners(points_cloud_x, 200);
   drow_axes(points_number);
   plt::scatter(points_cloud_x, points_cloud_y, 1.0);
   std::cout << "傾き(目標):" << first_line.slope << "切片(目標):" << first_line.intercept << std::endl;
   std::cout << "傾き(目標):" << second_line.slope << "切片(目標):" << second_line.intercept << std::endl;
   std::cout << "傾き(目標):" << third_line.slope << "切片(目標):" << third_line.intercept << std::endl;

   // std::cout << is_inlier.size() << std::endl;
   plt::show();
}