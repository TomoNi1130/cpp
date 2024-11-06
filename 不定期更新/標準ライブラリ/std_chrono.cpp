// chronoについて書く
#include <thread>
#include <iostream>
#include <chrono>

//<chrono> ヘッダは、時間に関するユーティリティとして機能する関数・クラスを提供する

// 時間間隔を表す型
/*
namespace std {
namespace chrono {
  using nanoseconds  = duration<少なくても64ビットを持つ符号付き整数型, nano>;        // (1) C++11
  //十億分の一
  using microseconds = duration<少なくても55ビットを持つ符号付き整数型, micro>;       // (2) C++11
  //百万分の一
  using milliseconds = duration<少なくても45ビットを持つ符号付き整数型, milli>;       // (3) C++11
  //千分の一
  using seconds      = duration<少なくても35ビットを持つ符号付き整数型>;              // (4) C++11
  using minutes      = duration<少なくても29ビットを持つ符号付き整数型, ratio<60>>;   // (5) C++11
  using hours        = duration<少なくても23ビットを持つ符号付き整数型, ratio<3600>>; // (6) C++11

  using days         = duration<少なくても25ビットを持つ符号付き整数型,
                                ratio_multiply<ratio<24>, hours::period>>;            // (7) C++20
  using weeks        = duration<少なくても22ビットを持つ符号付き整数型,
                                ratio_multiply<ratio<7>, days::period>>;              // (8) C++20
  using years        = duration<少なくても17ビットを持つ符号付き整数型,
                                ratio_multiply<ratio<146097, 400>, days::period>>;    // (9) C++20
  using months       = duration<少なくても20ビットを持つ符号付き整数型,
                                ratio_divide<years::period, ratio<12>>>;              // (10) C++20
}}
*/
// 例

int main()
{ // 型と型変換

  // seconds 少なくとも35bit(5byte)必要
  std::chrono::seconds s1{30};
  std::chrono::seconds s2{20};

  std::chrono::seconds result = s1 + s2; // 20+30 [seconds]
  std::cout << result.count() << std::endl;

  std::chrono::milliseconds ms = result; // seconds を millisecondsに変換
  std::cout << ms.count() << std::endl;

  // 時間計測
  std::chrono::system_clock::time_point start, end;
  start = std::chrono::system_clock::now();
  for (int i = 0; i < 5; i++)
  {
    std::cout << "%d秒経過\n", i;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  end = std::chrono::system_clock::now();
}