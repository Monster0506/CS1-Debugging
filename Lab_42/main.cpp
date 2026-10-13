// Tests the Bigint class (arbitrary size positive integers, one digit per
// array element, least significant digit first).
//
// Expected output:
//   299793 + 1207 = 301000
//   999 + 1 = 1000
//   123 * 456 = 56088
//   25! = 15511210043330985984000000
//   (10^20-1)^2 = 9999999999999999999800000000000000000001
//   25 * 4 = 100
//   7 * 10^3 = 7000
//   00123 == 123: yes
//   123 == 1123: no
//   0 + 0 = 0

#include "bigint.hpp"
#include <iostream>

int main() {
    Bigint a("299793"), b(1207);
    std::cout << "299793 + 1207 = " << a + b << std::endl;
    std::cout << "999 + 1 = " << Bigint("999") + Bigint(1) << std::endl;
    std::cout << "123 * 456 = " << Bigint(123) * Bigint(456) << std::endl;

    Bigint f(1);
    for (int i = 2; i <= 25; i++) {
        f = f * Bigint(i);
    }
    std::cout << "25! = " << f << std::endl;

    Bigint big("99999999999999999999");
    std::cout << "(10^20-1)^2 = " << big * big << std::endl;

    std::cout << "25 * 4 = " << Bigint(25).timesDigit(4) << std::endl;
    std::cout << "7 * 10^3 = " << Bigint(7).times10(3) << std::endl;

    std::cout << "00123 == 123: " << (Bigint("00123") == Bigint(123) ? "yes" : "no") << std::endl;
    std::cout << "123 == 1123: " << (Bigint(123) == Bigint(1123) ? "yes" : "no") << std::endl;
    std::cout << "0 + 0 = " << Bigint() + Bigint() << std::endl;
}
