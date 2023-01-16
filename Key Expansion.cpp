#include <iostream>
#include <array>

using namespace std;

const int Nb = 4; // Number of columns (32-bit words) comprising the State. For AES, it is always 4.
const int Nk = 4; // Number of 32-bit words comprising the Cipher Key. For AES-128, it is always 4.
const int Nr = 9 + 1; // Number of rounds. 9 rounds for AES-128

// AES-128 uses a fixed s-box
unsigned char sbox[256] = { /* S-box values */ };

// Rijndael Rcon
unsigned char Rcon[11] = { 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 };

// Key schedule array
unsigned char keySchedule[Nb*(Nr+1)];

// Function to perform key expansion
void KeyExpansion(unsigned char key[Nk*4])
{
    // First Nk columns of the key schedule are filled with the cipher key
    for (int i = 0; i < Nk*4; i++)
        keySchedule[i] = key[i];

    // All other columns are filled via the key expansion algorithm
    for (int i = Nk; i < Nb*(Nr+1); i++)
    {
        unsigned char temp[4];

        // Copy the previous 32-bit word
        for (int j = 0; j < 4; j++)
            temp[j] = keySchedule[(i-1)*4 + j];

        // Perform the key schedule core
        if (i % Nk == 0)
        {
            // Rotate the 32-bit word
            unsigned char t = temp[0];
            temp[0] = temp[1];
            temp[1] = temp[2];
            temp[2] = temp[3];
            temp[3] = t;

            // Apply the Rijndael S-box to each byte
            temp[0] = sbox[temp[0]];
            temp[1] = sbox[temp[1]];
            temp[2] = sbox[temp[2]];
            temp[3] = sbox[temp[3]];

            // Apply the round constant
            temp[0] ^= Rcon[i/Nk];
        }

        // XOR the 32-bit word with the previous key schedule word
        for (int j = 0; j < 4; j++)
            keySchedule[i*4 + j] = keySchedule[(i-Nk)*4 + j] ^ temp[j];
    }
}

