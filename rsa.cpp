#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <set>
using namespace std;

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
        num=rand()%43+49;
        if (isPrime(num)) {
            return num;
        }
    }
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int coprime(int n){
    int flag=0;
    for(int i=3;i<n;i++){
        if(gcd(n,i)==1){
            return i;
            break;
        }
    }
    return 0;
}

int privateKey(int copr, int tot){
    //e x d === 1 mod tot value
    for(int i=2;i<=1000000;i++){
        int val=(copr*i)%tot;
        if(val==1){
            return i;
            break;
        }
        else continue;
    }
    return 0;
}

int modExp(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main(){
    
    int p=23;
    int q=27;
    cout << "Here is the value for p: " << p << endl;
    cout << "Here is the value for q: " << q << endl;
    cout << "------------------------" << endl;
    int n=p*q;
    cout << "Here is the value for n: " << n << endl;
    cout << "------------------------" << endl;
    int tot=(p-1)*(q-1);
    cout << "Here is the totient value for n: " << tot << endl;
    cout << "------------------------" << endl;
    int copr=coprime(n);
    cout << "Here is the coprime value for n: " << copr << endl;
    cout << "------------------------" << endl;
    int privKey=privateKey(copr,tot);
    cout << "Here is the private key value for n: " << privKey << endl;
    cout << "------------------------" << endl;
    cout << "Now enter the message to be encrypted: "; int m;
    cin >> m;
    int encryption=modExp(m,copr,n);
    int decryption=modExp(encryption,privKey,n);
    cout << "Here is the encrypted value: " << encryption << endl;
    cout << "Here is the decrypted value: " << decryption << endl;  
}