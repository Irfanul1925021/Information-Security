
#include <iostream>
#include <string>

using namespace std;

// Key matrix
int key[3][3] = {{7, 8, 11}, {11, 12, 0}, {6, 8, 2}};

// Function to encrypt plain text
string encrypt(string plainText) {
    int length = plainText.length();

    if (length % 3 != 0) {
        plainText.append(3 - (length % 3), 'X');
    }

    string cipherText = "";

    for (int i = 0; i < plainText.length(); i += 3) {

        int plainTextMatrix[3][1] = {{plainText[i] - 'A'}, {plainText[i + 1] - 'A'}, {plainText[i + 2] - 'A'}};

        int cipherTextMatrix[3][1] = {};

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 1; k++) {
                for (int l = 0; l < 3; l++) {
                    cipherTextMatrix[j][k] += key[j][l] * plainTextMatrix[l][k];
                }
            }
        }

        cipherText += (char) ((cipherTextMatrix[0][0] % 26) + 'A');
        cipherText += (char) ((cipherTextMatrix[1][0] % 26) + 'A');
        cipherText += (char) ((cipherTextMatrix[2][0] % 26) + 'A');
    }
    return cipherText;
}

int main() {
    string msg="GFG";
    string cipherText = encrypt(msg);
    cout << "Cipher text: " << cipherText << endl;

    // Decryption
    //cout << "Decrypted plain text: " << decrypt(cipherText) << endl;

    return 0;
}
