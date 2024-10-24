// ここではコンストラクタを使う。

// コンストラクタの効果ーークラスを使ってオブジェクトを作ったときに自動的に値が入るようになる。←いちいち値を代入する必要がなくなる
// 言い換えれば、オブジェクトを作ったときのみに実行されるメンバ関数である(デストラクタもあるよ)

#include <iostream>
// 普通のクラス
class normal
{
public:
    void Normal()
    {
        std::cout << "これはただのメンバ関数\n";
    };
};
// コンストラクタのあるクラス
class Newclass
{
public:
    Newclass() // 型をなくし、名前を同じにすることでコンストラクタになる
    {
        std::cout << "オブジェクトを作るだけで発動！\n";
    };
};
// コンストラクタを使った初期化
class syokika
{
private:
    int num;

public:
    syokika() // コンスト
    {
        num = 19;
    };

    void Sstnum(int x)
    {
        num = x;
    };

    int Getnum()
    {
        return num;
    }
};
// 引数のあるコンストラクタを含む
class hikisuu
{
public:
    int num;
    hikisuu(int x)
    {
        num = x;
    };
};

int main()
{
    normal obj2; // クラスでオブジェクトを作っている

    Newclass obj;

    syokika obj3;

    std::cout << obj3.Getnum() << "\n";

    hikisuu obj4(100); // 引数に代入してる

    std::cout << obj4.num << "\n";

    return 0;
}