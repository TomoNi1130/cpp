#include <iostream>
#include <random>
#include <vector>
#include <cmath>

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

const int points_number = 75.0;

void drow_axes(int x) // 座標軸を書く用の関数
{
   int number = 2 * x + 1;
   std::vector<double> x_x_line(number), y_x_line(number), x_y_line(number), y_y_line(number);
   int a = -x;
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

void make_points(std::vector<double> &x, std::vector<double> &y)
{
   std::random_device rnd;
   std::mt19937 mt(rnd());
   std::normal_distribution<double> dist(0.0f, 3.0f);

   for (int i = 0; i < x.size(); i++)
   {
      x[i] = i - points_number / 2;
      y[i] = x[i] + 10.0;

      x[i] += dist(mt);
   }
}

double average(std::vector<double> &f, int N)
{
   double ave = 0.0;

   for (int i = 0; i < N; i++)
      ave += f[i] / (double)N;

   return ave;
}

double average_2char(std::vector<double> &f, std::vector<double> &f2, int N)
{
   double ave2c = 0.0;

   for (int i = 0; i < N; i++)
      ave2c = f[i] * f2[i] / (double)N;

   return ave2c;
}

void saisyou(std::vector<double> &x, std::vector<double> &y, const int points_number, double &a, double &b)
{
   double ave_x = average(x, points_number);
   double ave_y = average(y, points_number);
   double ave_xy = average_2char(x, y, points_number);
   double ave_xx = average_2char(x, x, points_number);

   a = (ave_xy - (ave_x * ave_y)) / ave_xx - (ave_x * ave_x);
   b = -((ave_xy - (ave_x * ave_y)) / ave_xx - (ave_x * ave_x)) * ave_x + ave_y;
}

int main()
{
   std::vector<double> x(points_number), y(points_number);
   std::vector<double> x_gess(points_number), y_gess(points_number);
   make_points(x, y);
   drow_axes(points_number);
   plt::scatter(x, y);
   double a, b;
   saisyou(x, y, points_number, a, b);
   std::cout << a << std::endl;
   std::cout << b << std::endl;
   for (int i = 0; i < points_number; i++)
   {
      x_gess[i] = i - points_number / 2.0;
      y_gess[i] = a * x_gess[i] + b;
   }

   plt::plot(x_gess, y_gess);
   plt::xlabel("X");
   plt::ylabel("Y");

   plt::show();
}