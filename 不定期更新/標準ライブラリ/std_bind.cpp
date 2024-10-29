// std::bind関数について書く
// 構造ーーーーー
// namespace std {
//   template <class F, class... BoundArgs>
//   unspecified bind(F&& f, BoundArgs&&... bound_args);           // (1) C++11

//   template <class F, class... BoundArgs>
//   constexpr unspecified bind(F&& f, BoundArgs&&... bound_args); // (1) C++20

//   template <class R, class F, class... BoundArgs>
//   unspecified bind(F&& f, BoundArgs&&... bound_args);           // (2) C++11

//   template <class R, class F, class... BoundArgs>
//   constexpr unspecified bind(F&& f, BoundArgs&&... bound_args); // (2) C++20
// }
// ーーーーーー

// 2024-10-28

// std::bindのすること
// 指定した関数をラップしたstd::functionを作る
// 特定の関数に入る引数を先に予約しておくみたいな

// 使い方
// auto 変数 = std::bind(ラップする関数,関数内で使用する変数たち);

#include <iostream>
#include <functional>

int add(int a, int b, int c)
{
   return a + b + c;
}

int main()
{
   using namespace std::placeholders;
   // std::placeholdersは後々関数を呼び出すときに入れる引数の枠を予約する

   std::function<int(int, int)> f1 = std::bind(add, 2, std::placeholders::_1, _2);
   const int result1 = f1(3, 4); // 残りの引数を渡して呼び出し
   std::cout << result1 << std::endl;
}