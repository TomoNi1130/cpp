// ここにすべての点の座標を表現するための型を作る
#include <iostream>
#include <vector>
#include <random>

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int max_iterations = 35; // ransac内での試行回数
double threshold = 10.0; // 闘値

const int line_number = 3; // 線の数
int points_number = 750;   // 一つの線ごとの点の数

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

void make_random_points(line line, double amplitude, std::vector<double> &_x, std::vector<double> &_y) // amplitude = 振れ幅
{
   std::random_device rnd;
   std::mt19937 mt(rnd());
   std::normal_distribution<double> dist(0.0f, amplitude);

   for (int i = 0; i < points_number; i++)
   {
      _x.emplace_back(i - points_number / 2);
      _y.emplace_back(line.slope * (i - points_number / 2) + line.intercept + dist(mt));
   }
}

void make_outliners(std::vector<double> &y, const int outliers_number)
{
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<int> dis(-points_number / 2, points_number / 2);
   std::uniform_int_distribution<int> dist(0, y.size() - 1);
   for (int i = 0; i < outliers_number; ++i)
   {
      int outlier_value = dis(gen);
      do
         outlier_value = dis(gen);
      while (outlier_value == 0);
      y[dist(gen)] = outlier_value;
   }
}
double calculate_error(double x, double y, const line &model) // 誤差を求める
{
   double y_est = model.slope * x + model.intercept;
   return std::fabs(y - y_est); // 差の絶対値を返す
}

line fit_line(double x1, double y1, double x2, double y2) // 二点から直線を割り出す
{
   double slope = (y2 - y1) / (x2 - x1);
   double intercept = y1 - slope * x1;
   return {slope, intercept};
}
line ransac(std::vector<double> &_x, std::vector<double> &_y, std::vector<bool> &inliers)
{
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> dis(0, _x.size() - 1);

   std::vector<bool> gess_inliers = inliers;
   std::vector<bool> best_inliers = inliers;
   line best_model;
   int best_inliers_count = 0;
   for (int i = 0; i < max_iterations; i++)
   {
      int idx1 = dis(gen);
      int idx2 = dis(gen);
      std::fill(gess_inliers.begin(), gess_inliers.end(), false);
      while (idx2 == idx1)
      {
         idx2 = dis(gen);
      }
      line model = fit_line(_x[idx1], _y[idx1], _x[idx2], _y[idx2]);
      int inliers_count = 0;
      for (int j = 0; j < _x.size(); j++)
      {
         if (!inliers[j])
            if (calculate_error(_x[j], _y[j], model) < threshold) // 予測グラフと，各点の誤差が闘値以下であれば，
            {
               ++inliers_count;
               gess_inliers[j] = true;
            }
      }
      if (inliers_count > best_inliers_count)
      {
         best_inliers_count = inliers_count;
         best_model = model;
         best_inliers = gess_inliers;
      }
   }
   for (int i = 0; i < inliers.size(); i++)
      if (best_inliers[i] && !inliers[i])
         inliers[i] = best_inliers[i];
   return best_model;
}