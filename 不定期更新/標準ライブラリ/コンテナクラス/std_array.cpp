// std::arrayについて
// 構造ーーーーー
// namespace std
// {
//    template <class T, std::size_t N>
//    struct array;
// }
// ーーーーーーー

//---2024-10-22---

#include <iostream>
#include <array>

int main()
{
   // 使い方
   //           ↓型  ↓大きさ
   std::array<int, 5> ar = {0, 3, 2, 4, 6};
   //                         ↓メンバ関数の一つsize
   for (int i = 0; i < ar.size(); i++)
   {
      std::cout << ar[i];
   }
   std::cout << "\n";
   // メンバ関数             ↓配列の中身って意味
   // begin  先頭要素を指すイテレータを取得する end  末尾の1つ次の要素を指すイテレータを取得する
   std::fill(ar.begin(), ar.end(), 3); // すべてを3で満たす
   for (int i = 0; i < ar.size(); i++)
   {
      std::cout << ar[i];
   }

   int *data = ar.data(); // コンテナ内部に保持されている生の配列へ直接アクセスする
   std::cout << *data << std::endl;
}