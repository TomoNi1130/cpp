// ラムダ式の前にこれを知っておこう

// 関数オブジェクトとは、
// 通常の関数と同じ構文で関数呼び出しを扱えるクラスである。

// ーーーー2024-10-26ーーーーー

#include <iostream>

// 関数オブジェクトの例
struct doubler
{
   int operator()(int x) const { return x * 2; }
};
// 関数オブジェクトには、直接的な関数呼び出しに勝る 2 つの主な利点がある
// 1つ目に、関数オブジェクトには状態を含めることができる
// 2つ目に、関数オブジェクトは型であるため、テンプレート パラメーターとして使用できます

// 関数オブジェクトの作成ーーーー
class Functor
{
public:
   int operator()(int a, int b)
   {
      return a < b; // true or false を返す
   }
};
// 一つの関数オブジェクトに複数の関数機能を持たせるには，，
// オーバーライドを使う
class override
{
public:
   int operator()(int a, int b) const
   {
      return a < b;
   }
   void operator()(int a) const
   {
      std::cout << "Value: " << a << std::endl;
   }
   void operator()(const std::string &str) const
   {
      std::cout << "String: " << str << std::endl;
   }
};

int main()
{
   Functor f; // クラスのインスタンスを作成
   int a = 5;
   int b = 7;
   int ans = f(a, b); // 関数オブジェクトの呼び出し(普段の関数と似ているが別のもの)

   override g;
   if (g(a, b))
   {
      g(399);
      g("string");
   }
}
// ーーーーー