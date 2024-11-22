// ここにすべての点の座標を表現するための型を作る
#include <iostream>
#include <vector>
#include <random>
#include <vector>

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int points_number = 750;

struct line
{
   double slope, intercept;
};

void drow_axes(int x) // 座標軸を書く用の関数
{
   int number = 1 * x + 1;
   std::vector<double> x_x_line(number), y_x_line(number), x_y_line(number), y_y_line(number);
   int a = -0.5 * x;
   for (int i = 0; i < number; i++)
   {
      x_x_line[i] = a;
      y_x_line[i] = 0;
      x_y_line[i] = 0;
      y_y_line[i] = a;
      a += 1;
   }
   plt::plot(x_x_line, y_x_line);
   plt::plot(x_y_line, y_y_line);
}

void drow_function(line line) // 一次関数のグラフを書く関数
{
   std::vector<double> x_gess(points_number), y_gess(points_number);

   for (int i = 0; i < points_number; i++)
   {
      x_gess[i] = i - points_number / 2.0;
      y_gess[i] = line.slope * x_gess[i] + line.intercept;
   }
   plt::plot(x_gess, y_gess, "r-");
}

void make_random_points(line line, double amplitude, std::vector<double> &_x, std::vector<double> &_y, std::vector<bool> &inliers) // amplitude = 振れ幅
{
   std::random_device rnd;
   std::mt19937 mt(rnd());
   std::normal_distribution<double> dist(0.0f, amplitude);

   for (int i = 0; i < points_number; i++)
   {
      _x.emplace_back(i - points_number / 2);
      _y.emplace_back(line.slope * (i - points_number / 2) + line.intercept + dist(mt));
      inliers.emplace_back(false);
   }
}

void make_outliners(std::vector<double> &y, const int outliers_number)
{
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<int> dis(0, points_number);
   std::random_device md;
   std::mt19937 ra(md());
   std::uniform_int_distribution<int> dist(0, y.size());
   for (int i = 0; i < outliers_number; i++)
   {
      y[dist(ra)] = points_number / 2 - dis(gen);
   }
}

line ransac(std::vector<double> &_x, std::vector<double> &_y);