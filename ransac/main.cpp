#include <cmath>
#include <iostream>
#include <vector>
#include <random>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

const int points_number = 75;

void get_param(const std::array<double, 2> &p1, const std::array<double, 2> &p2, double &a, double &b, double &c)
{
   a = p2[1] - p1[1];
   b = p1[0] - p2[0];
   c = -1 * p1[0] * b - p1[0] * a;
}

double euclid(const std::vector<double> &params, const std::array<double, 2> &point)
{
   double a = params[0], b = params[1], c = params[2];
   double x = point[0], y = point[1];
   double norm = std::sqrt(a * a + b * b);
   double dist = std::fabs(a * x + b * y + c) / norm;
   return dist;
}

double model(const std::vector<double> &params, double x)
{
   double a = params[0], b = params[1], c = params[2];
   double slope = -a / b;
   double intercept = -c / b;
   return slope * x + intercept;
}
// ransac関数
void ransac(int max_loop, double threshold, const std::vector<std::array<double, 2>> &points, std::vector<double> &xnew, std::vector<double> &ynew, bool &state)
{
   int best_p_cnt = 0;
   std::vector<double> best_param(3);

   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> dis(0, points.size() - 1);

   for (int i = 0; i < max_loop; ++i)
   {
      int idx1 = dis(gen);
      int idx2 = dis(gen);
      if (idx1 == idx2)
         continue;

      double a, b, c;
      get_param(points[idx1], points[idx2], a, b, c);
      std::vector<double> param = {a, b, c};

      int p_cnt = 0;
      for (const auto &point : points)
      {
         double dist = euclid(param, point);
         if (dist <= threshold)
         {
            ++p_cnt;
         }
      }
      if (p_cnt > best_p_cnt)
      {
         best_p_cnt = p_cnt;
         best_param = param;
      }
   }

   if (best_p_cnt <= 150)
   {
      std::cout << "No line" << std::endl;
      state = false;
   }
   else
   {
      state = true;
      xnew.clear();
      ynew.clear();
      for (double x = -2.0; x <= 2.0; x += 0.1)
      {
         xnew.push_back(x);
         ynew.push_back(model(best_param, x));
      }
   }
}

void process_lidar_data(const std::vector<double> &ranges)
{
   std::vector<std::array<double, 2>> points;
   std::vector<double> plot_x, plot_y;
   std::vector<double> xnew, ynew;
   bool state = false;

   for (size_t i = 0; i < ranges.size(); ++i)
   {
      double theta = M_PI * (225 - 0.2497 * i) / 180.0;
      double length = ranges[i];
      std::array<double, 2> point = {length * std::cos(theta), length * std::sin(theta)};
      points.push_back(point);
      plot_x.push_back(point[0]);
      plot_y.push_back(point[1]);
   }

   ransac(300, 0.001, points, xnew, ynew, state);

   plt::clf();
   plt::plot(plot_x, plot_y);
   if (state)
   {
      plt::plot(xnew, ynew, {{"label", "lidar_line"}});
   }
   plt::legend();
   plt::grid(true);
   plt::xlim(-2, 2);
   plt::ylim(-2, 2);
   plt::pause(0.001);
}

int main()
{
   std::random_device rnd;
   std::mt19937 mt(rnd());
   std::uniform_real_distribution<double> dist(0.0f, 3.0f);
   std::vector<double> ranges(points_number);
   for (int i = 0; i < points_number; ++i)
   {
      ranges[i] = dist(mt);
   }
   process_lidar_data(ranges);
   return 0;
}
