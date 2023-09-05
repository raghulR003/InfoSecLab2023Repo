#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <set>
#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int num); // Function prototype

int generatePrime() {
    int num;
    while (true) {
        num = rand()%40 + 100;
        if (isPrime(num)) {
            return num;
        }
    }
}

bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int findPrimitiveRoot(int n) {
    if (n <= 2)
        return -1; // No primitive root exists for n<=2

    int totient = n - 1;
    std::set<int> factors;

    // Find all prime factors of totient
    int temp = totient;
    for (int i = 2; i <= sqrt(temp); i++) {
        while (temp % i == 0) {
            factors.insert(i);
            temp /= i;
        }
    }
    if (temp > 1)
        factors.insert(temp);

    // Check potential primitive roots
    for (int i = 2; i <= n; i++) {
        bool isPrimitiveRoot = true;
        for (auto factor : factors) {
            if (gcd(i, totient / factor) == 1) {
                isPrimitiveRoot = false;
                break;
            }
        }
        if (isPrimitiveRoot)
            return i;
    }

    return -1; // No primitive root found
}

int main() {
    int n = generatePrime();
    cout << "Value for n: " << n << endl;
    int p = findPrimitiveRoot(n);
    cout << "Here is the primitive root of n: " << p << endl;
    int X=rand()%15;
    int Y=rand()%59;
    cout << "X: " << X << endl;
    cout << "Y: " << Y << endl;
    int A=(int)pow(p,(X%n));
    int B=(int)pow(p,(Y%n));
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "------------------------" << endl;

    //Public Keys A and B need to be inserted in another txt file
    std::ofstream outputfile("attackerlog.txt");
    outputfile << A << endl << B <<endl;
    outputfile << X << endl << Y <<endl;

    //Man-in-the-middle attack demonstrated now
    //Both public keys are available to the attacker
    //From the log.txt file

    std::ifstream inputfile("actuallog.txt");
    int value1,value2,cmpr1,cmpr2;
    inputfile >> value1;
    inputfile >> value2;

    //Successfully retrieved the public keys (A and B of the other side)

}
