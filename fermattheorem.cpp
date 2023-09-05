#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

int modPow(int base, int exponent, int modulus) {
    int result = 1;
    base %= modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent >>= 1;
        base = (base * base) % modulus;
    }

    return result;
}

int main() {
    int p;
    std::cout << "Enter a prime number (p): ";
    std::cin >> p;

    if (!isPrime(p)) {
        std::cout << "Input is not a prime number.\n";
        return 1;
    }

    int a;
    std::cout << "Enter an integer (a) such that 1 <= a < p: ";
    std::cin >> a;

    if (a < 1 || a >= p) {
        std::cout << "Input is out of range.\n";
        return 1;
    }

    int result = modPow(a, p - 1, p);

    if (result == 1) {
        std::cout << "Fermat's Little Theorem is satisfied for a^p-1 % p = 1.\n";
    } else {
        std::cout << "Fermat's Little Theorem is NOT satisfied for a^p-1 % p = " << result << "\n";
    }

    return 0;
}
