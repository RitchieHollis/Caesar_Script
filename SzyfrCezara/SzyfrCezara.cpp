// SzyfrCezara.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>

using namespace std;
/*
tekst -> A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
szyfr -> D E F G H I J K L M N O P Q R S T U V W X Y Z A B C

Without using temporary variables
*/

string crypting(string);
string decrypting(string);

const unsigned int key = 4;

int main()
{
	string word;

	cout << "Gimme word to crypt" << endl;
	cin >> word;

	cout << "Crypted word: " << crypting(word) << endl;
	cout << "Decrypted word: " << decrypting(crypting(word)) << endl;

	return EXIT_SUCCESS;
}
string crypting(string word) {

	for (int i = 0; i < word.length(); i++) {
		
		if (word[i] < 65 || word[i] > 122) {
			return "Blad, uzywaj tylko liter";
		}

		if (word[i] < 91) {
			if (word[i] < (91 - key)) {
				word[i] += key;
			}
			else {
				word[i] -= (26 - key);
			}
		}
		if (word[i] >= 97) {
			if (word[i] < (123 - key)) {
				word[i] += key;
			}
			else {
				word[i] -= (26 - key);
			}
		}
	}
	return word;
}

string decrypting(string word) {
	
	for (int i = 0; i < word.length(); i++) {

		if (word[i] < 65 || word[i] > 122) {
			return "Blad, uzywaj tylko liter";
		}

		if (word[i] < 97) {
			if (word[i] > (64 + key)) {
				word[i] -= key;
			}
			else {
				word[i] += (26 - key);
			}
		}
		if (word[i] >= 97) {
			if (word[i] > (96 + key)) {
				word[i] -= key;
			}
			else {
				word[i] += (26 - key);
			}
		}
	}
	return word;
}
