#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <set>
#include <iostream>
#include <fstream>
using namespace std;

//To generate a prime number, i.e., n
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

int generatePrime() {
    int num;
    while (true) {
        num=rand()%40+100;
        if (isPrime(num)) {
            return num;
        }
    }
}

// To find the primitive root, i.e., p
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

    //Create an output stream object
    std::ofstream outputfile;
    outputfile.open("actuallog.txt");

    // Generate a prime number
    int n = generatePrime();
    cout << "Here is the value for n: " << n << endl;

    // Generate the primitive root of n
    int p = findPrimitiveRoot(n);
    cout << "Here is the primitive root of n: " << p << endl;
    cout << "------------------------" << endl;
    
    //Now to generate two keys, one for the sender and another for the receiver
    int X=rand()%21;
    int Y=rand()%56;
    cout << "The private keys, from sender: " << X << endl;
    cout << "The private keys, from receiver: " << Y << endl;
    cout << "------------------------" << endl;

    //Public key generation, i.e., A and B
    int A=(int)pow(p,(X%n));
    int B=(int)pow(p,(Y%n));
    cout << "The public key, from sender: " << A << endl;
    outputfile << A << std::endl;
    cout << "The public key, from receiver: " << B << endl;
    outputfile << B << std::endl;
    outputfile << X << std::endl;
    outputfile << Y << std::endl;
    cout << "------------------------" << endl;

    //Final key generation, k1 and k2
    int k_A=((int)(pow(B,X))%n);
    int k_B=((int)(pow(A,Y))%n);
    cout << "The final key k1, from sender: " << k_A << endl;
    cout << "The final key k2, from receiver: " << k_B << endl;
    cout << "------------------------" << endl;

    outputfile.close();
}