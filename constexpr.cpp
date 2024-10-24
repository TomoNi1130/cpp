#include <cassert>
#include <iostream>
// constexpr (constant expression)直訳すると、絶え間ない表現、定数式、、汎用的に定数式を表現するための機能
constexpr int square(int x)
{
   return x * x;
}

int main()
{
   /*
   コンパイル時に値が決定する定数、
   コンパイル時に実行される関数、
   コンパイル時にリテラルとして振る舞うクラスを定義できる
   */
   // constexpr int compile_time_result = 3; //コンパイル時に定義され、その後コンパイル中は変えられない
   constexpr int compile_time_result = square(3);               // コンパイル時に実行
   static_assert(compile_time_result == 9, "result must be 9"); // コンパイル時に判定される

   std::cout << compile_time_result << "\n";
}