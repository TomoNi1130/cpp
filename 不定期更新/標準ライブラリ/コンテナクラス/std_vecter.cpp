// vector はシーケンスコンテナの一種で、
// 各要素は線形に、順序を保ったまま格納される．
// とっても便利

// 動的配列クラスといわれていて，宣言したのちに増減,挿入,削除することができる．
// コンテナクラスの中で最も単純で速いらしい．知らんけど

// 構造ーーーーーー
//  namespace std
//  {
//     template <class T, class Allocator = allocator<T>>
//     class vector;

//    namespace pmr
//    {
//       template <class T>
//       using vector = std::vector<T, polymorphic_allocator<T>>; // C++17から
//    }
// }
// ーーーーーーーーー

// 2024-10-24

// 仕様(日本語リファレンスより)
// vector は実際の要素数より少し余分にメモリを確保する
// vector は要素アクセスと(末尾に対する)追加・削除において一般的に最高の性能を誇る
// 配列と違い、ストレージは vector 自体が管理するため、自動的に領域の拡張が行われる

#include <iostream>
#include <cassert>
#include <vector>

int main()
{
   std::vector<int> vec = {0, 99, 58};
   vec[0] = 99; // ゼロ番目に99を代入//一般の配列と同じように代入できる
   for (const int &data : vec)
   {
      std::cout << data << std::endl;
   }
   std::cout << "\n";

   vec.push_back(5); // 末尾に値5を追加
   for (const int &data : vec)
   {
      std::cout << data << std::endl;
   }
   std::cout << "\n";

   vec.insert(vec.begin() + 1, 2); // 一番目に値2を挿入
   for (const int &data : vec)
   {
      std::cout << data << std::endl;
   }
   std::cout << "\n";

   int *p = vec.data();       // 内部表現のポインタを取得
   uint8_t size = vec.size(); // 要素数を取得
   std::cout << p[0] << std::endl;
   assert(p[0] == 99);
}