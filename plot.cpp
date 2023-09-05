#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using BigInteger = mp::cpp_int;

bool isPrime(const BigInteger &num) {
    if (num <= 1)
        return false;

    for (BigInteger i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

BigInteger generatePrime() {
    BigInteger num;
    while (true) {
        num = rand() % 415 + 1;
        if (isPrime(num)) {
            return num;
        }
    }
}

BigInteger modExp(const BigInteger &base, const BigInteger &exponent, const BigInteger &modulus) {
    if (exponent == 0)
        return 1;

    if (exponent % 2 == 0) {
        BigInteger temp = modExp(base, exponent / 2, modulus);
        return (temp * temp) % modulus;
    } else {
        return (base * modExp(base, exponent - 1, modulus)) % modulus;
    }
}

int main() {
    srand(time(NULL));

    BigInteger p = generatePrime();
    BigInteger q = generatePrime();

    std::cout << "Here is the value for p: " << p << std::endl;
    std::cout << "Here is the value for q: " << q << std::endl;
    std::cout << "------------------------" << std::endl;

    BigInteger n = p * q;
    std::cout << "Here is the value for n: " << n << std::endl;
    std::cout << "------------------------" << std::endl;

    BigInteger tot = (p - 1) * (q - 1);
    std::cout << "Here is the totient value for n: " << tot << std::endl;
    std::cout << "------------------------" << std::endl;

    BigInteger copr = 3; // Assuming 3 as the coprime value
    std::cout << "Here is the coprime value for n: " << copr << std::endl;
    std::cout << "------------------------" << std::endl;

    BigInteger privKey = 0;
    while (true) {
        if ((copr * privKey) % tot == 1) {
            break;
        }
        privKey++;
    }
    std::cout << "Here is the private key value for n: " << privKey << std::endl;
    std::cout << "------------------------" << std::endl;

    std::cout << "Now enter the message to be encrypted: ";
    BigInteger m;
    std::cin >> m;

    BigInteger encryption = modExp(m, copr, n);
    BigInteger decryption = modExp(encryption, privKey, n);

    std::cout << "Here is the encrypted value: " << encryption << std::endl;
    std::cout << "Here is the decrypted value: " << decryption << std::endl;

    return 0;
}
