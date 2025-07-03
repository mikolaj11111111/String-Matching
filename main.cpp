#include<iostream>
#include<string>
#include <cctype>
#include <algorithm>

using namespace std;

void NaiveAlg(string text, string pattern) {
	int text_len = text.length();
	int pattern_len = pattern.length();

	for (int i = 0; i <= text_len - pattern_len; i++) {

		string similar = "";

		for (int j = 0; j < pattern_len; j++) {
			if (text[i + j] != pattern[j]) {
				cout << "no pattern for index: " << i << endl;
				break;
			}
			else {
				similar += text[i + j];
			}
			cout << "similarity found in index: " << i  << " pattern: " << similar << endl;
		}
	}
}

int HashPattern(string pattern) {
	
	int pattern_len = pattern.length();

	int pattern_sum = 0;

	for (int j = 0; j < pattern_len; j++) {
		if (j == pattern_len - 1) {
			pattern_sum += (pattern[j] - 65);
		}
		else if (j == 0) {
			pattern_sum += (pattern[j] - 65) * 10;
		}
		else {
			pattern_sum += pattern[j] - 65;
			pattern_sum *= 10;
		}
	}
	int hash_pattern = pattern_sum % 13;
	cout << "Pattern sum is " << pattern_sum << " and hash_pattern: " << hash_pattern << " and pattern: " << pattern << endl;

	return hash_pattern;
}



void RabinKarpAlg(int hash, string text, string pattern) {
	int text_len = text.length();
	int pattern_len = pattern.length();

	for (int i = 0; i <= text_len - pattern_len; i++) {

		int pattern_sum = 0;
		string similar = "";

		for (int j = 0; j < pattern_len; j++) {
				if (j == pattern_len - 1) {
					pattern_sum += (text[i + j] -65);
				}
				else if (j == 0) {
					pattern_sum += (text[i + j] - 65) * 10;
				}
				else {
					pattern_sum += text[i + j] - 65;
					pattern_sum *= 10;
				}
				similar += text[i + j];
				//cout << "Pattern sum for index: " << i << " and " << j << " is " << pattern_sum << endl;
				
		}

		int hash_pattern = pattern_sum % 13;
		if (hash == hash_pattern && similar == pattern) {
			cout << "!!!!" << endl;
			cout << "Pattern sum for index: " << i << " is " << pattern_sum << " and hash_pattern: " << hash_pattern << " and pattern: " << pattern << endl;
			cout << "!!!!" << endl;

		}
	}
}

string TransformToUpper(string text) {

	transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
		return toupper(c);
		});
	return text;
}



int main() {

	string text = "aabaacaadaabaaba";
	string pattern = "aaba";
	
	text = TransformToUpper(text);
	pattern = TransformToUpper(pattern);

	//Naive Algoritm
	//NaiveAlg(text, pattern);

	//Rabin-Karp Algoritm
	int hash_pattern = HashPattern(pattern);

	RabinKarpAlg(hash_pattern, text, pattern);



	return 0;
}
