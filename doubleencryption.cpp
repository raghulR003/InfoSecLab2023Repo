#include <iostream>
#include <string>
using namespace std;

string CaesarEncrypt(string message) {
    string encryptedMsg = "";
    for (char ch : message) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            encryptedMsg += char((ch - base + 3) % 26 + base);
        } else {
            encryptedMsg += ch;
        }
    }
    return encryptedMsg;
}

string CaesarDecrypt(string message) {
    string decryptedMsg = "";
    for (char ch : message) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            decryptedMsg += char((ch - base - 3 + 26) % 26 + base);
        } else {
            decryptedMsg += ch;
        }
    }
    return decryptedMsg;
}

string XOREncryption(string keytext, string caesarCiphertext) {
    int size = 0;
    while (size < caesarCiphertext.length()) {
        size += keytext.length();
    }
    while (caesarCiphertext.length() < size) {
        caesarCiphertext += 'X';
    }
    string encryptedText = "";
    for (int i = 0; i < size; i++) {
        char cipherChar = caesarCiphertext[i];
        char keyChar = keytext[i % keytext.length()];
        char encryptedChar = cipherChar ^ keyChar;
        encryptedText += encryptedChar;
    }
    return encryptedText;
}

int main() {
    string plaintext;
    string keytext;
    cout << "Enter message to be encrypted: ";
    getline(cin, plaintext);
    
    // Starting the first level of encryption
    string caesarCiphertext = CaesarEncrypt(plaintext);
    cout << "Encrypted Caesar Ciphertext: " << caesarCiphertext << endl;
    
    // Starting the second level of encryption: the XOR encryption
    cout << "Enter the XOR encryption key: ";
    getline(cin, keytext);
    string finalEncryption = XOREncryption(keytext, caesarCiphertext);
    cout << "Final Encryption text: " << finalEncryption << endl;
    
    // Initial Decryption
    cout << "Enter the XOR decryption key: ";
    getline(cin, keytext);
    
    string decrypt1 = XOREncryption(keytext, finalEncryption);
    cout << "Intermediate Decryption: " << decrypt1 << endl;
    
    // Perform Caesar decryption on the intermediate result
    string caesarPlaintext = CaesarDecrypt(decrypt1);
    cout << "Decrypted Caesar Ciphertext: " << caesarPlaintext << endl;
    
    return 0;
}
