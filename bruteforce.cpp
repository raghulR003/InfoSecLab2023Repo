#include <iostream>
#include <string>
using namespace std;


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
    string encryptedMessage;

    cout << "Enter the encrypted message: ";
    getline(cin, encryptedMessage);

    // Perform brute-force attack
    cout << "Check the results:" << endl;
    for (int shiftKey = 1; shiftKey <= 25; shiftKey++) {
        string decryptedMessage = decrypt(encryptedMessage, shiftKey);
        cout << "Key num " << shiftKey << ": " << decryptedMessage << endl;
    }
    return 0;
}
