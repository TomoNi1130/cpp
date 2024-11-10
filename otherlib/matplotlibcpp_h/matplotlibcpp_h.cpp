// センサーなどを使っていて得た数値をもとにグラフが書きたいと思った
// 調べてみるとmatplotlibというものがpythonにはあるというではないか．しかし，私はcpp使いたい．
// そんな時は，matplotlibcpp.hを使おう！！

// 導入方法 --> https://hirlab.net/nblog/category/programming/art_826/

// 使い方ーー

#include <iostream>
#include <cmath>
#include <vector>

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

int main()
{
   int n = 1000;
   std::vector<double> x(n), y(n);

   for (int i = 0; i < n; ++i)
   {
      x[i] = i;
      y[i] = sin(0.1 * i);
   }

   plt::plot(x, y);
   plt::show();

   return 0;
}