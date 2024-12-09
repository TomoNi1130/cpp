#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <cmath>
#include <algorithm>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

struct line_segment
{
   // 線分にするためのデータ
   double low_x, high_x;
   // ax+by+c = 0  y= a/b*x+c/b
   double a, b, c;
};

struct line
{
   double a, b, c;
};

class pointsProcess
{
public:
   std::vector<double> _x, _y;
   std::vector<bool> _inliers; // 直線の近くにある点を記録するための配列(線の重複を防ぐため)
   std::vector<line_segment> ransac_lines;

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
         _x[i] = dist(random) / 2;
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
            int guess_inliers_count = 0;

            int idx1 = dis(gen);
            int idx2 = dis(gen);
            while (idx2 == idx1)
            {
               idx2 = dis(gen);
            }
            line guess_model = fit_line(_x[idx1], _y[idx1], _x[idx2], _y[idx2]);

            for (int j = 0; j < _x.size(); j++)
            {
               if (!_inliers[j] && calculate_error(_x[j], _y[j], guess_model) < threshold) // 予測グラフと，各点の誤差が闘値以下であれば，
               {
                  ++guess_inliers_count;
                  guess_inliers[j] = true;
                  in_line_x.push_back(_x[j]);
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
      }
   }

   void draw_ransac_lines()
   {
      for (const auto &line : ransac_lines) // この書き方は知らなかった(AIに聞いた)
      {
         draw_line(line);
      }
   }

private:
   int all_line_number;
   int all_points_number; // すべての点の合計数
   int now_line_number = 0;
   void draw_line(line_segment const line)
   {
      std::vector<double> x, y;
      double x_width = line.high_x - line.low_x;
      std::cout << "line" << now_line_number + 1 << ":" << line.high_x << "~" << line.low_x << std::endl;
      for (int i = 0; i < 2; i++)
      {
         x.push_back(line.low_x + x_width * i);
         y.push_back(line.a / line.b * (line.low_x + x_width * i) + line.c / line.b);
      }
      plt::plot(x, y);
      now_line_number++;
   }
   double calculate_error(const double x, const double y, const line &model) // 誤差を求める
   {
      double y_est = (model.a * x + model.c) / model.b;
      return std::fabs(y - y_est); // 差の絶対値を返す
   }

   line fit_line(double x_1, double y_1, double x_2, double y_2) // 二点の距離から直線を割り出す
   {
      line guess_line;
      guess_line.a = y_2 - y_1;
      guess_line.b = x_2 - x_1;
      guess_line.c = y_1 * x_2 - x_1 * y_2;
      return guess_line;
   }

}; // pointsProcess
