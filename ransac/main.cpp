// 動きはするが，点の座標の表し方に不満があるので作り直す
#include <iostream>
#include <random>
#include <vector>
#include <cmath>

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

const int points_number = 7500;
const int line_number = 5;
const bool line_drow_on = true;
const bool points_drow_on = true;
const bool axes_drow_on = true;

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
      _x[i] = i - points_number / 2;
      _y[i] = line.slope * _x[i] + line.intercept + dist(mt);
   }
}

double calculate_error(double x, double y, const line &model) // 誤差を求める
{
   double y_est = model.slope * x + model.intercept;
   return std::fabs(y - y_est);
}

line fit_line(double x1, double y1, double x2, double y2)
{
   double slope = (y2 - y1) / (x2 - x1);
   double intercept = y1 - slope * x1;
   return {slope, intercept};
}

line ransac(std::vector<double> x, std::vector<double> y, int max_iterations, double threshold, std::vector<bool> &inliers)
{
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> dis(0, x.size() - 1);

   line best_model;
   int best_inliers_count = 0;
   int min_inliers_number = points_number / line_number * 2;
   // ransacーーーーー
   for (int i = 0; i < max_iterations; ++i)
   {
      int idx1 = dis(gen);
      int idx2 = dis(gen);
      while (idx2 == idx1)
      {
         idx2 = dis(gen);
      }
      line model = fit_line(x[idx1], y[idx1], x[idx2], y[idx2]);
      int inliers_count = 0;
      for (size_t j = 0; j < x.size(); ++j)
      {
         if (calculate_error(x[j], y[j], model) < threshold) // 予測グラフと，各点の誤差が闘値以下であれば，
         {
            ++inliers_count;
            inliers[j] = true;
         }
         // std::cout << j << std::endl;
      }
      if (inliers_count > best_inliers_count)
      {
         best_inliers_count = inliers_count;
         best_model = model;
      }
   }
   return best_model;
}

void make_outliners(std::vector<double> &y, const int outliers_number)
{
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<int> dis(0, points_number);
   for (int i = 0; i < outliers_number; i++)
   {
      y[dis(gen)] = points_number / 2 - dis(gen);
   }
}

int main()
{
   // 点群座標軸の用意
   line original_line = {1.0, 30.0};
   std::vector<double> original_line_x(points_number), original_line_y(points_number);
   make_random_points(original_line, 50.0, original_line_x, original_line_y);
   make_outliners(original_line_y, points_number / 3);
   if (axes_drow_on)
      drow_axes(points_number);
   if (points_drow_on)
      plt::scatter(original_line_x, original_line_y, 1.0);
   std::cout << "傾き(目標):" << original_line.slope << "切片(目標):" << original_line.intercept << std::endl;

   // ransac--------

   int max_iterations = 35;  // 試行回数
   double threshold = 300.0; // 振れ幅
   std::vector<double> now_line_x = original_line_x, now_line_y = original_line_y;
   std::vector<bool> inliers(points_number, false); // 点が闘値内にあるかどうかを判定する変数
   for (int j = 0; j < line_number; j++)
   {
      line gess_line = ransac(now_line_x, now_line_y, max_iterations, threshold, inliers);
      std::cout << "直線" << j + 1 << ">>傾き(予測):" << gess_line.slope << "切片(予測):" << gess_line.intercept << std::endl;
      // int out_liners_number = points_number - inliers;
      std::vector<double> x_outliers, y_outliers;
      for (size_t i = 0; i < points_number; ++i)
      {
         if (!inliers[i])
         {
            x_outliers.push_back(now_line_x[i]);
            y_outliers.push_back(now_line_y[i]);
         }
      }
      now_line_x = x_outliers;
      now_line_y = y_outliers;
      if (line_drow_on)
         drow_function(gess_line);
   }
   //----------
   plt::show();
}