// std::functionについて書く
// 構造ーーーーーー
// namespace std
// {
//    template <class>
//    class function; // 宣言のみ

//    template <class R, class... ArgTypes>
//    class function<R(ArgTypes...)>;
// }
// ーーーーーーー

// 2024-10-28-

// 使い方--
// function<戻り値(引数の型)>変数名 = 保存する関数名

#include <iostream>
#include <functional>

int add(int x) // ただの関数
{
   return x + 1;
}

int main()
{
   std::function<int(int)> f = add; // fにadd関数を代入
   std::cout << f(1) << std::endl;

   f = [](int x)
   { return x + 10; }; // 関数オブジェクト(ここではラムダ式)を入れることもできる
   std::cout << f(1) << std::endl;
}