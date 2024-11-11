// センサーなどを使っていて得た数値をもとにグラフが書きたいと思った
// 調べてみるとmatplotlibというものがpythonにはあるというではないか．しかし，私はcpp使いたい．
// そんな時は，matplotlibcpp.hを使おう！！

// 導入方法 --> https://hirlab.net/nblog/category/programming/art_826/

// ーーー2024-11-11ーーーーーー

// 使い方ーー

#include <iostream>
#include <cmath>
#include <vector>

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main()
{
   int n = 1000;

   std::vector<double> x(n), y(n); // x,yともにnこのdouble型の要素を持つように定義する(この要素たちを使って点を表現する)

   for (int i = -500; i < n; ++i)
   {
      x[i] = i;            // x軸はそのまま増えていく
      y[i] = sin(0.1 * i); // y軸のみsinカーブを描くように
   }
   // plt::subplot(2, 1, 1);
   // plt::ylabel("functions");
   plt::scatter(x, y); // scatter関数で点が打てる

   // グラフに名前を付けることもできる

   std::vector<double> nz(n), ny(n);
   for (int i = -500; i < n; ++i)
   {
      ny[i] = 0.006 * i - 2;
      nz[i] = -0.009 * i + 4;
   }
   plt::named_plot("0.006x-2", x, ny); // plot関数で線が描ける
   plt::named_plot("0.009x+4", x, nz);
   plt::legend(); // これがないと左上の名札が出ない
   plt::title("functions");
   plt::xlabel("X");
   plt::ylabel("Y");
   plt::show(); // この関数でグラフを表示

   // 複数グラフの描写
   // pythonのものと同じようにこちらもsubplot関数を使う(しかし，これはcppしか使わない人が書いているのでsubplotの使い方から書く)

   // subplot関数がなんか使えない

   // std::vector<double> mz(n);
   // for (int i = 0; i < n; ++i)
   // {
   //    mz[i] = i ^ 2;
   // }
   // plt::subplot(2, 1, 2);
   // plt::ylabel("quadratic function");
   // plt::plot(x, mz);
   return 0;
}