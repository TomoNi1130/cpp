#include <iostream>
#include <random>
#include <vector>
#include <cmath>

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

const int points_number = 750;

void drow_function(double a, double b) // 傾きと切片から一次関数のグラフを書く
{
   std::vector<double> x_gess(points_number), y_gess(points_number);

   for (int i = 0; i < points_number; i++)
   {
      x_gess[i] = i - points_number / 2.0;
      y_gess[i] = a * x_gess[i] + b;
   }
   plt::plot(x_gess, y_gess);
}
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

void make_points(std::vector<double> &x, std::vector<double> &y) // ある一次関数をもとにした点群を作る
{
   std::random_device rnd;
   std::mt19937 mt(rnd());
   std::normal_distribution<double> dist(0.0f, 20.0f);

   for (int i = 0; i < x.size(); i++)
   {
      x[i] = i - points_number / 2;
      y[i] = 1 * x[i] + 80.0;
      x[i] += dist(mt);
   }
}

double average(const std::vector<double> &f, int N) // 配列の全要素の平均をとる関数
{
   double ave = 0.0;

   for (int i = 0; i < N; i++)
      ave += f[i] / (double)N;

   return ave;
}

double average_2char(std::vector<double> &f, std::vector<double> &f2, int N) // 二つの配列をかけた結果の平均をとる関数
{
   double ave2c = 0.0;

   for (int i = 0; i < N; i++)
      ave2c += f[i] * f2[i] / (double)N;

   return ave2c;
}

void saisyou(std::vector<double> &x, std::vector<double> &y, const int points_number, double &a, double &b) // 上記の関数をつかい最小二乗法する関数
{
   double ave_x = average(x, points_number);
   double ave_y = average(y, points_number);
   double ave_xy = average_2char(x, y, points_number);
   double ave_xx = average_2char(x, x, points_number);

   a = (ave_xy - (ave_x * ave_y)) / (ave_xx - (ave_x * ave_x));
   b = ave_y - a * ave_x;
}

int main()
{
   std::vector<double> x(points_number), y(points_number);
   make_points(x, y);        // 点群を作成
   drow_axes(points_number); // 座標軸を描写
   plt::scatter(x, y);       // 点群を描写

   // 最小二乗法ーー
   double a, b;
   saisyou(x, y, points_number, a, b);
   drow_function(a, b);

   std::cout << "傾き:" << a << std::endl;
   std::cout << "切片:" << b << std::endl;

   plt::xlabel("X");
   plt::ylabel("Y");

   plt::show();
}