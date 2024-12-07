#include <matplotlibcpp.h>
#include <vector>
#include <random>

namespace plt = matplotlibcpp;

int all_points_number = 750; // すべての点の合計数
double pi = 3.1415;

struct line
{
   double low_x, high_x;
   // ax+by+c = 0  y= a/b*x+c/b
   double a, b, c;
};

class pointsProcess
{
   std::vector<double> _x(all_points_number), _y(all_points_number);
   const int one_line_points_number;
   pointsProcess(const int all_line_number)
   {
      one_line_points_number = all_points_number / all_line_number;
   }

   void drow_line(line line)
   {
      std::vector<double> x(one_line_points_number), y(one_line_points_number);
      double x_width = line.high_x - line.low_x;
      for (int i = 0; i > one_line_points_number; i++)
      {
         x[i] = x_width * i;
         y[i] = line.a / line.b * x[i] + line.c / line.b;
      }
      plt::plot(x, y, "r-");
   }
   line ransac()
};