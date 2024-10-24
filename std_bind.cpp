#include <iostream>
#include <functional>

class Test
{
public:
    void test_function(int a, int b)
    {
        printf("a=%d, b=%d\n", a, b);
    }

    void bind_test()
    { //                                                ↓ここはインスタンスメソッドというものを指定するらしい
        auto func1 = std::bind(&Test::test_function, this, std::placeholders::_1, std::placeholders::_2);
        //                    インスタンスメソッドとはクラスのインスタンス（オブジェクト）に関連付けられたメソッド（関数）のこと
        func1(1, 2);
    }
};

int main(int argc, const char *argv[])
{

    auto test = Test();
    test.bind_test();

    return 0;
}
