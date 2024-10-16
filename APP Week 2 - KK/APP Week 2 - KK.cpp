#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>

using namespace std;


string removePunc(const string& word) {
	string newWord = "";
	for (char ch : word) {
		if (!ispunct(ch)) {
			newWord += ch;
		}
	}
	return newWord;
}

void printSummary(const string& filename) {

	ifstream readFile(filename);
	if (!readFile) {
		cerr << "File Cannot Be Opened. " << filename << endl;
		return;
	}


	unordered_map<string, int> WordFreqPair;
	int numberofSentences = 0;
	int numberofWords = 0;

	string line;

	while (getline(readFile, line)) {
		stringstream ss(line);
		string word;

		while (ss >> word) {
			for (char ch : word) {
				if (ch == '.' || ch == '!' || ch == '?') {
					numberofSentences++;
				}
			}
			word = removePunc(word);
			if (!word.empty()) {
				for (char& ch : word) {
					ch = tolower(ch);
				}
			}
			WordFreqPair[word]++;
			numberofWords++;
		}
	}
	readFile.close();
	cout << "Number of Sentences: " << numberofSentences << endl;
	cout << "Number of Words : " << numberofWords << endl;
	
	for (const auto& pair : WordFreqPair) {
		cout << pair.first << " " << pair.second << endl;
	}
}


int main()
{
	string filename;
	cout << "Enter filename: ";
	getline(cin, filename);
	printSummary(filename);
	return 0;
}