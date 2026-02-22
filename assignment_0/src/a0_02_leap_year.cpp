#include <iostream>

int main() {
    int year = 0;
    std::cin >> year;

    bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    std::cout << (is_leap ? "YES" : "NO") << std::endl;

    return 0;
}