
#include <vector>
#include <random>
#include "sbb.cpp"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main()
{
   pointsProcess cloud(2);
   line first_line = (-1.0, 1.0, 1.0, 1.0, 1.0);
   line second_line = (-2.0, 0, -1.0, 1.0, -1.0);

   cloud.drow_line(first_line);

   plt::xlabel("X");
   plt::ylabel("Y");
   plt::show();

   retrun 0;
}