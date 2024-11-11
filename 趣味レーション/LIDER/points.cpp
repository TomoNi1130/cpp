// 自作rviz (ランダムな場所に点を打つだけ)

// 実行方法ーー
/*
build内でターミナルを開く
cmake ..(初回のみ)
make
./plt
*/
// ーーー
#include <iostream>
#include <random>
#include <vector>
#include <cmath>

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

const int points_number = 100;
const double pi = 3.14159;

void length_to_points(double *x, double *y, const double length, const int number)
{
   double tani = 1.5 * pi / points_number;
   double theta = number * tani - pi / 4;
   *x = cos(theta) * length;
   *y = sin(theta) * length;
};

int main()
{
   std::random_device rnd;
   std::mt19937 mt(rnd());

   std::uniform_real_distribution<double> dist(0.1f, 3.0f);

   std::vector<double> x(points_number), y(points_number), length(points_number);

   for (int i = 0; i < points_number; ++i)
   {
      length[i] = dist(mt);
   }

   for (int i = 0; i < length.size(); ++i)
   {
      length_to_points(&x[i], &y[i], length[i], i);
   }

   std::vector<double> x_line_x(2), x_line_y(2), y_line_x(2), y_line_y(2);

   for (int i = 0; i < 2; ++i)
   {
      x_line_x[i] = -6 * i + 3;
      x_line_y[i] = 0;
   }
   for (int i = 0; i < 2; ++i)
   {
      y_line_x[i] = 0;
      y_line_y[i] = -6 * i + 3;
   }

   plt::plot(x_line_x, x_line_y);
   plt::plot(y_line_x, y_line_y);

   plt::scatter(x, y);

   plt::xlabel("X");
   plt::ylabel("Y");
   plt::show();

   return 0;
}