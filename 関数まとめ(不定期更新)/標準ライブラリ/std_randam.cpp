//<random>ヘッダについて書く
// 擬似乱数を取り扱うための
// 乱数生成器 (Random Number Generator) ,分布生成器 (Distribution) ,非決定論的な乱数生成器,
// および関連する一連のクラス・関数を定義する乱数ライブラリである

// 疑似乱数生成器について
/*
実は<random>で作られる乱数は完全な乱数ではなく再現性がある
            その代わり高速，高効率
*/

// 非決定論的な乱数生成器について
/*
疑似乱数生成器の欠点をなくし，予測できなくしたもの．
            その代わり生成に時間が少しかかる
*/

//-----2024-11-8-------

// 使い方
#include <iostream>
#include <array>
#include <random>

int main()
{
   // 非決定的な乱数生成器
   std::random_device No_deter;
   // 疑似乱数生成器(ただ，今回はシードに非決定の乱数を入れることで毎回違った乱数が出るようになっている)
   std::mt19937_64 rando(No_deter());

   // 分布生成ーーーー
   // 一様分布
   // [-5.0f, 5.0f)の値の範囲で、等確率に実数を生成する
   //-5~5の間の数値が等間隔に出る関数ができる
   std::uniform_real_distribution<float> dist1(-5.0f, 5.0f);

   // 正規分布
   // 平均1.0f、標準偏差0.5fで分布させる
   // できるのは1を中心とした標準偏差ができる
   std::normal_distribution<float> dist2(1.0f, 0.5f);

   // ほかにもいろいろある．．．．．
   // ーーーーー

   std::array<float, 30> rando1, rando2;

   for (int i = 0; i < 30; i++)
   {
      rando1[i] = dist1(rando); // 作成された数値を配列に代入
      rando2[i] = dist2(rando);
   }

   for (int i = 0; i < 30; i++)
   {
      std::cout << rando1[i] << std::endl;
   }
   std::cout << "\n"
             << std::endl;
   for (int i = 0; i < 30; i++)
   {
      std::cout << rando2[i] << std::endl;
   }
}