#include <iostream>
#include <string>
using namespace std;

string Encrypt(string message, int key) {
    string encryptedMessage = "";

    for (char ch : message) {
        if (isupper(ch)) {
            encryptedMessage += char(int(ch + key - 65) % 26 + 65);
        }
        else if (islower(ch)) {
            encryptedMessage += char(int(ch + key - 97) % 26 + 97);
        }
        else {
            encryptedMessage += ch;
        }
    }
    return encryptedMessage;
}

int main() {
    string plaintext;
    int key;
    cout << "Enter the plaintext message: ";
    getline(cin, plaintext);
    //Setting key to be 3 (for Ceasar Cipher)
    key=3;
    string ciphertext = Encrypt(plaintext, key);
    cout << "Encrypted ciphertext: " << ciphertext << endl;
    return 0;
}
