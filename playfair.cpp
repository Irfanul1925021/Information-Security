#include <bits/stdc++.h>
using namespace std;
#define SIZE 30
void generateKeyTable(char key[], int ks, char keyT[5][5])
{
	int i, j, k, flag = 0;

	// a 26 character hashmap
	// to store count of the alphabet
	int dicty[26] = { 0 };
	for (i = 0; i < ks; i++) {
		if (key[i] != 'j')
			dicty[key[i] - 97] = 2;
	}

	dicty['j' - 97] = 1;

	i = 0;
	j = 0;

	for (k = 0; k < ks; k++) {
		if (dicty[key[k] - 97] == 2) {
			dicty[key[k] - 97] -= 1;
			keyT[i][j] = key[k];
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}

	for (k = 0; k < 26; k++) {
		if (dicty[k] == 0) {
			keyT[i][j] = (char)(k + 97);
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}
}
void search(char keyT[5][5], char a, char b, int arr[])
{
	int i, j;

	if (a == 'j')
		a = 'i';
	else if (b == 'j')
		b = 'i';

	for (i = 0; i < 5; i++) {

		for (j = 0; j < 5; j++) {

			if (keyT[i][j] == a) {
				arr[0] = i;
				arr[1] = j;
			}
			else if (keyT[i][j] == b) {
				arr[2] = i;
				arr[3] = j;
			}
		}
	}
}
int mod5(int a) { return (a % 5); }
int prepare(char str[], int ptrs)
{
	if (ptrs % 2 != 0) {
		str[ptrs++] = 'z';
		str[ptrs] = '\0';
	}
	return ptrs;
}
void encrypt(char str[], char keyT[5][5], int ps)
{
	int i, a[4];

	for (i = 0; i < ps; i += 2) {

		search(keyT, str[i], str[i + 1], a);

		if (a[0] == a[2]) {
			str[i] = keyT[a[0]][mod5(a[1] + 1)];
			str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
		}
		else if (a[1] == a[3]) {
			str[i] = keyT[mod5(a[0] + 1)][a[1]];
			str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
		}
		else {
			str[i] = keyT[a[0]][a[3]];
			str[i + 1] = keyT[a[2]][a[1]];
		}
	}
}
void encryptByPlayfairCipher(string str, string key)
{   int key;
    cin>>key;
	string ps, ks;
	char keyT[5][5];
	key.erase(remove(key.begin(), key.end(), ' '), key.end());
	ks=transform(key.begin(), key.end(), key.begin(), ::tolower);

	// Plaintext
	ps = strlen(str);
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	ps=transform(str.begin(), str.end(), str.begin(), ::tolower);;
	ps = prepare(str, ps);
	generateKeyTable(key, ks, keyT);

	encrypt(str, keyT, ps);
}
int main()
{
	string str,key;
	cout<<"Enter String : ";
	getline(cin,str);
	cout<<"Enter Key : ";
		getline(cin,key);
	encryptByPlayfairCipher(str, key);

	cout << "Cipher text: " << str << "\n";
	return 0;
}
