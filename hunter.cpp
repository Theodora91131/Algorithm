#include <iostream>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    const int range_start = 1;
    const int range_end = 10000;

    std::cout << "Prime numbers between " << range_start << " and " << range_end << " are:" << std::endl;

    for (int i = range_start; i <= range_end; ++i) {
        if (is_prime(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}

