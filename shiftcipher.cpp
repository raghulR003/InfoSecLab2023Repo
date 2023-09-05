#include <iostream>
#include <string>
using namespace std;

string encrypt(string plaintext, int shift) {
    string encryptedText = "";
    for (size_t i = 0; i < plaintext.length(); i++) {
        if (isupper(plaintext[i]))
            encryptedText += char(int(plaintext[i] + shift - 65) % 26 + 65);
        else if (islower(plaintext[i]))
            encryptedText += char(int(plaintext[i] + shift - 97) % 26 + 97);
        else
            encryptedText += plaintext[i];
    }
    return encryptedText;
}

string decrypt(string ciphertext, int shift) {
    string decryptedText = "";
    for (size_t i = 0; i < ciphertext.length(); i++) {
        if (isupper(ciphertext[i]))
            decryptedText += char(int(ciphertext[i] - shift - 65 + 26) % 26 + 65);
        else if (islower(ciphertext[i]))
            decryptedText += char(int(ciphertext[i] - shift - 97 + 26) % 26 + 97);
        else
            decryptedText += ciphertext[i];
    }
    return decryptedText;
}

int main() {
    int shiftKey;
    string message;

    cout << "Enter the message to encrypt: ";
    getline(cin, message);

    cout << "Enter the shift key: ";
    cin >> shiftKey;

    // Encryption part
    string encryptedMessage = encrypt(message, shiftKey);
    cout << "Encrypted message: " << encryptedMessage << endl;

    // Decryption part
    string decryptedMessage = decrypt(encryptedMessage, shiftKey);
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}
