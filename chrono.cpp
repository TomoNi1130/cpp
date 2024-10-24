#include <iostream>
#include <array>
#include <chrono>

using namespace std::chrono_literals;

std::chrono::microseconds max_pulse_width = 2500us;

int main()
{
   auto a = max_pulse_width.count();
   printf("%lld\n", max_pulse_width);
   printf("%lld", a);
}