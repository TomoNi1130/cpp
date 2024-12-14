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
   pointsProcess(const int line_number, const int points_number)
   {
      all_line_number = line_number;
      all_points_number = points_number;
      _inliers.resize(all_points_number, false);
   }
   void draw_points_cloud()
   {
      plt::scatter(_x, _y);
   }
   void make_points_cloud()
   {
      std::random_device rad;
      std::mt19937 random(rad());
      std::uniform_real_distribution<double> dist(-5.0f, 5.0f);

      _x.resize(all_points_number);
      _y.resize(all_points_number);
      for (int i = 0; i < all_points_number; i++)
      {
         _x[i] = dist(random);
         _y[i] = dist(random);
      }
   }
   void ransac(const int max_iterations, const double threshold, int const Minimum_guarantee) // 試行回数，闘値，最低保証(inlier下限)
   {
      std::cout << "ransac" << std::endl;
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_real_distribution<double> dis(0, _x.size() - 1);

      for (int line_num = 0; line_num < all_line_number; line_num++) // 決まった数だけ線分を書く//line_segment(線分)を求める
      {
         std::vector<bool> best_inliers(_x.size(), false);
         line_segment best_model;
         int best_inliers_count = 0;

         for (int i = 0; i < max_iterations; i++) // 試行回数の分だけランダムに生成された直線を選定する//line(直線)を求める
         {
            std::vector<bool> guess_inliers(_x.size(), false);
            std::vector<double> in_line_x(0); // inlierのx座標を記録するやつ//線分にする
            std::vector<double> in_line_y(0); // inlierのx座標を記録するやつ//線分にする
            int guess_inliers_count = 0;

            int idx1 = dis(gen);
            int idx2 = dis(gen);
            while (idx2 == idx1)
            {
               idx2 = dis(gen);
            }
            line guess_model = fit_line(_x[idx1], _y[idx1], _x[idx2], _y[idx2]);

            for (std::vector<double>::size_type j = 0; j < _x.size(); j++)
            {
               if (!_inliers[j] && calculate_error(_x[j], _y[j], guess_model) < threshold) // 予測グラフと，各点の誤差が闘値以下であれば，
               {
                  ++guess_inliers_count;
                  guess_inliers[j] = true;
                  in_line_x.push_back(_x[j]);
                  in_line_y.push_back(_y[j]);
               }
            }
            if (guess_inliers_count > best_inliers_count)
            {
               best_inliers = guess_inliers;
               best_inliers_count = guess_inliers_count;
               best_model.a = guess_model.a;
               best_model.b = guess_model.b;
               best_model.c = guess_model.c;
               best_model.low_x = *min_element(begin(in_line_x), end(in_line_x));
               best_model.high_x = *max_element(begin(in_line_x), end(in_line_x));
               best_model.high_y = *max_element(begin(in_line_y), end(in_line_y));
               best_model.low_y = *min_element(begin(in_line_y), end(in_line_y));
            }
         }

         if (best_inliers_count < Minimum_guarantee && ransac_lines.size() > all_line_number / 2)
            break;
         for (int i = 0; i < all_points_number; i++)
         {
            if (best_inliers[i])
               _inliers[i] = true;
         }
         ransac_lines.push_back(best_model);
         ransac_lines.back().distance = get_distance_line(line_num);
         ransac_lines.back().theta = get_theta(line_num);
      }
   }

   void draw_ransac_lines()
   {
      for (const line_segment line : ransac_lines) // この書き方は知らなかった(AIに聞いた)
      {
         draw_line(line);
      }
   }

private:
   std::vector<double> _x, _y;
   std::vector<bool> _inliers; // 直線の近くにある点を記録するための配列(線の重複を防ぐため)
   std::vector<line_segment> ransac_lines;
   int all_line_number;
   int all_points_number; // すべての点の合計数
   int now_line_number = 0;

   double get_theta(int line_number)
   {
      int get_line_number = line_number;
      double slope = ransac_lines.back().b / ransac_lines.back().a;
      plt::plot(std::vector<double>{ransac_lines.back().low_x, ransac_lines.back().high_x}, std::vector<double>{slope * ransac_lines.back().low_x, slope * ransac_lines.back().high_x});
      if (-(ransac_lines.back().a / ransac_lines.back().b) < 0)
      {
         if (-ransac_lines.back().c / ransac_lines.back().b > 0)
         {
            // std::cout << "theta_line " << line_number + 1 << " :" << std::atan(slope) * 180.0 / pi << std::endl;
            return std::atan(slope); // 第一象限
         }
         else
         {
            // std::cout << "theta_line " << line_number + 1 << " :" << (std::atan(slope) + pi) * 180.0 / pi << std::endl;
            return std::atan(slope) + pi; // 第三象限
         }
      }
      else
      {
         if (-ransac_lines.back().c / ransac_lines.back().b > 0)
         {
            // std::cout << "theta_line " << line_number + 1 << " :" << (std::atan(slope) + pi) * 180.0 / pi << std::endl;
            return std::atan(slope) + pi; // 第二象限
         }
         else
         {
            // std::cout << "theta_line " << line_number + 1 << " :" << (std::atan(slope) + 2 * pi) * 180.0 / pi << std::endl;
            return std::atan(slope) + 2 * pi; // 第四象限
         }
      }
   }

   double get_distance_line(int line_number)
   {
      int get_line_number = line_number;
      double x2 = ransac_lines.back().high_x;
      double x1 = ransac_lines.back().low_x;
      double y2 = ransac_lines.back().high_y;
      double y1 = ransac_lines.back().low_y;

      double a = x2 - x1;
      double b = y2 - y1;
      double a2 = a * a;
      double b2 = b * b;
      double r2 = a2 + b2;
      double tt = -(a * x1 + b * y1);
      if (tt < 0)
      {
         // std::cout << "distance_line " << line_number + 1 << ":" << sqrt(x1 * x1 + y1 * y1) << std::endl;
         return sqrt(x1 * x1 + y1 * y1);
      }
      if (tt > r2)
      {
         // std::cout << "distance_line " << line_number + 1 << ":" << sqrt(x2 * x2 + y2 * y2) << std::endl;
         return sqrt(x2 * x2 + y2 * y2);
      }
      double f1 = a * y1 - b * x1;
      // std::cout << "distance_line " << line_number + 1 << " :" << sqrt((f1 * f1) / r2) << std::endl;
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
   double calculate_error(const double &x, const double &y, const line &model) // 誤差を求める
   {
      double error = abs(model.a * x + model.b * y + model.c) / std::sqrt(model.a * model.a + model.b * model.b);
      return error; // 差の絶対値を返す
   }

   line fit_line(double &x_1, double &y_1, double &x_2, double &y_2) // 二点の距離から直線を割り出す
   {
      line guess_line;
      guess_line.a = y_2 - y_1;
      guess_line.b = x_2 - x_1;
      guess_line.c = y_1 * x_2 - x_1 * y_2;
      return guess_line;
   }

}; // pointsProcess
