
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;
char keyMatrix[SIZE][SIZE];

// function to generate the key matrix
void generateKeyMatrix(string key)
{
    // stores the characters of the key
    char keyChars[SIZE * SIZE];

    // variable to store the current position in the key matrix
    int currentPos = 0;

    // variable to store the current position in the key string
    int keyPos = 0;

    // loop through the key string and store unique characters in the keyChars array
    while (keyPos < key.length())
    {
        bool alreadyExists = false;
        char currentChar = key[keyPos];

        // loop through the keyChars array to check if the current character already exists
        for (int i = 0; i < currentPos; i++)
        {
            if (keyChars[i] == currentChar)
            {
                alreadyExists = true;
                break;
            }
        }

        // if the current character doesn't already exist in the keyChars array, add it
        if (!alreadyExists)
        {
            keyChars[currentPos] = currentChar;
            currentPos++;
        }

        keyPos++;
    }

    // add remaining characters of the alphabet to the keyChars array
    for (int i = 'A'; i <= 'Z'; i++)
    {
        bool alreadyExists = false;

        // loop through the keyChars array to check if the current character already exists
        for (int j = 0; j < currentPos; j++)
        {
            if (keyChars[j] == i)
            {
                alreadyExists = true;
                break;
            }
        }

        // if the current character doesn't already exist in the keyChars array, add it
        if (!alreadyExists)
        {
            keyChars[currentPos] = i;
            currentPos++;
        }
    }

    // fill the key matrix
    int keyCharPos = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            keyMatrix[i][j] = keyChars[keyCharPos];
            keyCharPos++;
        }
    }
}

// function to get the position of a character in the key matrix
void getCharPos(char c, int &x, int &y)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (keyMatrix[i][j] == c)
            {
                x = i;
                y = j;
                return;
            }
        }
    }
}

// function to encrypt the plaintext
string encrypt(string plaintext)
{
    // variable to store the current position in the plaintext
    int plaintextPos = 0;

    // variable to store the current position in the ciphertext
    int ciphertextPos = 0;

    // variable to store the ciphertext

    string ciphertext(plaintext.length(), ' ');

    while (plaintextPos < plaintext.length())
{
    // get the first character of the pair
    char firstChar = plaintext[plaintextPos];

    // if the first character is 'X', add 'Z' after it
    if (firstChar == 'X')
    {
        ciphertext[ciphertextPos] = firstChar;
        ciphertextPos++;
        ciphertext[ciphertextPos] = 'Z';
        plaintextPos++;
    }
    else
    {
        // get the second character of the pair
        plaintextPos++;
        if (plaintextPos >= plaintext.length())
        {
            ciphertext[ciphertextPos] = firstChar;
            ciphertextPos++;
            ciphertext[ciphertextPos] = 'X';
            plaintextPos++;
        }
        else
        {
            char secondChar = plaintext[plaintextPos];

            // if the second character is 'X', add 'Z' after it
            if (secondChar == 'X')
            {
                ciphertext[ciphertextPos] = firstChar;
                ciphertextPos++;
                ciphertext[ciphertextPos] = 'Z';
                plaintextPos++;
            }
            else
            {
                // if the characters are the same, add 'X' after the first character
                if (firstChar == secondChar)
                {
                    ciphertext[ciphertextPos] = firstChar;
                    ciphertextPos++;
                    ciphertext[ciphertextPos] = 'X';
                    plaintextPos++;
                }
                else
                {
                    // get the position of the characters in the key matrix
                    int firstCharX, firstCharY, secondCharX, secondCharY;
                    getCharPos(firstChar, firstCharX, firstCharY);
                    getCharPos(secondChar, secondCharX, secondCharY);

                    // if the characters are in the same row
                    if (firstCharX == secondCharX)
                    {
                        ciphertext[ciphertextPos] = keyMatrix[firstCharX][(firstCharY + 1) % SIZE];
                        ciphertextPos++;
                        ciphertext[ciphertextPos] = keyMatrix[secondCharX][(secondCharY + 1) % SIZE];
                        plaintextPos++;
                    }
                    // if the characters are in the same column
                    else if (firstCharY == secondCharY)
                    {
                        ciphertext[ciphertextPos] = keyMatrix[(firstCharX + 1) % SIZE][firstCharY];
                        ciphertextPos++;
                        ciphertext[ciphertextPos] = keyMatrix[(secondCharX + 1) % SIZE][secondCharY];
                        plaintextPos++;
                    }
                    // if the characters form a rectangle
                    else
                    {
                        ciphertext[ciphertextPos] = keyMatrix[firstCharX][secondCharY];
                        ciphertextPos++;
                        ciphertext[ciphertextPos] = keyMatrix[secondCharX][firstCharY];
                        plaintextPos++;
                    }
                }
            }
        }
    }
}

            return ciphertext;
}

string decrypt(string ciphertext)
{
// variable to store the current position in the ciphertext
    int ciphertextPos = 0;

    // variable to store the current position in the plaintext
    int plaintextPos = 0;

    // variable to store the plaintext
    string plaintext(ciphertext.length(), ' ');

    while (ciphertextPos < ciphertext.length())
    {
        // get the first character of the pair
        char firstChar = ciphertext[ciphertextPos];

        // get the second character of the pair
        ciphertextPos++;
        char secondChar = ciphertext[ciphertextPos];

        // get the position of the characters in the key matrix
        int firstCharX, firstCharY, secondCharX, secondCharY;
        getCharPos(firstChar, firstCharX, firstCharY);
        getCharPos(secondChar, secondCharX, secondCharY);

        // if the characters are in the same row
        if (firstCharX == secondCharX)
        {
            plaintext[plaintextPos] = keyMatrix[firstCharX][(firstCharY - 1 + SIZE) % SIZE];
            plaintextPos++;
            plaintext[plaintextPos] = keyMatrix[secondCharX][(secondCharY - 1 + SIZE) % SIZE];
            ciphertextPos++;
        }
        // if the characters are in the same column
        else if (firstCharY == secondCharY)
        {
            plaintext[plaintextPos] = keyMatrix[(firstCharX - 1 + SIZE) % SIZE][firstCharY];
            plaintextPos++;
            plaintext[plaintextPos] = keyMatrix[(secondCharX - 1 + SIZE) % SIZE][secondCharY];
            ciphertextPos++;
        }
        // if the characters form a rectangle
        else
        {
            plaintext[plaintextPos] = keyMatrix[firstCharX][secondCharY];
            plaintextPos++;
            plaintext[plaintextPos] = keyMatrix[secondCharX][firstCharY];
            ciphertextPos++;
        }
    }

    return plaintext;
}




int main()
{
    string key;
    cout << "Enter the key: ";
    cin >> key;


    generateKeyMatrix(key);

    string plaintext;
    cout << "Enter the plaintext: ";
    cin >> plaintext;

    string ciphertext = encrypt(plaintext);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedPlaintext = decrypt(ciphertext);
    cout << "Decrypted plaintext: " << decryptedPlaintext << endl;

    return 0;
}
