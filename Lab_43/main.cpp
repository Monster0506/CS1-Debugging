// Tests the String class (null-terminated, dynamically allocated).
//
// Expected output:
//   a + b: hello world
//   a: hello  c: hello!
//   length of a: 5
//   a == hello: yes
//   a == c: no
//   abc < abd: yes
//   abd < abc: no
//   ab < abc: yes
//   substr(1,3) of c: ell
//   findch l: 2
//   findstr lo: 3
//   findstr xyz: -1
//   split: [a] [b] [c]
//   d: Jello  a: hello

#include "string.hpp"
#include <iostream>
#include <vector>

int main() {
    String a("hello"), b(" world");
    std::cout << "a + b: " << a + b << std::endl;

    String c(a);
    c += "!";
    std::cout << "a: " << a << "  c: " << c << std::endl;
    std::cout << "length of a: " << a.length() << std::endl;

    std::cout << "a == hello: " << (a == String("hello") ? "yes" : "no") << std::endl;
    std::cout << "a == c: " << (a == c ? "yes" : "no") << std::endl;
    std::cout << "abc < abd: " << (String("abc") < String("abd") ? "yes" : "no") << std::endl;
    std::cout << "abd < abc: " << (String("abd") < String("abc") ? "yes" : "no") << std::endl;
    std::cout << "ab < abc: " << (String("ab") < String("abc") ? "yes" : "no") << std::endl;

    std::cout << "substr(1,3) of c: " << c.substr(1, 3) << std::endl;
    std::cout << "findch l: " << a.findch(0, 'l') << std::endl;
    std::cout << "findstr lo: " << a.findstr(0, String("lo")) << std::endl;
    std::cout << "findstr xyz: " << a.findstr(0, String("xyz")) << std::endl;

    std::vector<String> parts = String("a,b,c").split(',');
    std::cout << "split:";
    for (size_t i = 0; i < parts.size(); ++i) {
        std::cout << " [" << parts[i] << "]";
    }
    std::cout << std::endl;

    String d;
    d = a;
    d[0] = 'J';
    std::cout << "d: " << d << "  a: " << a << std::endl;
}
