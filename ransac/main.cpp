#include <iostream>
#include <random>
#include <vector>
#include <cmath>

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

const int points_number = 700;

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
   plt::plot(x_gess, y_gess);
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

double calculate_error(double x, double y, const line &model)
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

line ransac(std::vector<double> x, std::vector<double> y, int max_iterations, double threshold)
{
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> dis(0, x.size() - 1);

   line best_model;
   int best_inliers_count = 0;
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
         if (calculate_error(x[j], y[j], model) < threshold)
         {
            ++inliers_count;
         }
      }
      if (inliers_count > best_inliers_count)
      {
         best_inliers_count = inliers_count;
         best_model = model;
      }
   }
   return best_model;
}

void make_outliners(std::vector<double> &y)
{
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<int> dis(0, points_number);
   for (int i = 0; i < 100; i++)
   {
      y[dis(gen)] = 500;
   }
}

int main()
{
   line line1 = {1.0, 30.0};
   line line2 = {-1.0, -50.0};
   std::vector<double> line1_x(points_number), line1_y(points_number);
   std::vector<double> line2_x(points_number), line2_y(points_number);
   make_random_points(line1, 5.0, line1_x, line1_y);
   make_random_points(line2, 0.0, line2_x, line2_y);
   make_outliners(line1_y);

   drow_axes(points_number);
   plt::scatter(line1_x, line1_y);
   // plt::scatter(line2_x, line2_y);

   int max_iterations = 100;
   double threshold = 5.0;
   line best_line = ransac(line1_x, line1_y, max_iterations, threshold);
   std::cout << "傾き(目標):" << line1.slope << "切片(目標):" << line1.intercept << std::endl;
   std::cout << "傾き(予測):" << best_line.slope << "切片(予測):" << best_line.intercept << std::endl;
   drow_function(best_line);

   plt::show();
}