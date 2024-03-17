#include <iostream>
#include <bitset>
#include <vector>
#include "DES.h"

using namespace std;

string toUpperString(string str);
vector<string> splitString(const string& str);

int main()
{
	cout << "Enter text:";
	string text;
	getline(cin, text);
	text = toUpperString(text);
	vector<string> asd = splitString(text);
	string key;
	do
	{
		cout << "Enter key:";
		cin >> key;
		if (key.size() <= 8) break;
	} while (true);
	key = toUpperString(key);
	bitset<64> bitTestKey = convertStringToBitset(key);
	vector<bitset<48>> vecBitTestKey = keyGeneration(bitTestKey);
	string deryptedText = "";
	string cryptedText = "";
	for (int i = 0; i < asd.size(); i++)
	{
		bitset<64> bitTestPart = convertStringToBitset(asd[i]);
		bitset<64> cryptedTextBitPart = encrypt(bitTestPart, vecBitTestKey);
		bitset<64> deryptedTextBitPart = decrypt(cryptedTextBitPart, vecBitTestKey);
		string deryptedTextPart = bitsetToString(deryptedTextBitPart);
		string cryptedTextPart = bitsetToString(cryptedTextBitPart);
		deryptedText += deryptedTextPart;
		cryptedText += cryptedTextPart;
	}

	cout << /*"crypted text - " <<*/ cryptedText << endl << endl;
	cout << "decrypted text - " << deryptedText << endl << endl;

}

string toUpperString(string str)
{
	string newStr = "";
	for (char c : str)
	{
		c = toupper(c);
		newStr.push_back(c);
	}
	return newStr;
}

vector<string> splitString(const string& str) {
	vector<string> result;

	for (size_t i = 0; i < str.size(); i += 8) {
		result.push_back(str.substr(i, 8));
	}

	return result;
}
