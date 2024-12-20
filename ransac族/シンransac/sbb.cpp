#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <cmath>
#include <algorithm>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

double pi = 3.1415;

struct line_segment
{
   // 線分にするためのデータ
   double low_x, high_x, low_y, high_y;
   // ax+by+c = 0  y= a/b*x+c/b
   double a, b, c;

   double distance; // 原点との距離

   double theta; // 角度
};

struct line
{
   double a, b, c;
};

void drow_axes(int x) // 座標軸を書く用の関数
{

   std::vector<double> x_x_line, y_x_line, x_y_line, y_y_line;

   for (int i = -1; i < 2; i++)
   {
      x_x_line.push_back(i * x);
      y_x_line.push_back(0);
      y_y_line.push_back(i * x);
      x_y_line.push_back(0);
   }
   plt::plot(x_x_line, y_x_line);
   plt::plot(x_y_line, y_y_line);
}

class pointsProcess
{
public:
   pointsProcess(std::vector<double> &x, std::vector<double> &y)
       : _x(x), _y(y), all_points_num(x.size()) {}

   void ransac(const int line_num, const int max_iterations, const double threshold, int const Minimum_guarantee)
   {
      std::vector<bool> inlier(all_points_num, false);

      for (int now_line_num = 0; now_line_num < line_num; now_line_num++)
      {
         line_segment best_line; // 求める線分
         std::vector<bool> guess_guess_inlier(all_points_num);
         int best_inlier_count = 0;

         for (int i = 0; i < max_iterations; i++)
         {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dis(0, _x.size() - 1);
            std::vector<bool> guess_inlier = inlier;
            std::vector<double> inlier_x;
            std::vector<double> inlier_y;
            int guess_inlier_count = 0;
            bool break_flag = false;

            double guess_1 = dis(gen);
            double guess_2 = dis(gen);
            while (guess_1 == guess_2)
            {
               guess_2 = dis(gen);
            }
            line guess_line = fit_line(_x[guess_1], _y[guess_1], _x[guess_2], _y[guess_2]);
            for (int j = 0; j < _x.size(); j++)
            {
               // std::cout << "points" << _y[0] << std::endl;
               if (calculate_error(_x[j], _y[j], guess_line) < threshold && !inlier[j])
               {
                  guess_inlier_count++;
                  guess_inlier[j] = true;
                  inlier_x.push_back(_x[j]);
                  inlier_y.push_back(_y[j]);
               }
            }
            std::cout << inlier_x.size() << std::endl;
            sort(inlier_x.begin(), inlier_x.end()); // inlierを順番に並べ替え
            // std::cout << "検査開始..." << std::endl;
            if (!inlier_x.size() == 0)
               for (int k = 0; k < inlier_x.size(); k++)
               {
                  // std::cout << ".";
                  if (abs(inlier_x[k + 1]) > abs(inlier_x[k]) * 10.0)
                  {
                     std::cout << "breaked!!" << abs(inlier_x[k + 1]) << ">" << abs(inlier_x[k]) * 8.0 << std::endl;
                     break_flag = true;
                  }
               }
            else
               std::cout << "inlier.size() = 0" << std::endl;
            // std::cout << "\n"
            //           << "検査終了" << std::endl;
            if (best_inlier_count < guess_inlier_count && !break_flag)
            {

               best_inlier_count = guess_inlier_count;
               guess_guess_inlier = guess_inlier;
               best_line.a = guess_line.a;
               best_line.b = guess_line.b;
               best_line.c = guess_line.c;
               best_line.low_x = *std::min_element(begin(inlier_x), end(inlier_x));
               best_line.high_x = *std::max_element(begin(inlier_x), end(inlier_x));
               best_line.high_y = *std::max_element(begin(inlier_y), end(inlier_y));
               best_line.low_y = *std::min_element(begin(inlier_y), end(inlier_y));
               best_line.distance = get_distance_line(best_line.low_x, best_line.low_y, best_line.high_x, best_line.high_y);
               best_line.theta = get_theta(guess_line.a, guess_line.b, guess_line.c);
            }
         }
         inlier = guess_guess_inlier;
         draw_line(best_line);
      } // 線の数

   } // ransac関数

private:
   const int all_points_num;
   int now_line_number = 0;
   const std::vector<double> _x, _y;

   double calculate_error(const double &x, const double &y, const line &model) // 誤差を求める
   {
      double error = abs(model.a * x + model.b * y + model.c) / std::sqrt(model.a * model.a + model.b * model.b);
      return error; // 差の絶対値を返す
   }

   line fit_line(double const x_1, double const y_1, double const x_2, double const y_2) // 二点の距離から直線を割り出す
   {
      line guess_line;
      double m = (y_1 - y_2) / (x_1 - x_2);
      double b = y_1 - m * x_1;
      guess_line.a = m;
      guess_line.b = -1;
      guess_line.c = b;
      return guess_line;
   }

   double get_theta(double a, double b, double c)
   {
      double slope = b / a;
      if (-(a / b) < 0)
      {
         if (-(c / b) > 0)
         {
            return std::atan(slope); // 第一象限
         }
         else
         {
            return std::atan(slope) + pi; // 第三象限
         }
      }
      else
      {
         if (-(c / b) > 0)
         {
            return std::atan(slope) + pi; // 第二象限
         }
         else
         {
            return std::atan(slope) + 2 * pi; // 第四象限
         }
      }
   }
   double get_distance_line(double x1, double y1, double x2, double y2)
   {
      double a = x2 - x1;
      double b = y2 - y1;
      double a2 = a * a;
      double b2 = b * b;
      double r2 = a2 + b2;
      double tt = -(a * x1 + b * y1);
      if (tt < 0)
      {
         return sqrt(x1 * x1 + y1 * y1);
      }
      if (tt > r2)
      {
         return sqrt(x2 * x2 + y2 * y2);
      }
      double f1 = a * y1 - b * x1;
      return sqrt((f1 * f1) / r2);
   }

   void draw_line(line_segment const &line)
   {
      std::vector<double> x, y;
      double x_width = line.high_x - line.low_x;
      double y_width = line.high_y - line.low_y;
      std::cout << "line" << now_line_number + 1 << ":" << line.high_x << "~" << line.low_x << " a:" << line.a << " b:" << line.b << " c:" << line.c << " distance:" << line.distance << " theta:" << line.theta * 180 / pi << std::endl;

      if (x_width > y_width)
      {
         for (int i = 0; i < 2; i++)
         {
            x.push_back(line.low_x + x_width * i);
            y.push_back(-(line.a / line.b * (line.low_x + x_width * i)) - line.c / line.b);
         }
      }
      else
      {
         for (int i = 0; i < 2; i++)
         {
            y.push_back(line.low_y + y_width * i);
            x.push_back(-(line.b / line.a * (line.low_y + y_width * i)) - line.c / line.a);
         }
      }
      plt::plot(x, y);
      now_line_number++;
   }
}; // pointsProcess
