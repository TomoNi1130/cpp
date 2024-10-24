// smartなpointaを理解しよう！！

// 動的確保のみだとミスが多発して仕方がない
// 　　　　　　　　↓
// それぞれのメモリに所有者(責任者)をつけることで自動的に確保と解放をしてくれるようにしよう
// 　　　　　　　　↓
// スマートポインタ誕生
#include "TwoInt.cpp"
#include <iostream>
#include <memory> //使用するにはこれをインクルードしよう！！

int main()
{                               // 　　↓これがスマートポインタの一種
    std::unique_ptr<int[]> ptr; // Int配列型のポインタをつくった
    // こう書くのと同じ
    // int* ptr=nullptr;//ptrをint型のポインタにして、初期化している
    int len2;
    std::cin >> len2;
    int len = ++len2;
    // 　　　　　　　↓自作クラスもつかえる

    if (len > 0)
    {                                       // アドレスを作ると同時に数を入れている(ここでは配列を作っているので値は入っていない)
        ptr = std::make_unique<int[]>(len); // さっき作った配列のポインタにlen個の枠のある配列の先頭アドレスを入れてる
        // make_unique関数内部でnewしている
        // ptr = new int[len];
    }

    for (int i = 0; i < len; ++i)
    { // 配列型ならoperator[]で要素にアクセスできる
        ptr[i] = i * i;
        std::cout << ptr[i] << "\n";
    }
    // 　　　　　　↓make_sharedは実体を作ると同時に代入もできる
    auto ptr2 = std::make_unique<twoint>(2, 5); // こうして入れるときはクラス側に対応するようにコンストラクタ和作っておく必要がある

    std::cout << "a: " << ptr2->a << "\n";
    std::cout << "b: " << ptr2->b << "\n";

    return 0;
    // やっていることは動的確保だが、unique関数がしてくれるので開放する必要はない
}

// スマートポインタの種類
// std::unique_ptr x; // 最もシンプルで最も軽い　所有権を他人に譲らないように作られている
//                    // コピー不可

// std::shared_ptr a; // ←これはその名の通りあるメモリの所有権を複数のインスタンスで共有できるように設計されたスマートポインタ
//                    // コピー可能　常時ちょっと重い

// std::weak_ptr aa; // ←これは所有権を持たないsharedみたいな　よくわからん

// メモリの管理をゆだねる
