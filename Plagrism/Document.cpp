#include "pch.h"
#include "Document.h"
#include <iostream>
#include <fstream>

using namespace std;

Document::Document(){
	filePath = "";
	fileName = "";
}

Document::Document(string file, int n) {
	lenWord = n;


	int bin = file.find_last_of("/");
	if (bin != -1) {
		fileName = file.substr(bin+1);
	}
	else {
		fileName = file;
	}
	filePath = file;



	ifstream inFile;
	inFile.open(file, ios::in);
	
	vector<string> add;
	string temp;
	for (int i = 0; i < n; i++) {
		inFile >> temp;
		add.push_back(temp);
	}
	sequence.push_back(add);




	while (inFile >> temp) {
		add.erase(add.begin());
		add.push_back(temp);
		sequence.push_back(add);
	}
	
	//cout << fileName << endl;
	/*cout << fileName << endl;
	cout << filePath << endl;
	cout << sequence.size() << endl;
	

	for (int i = 0; i < sequence.size(); i++) {
		for (int j = 0; j < sequence[i].size(); j++) {
			cout << sequence[i][j] << " ";
		}
		cout << '\n';
	}*/

}

void Document::outPermutations() {
	for (int i = 0; i < sequence.size(); i++) {
		for (int j = 0; j < lenWord; j++) {
			cout << sequence[i][j] << " ";
		}
		cout << endl;
	}
}

int Document::getSequenceLen() {
	return sequence.size();
}

vector<string> Document::operator [](int x) {
	if (x < sequence.size())
		return sequence[x];
}


Document::~Document(){

}


//Getters and Setters
vector<vector<string>> Document::getSequence() {
	return sequence;
}

int Document::getLenWord() {
	return lenWord;
}

string Document::getFilePath() {
	return filePath;
}

string Document::getFileName() {
	return fileName;
}

void Document::setSequence(vector<vector<string>> set) {
	sequence = set;
}

void Document::setLenWord(int set) {
	lenWord = set;
}

void Document::setFilePath(string set) {
	filePath = set;
}

void Document::setFileName(string set) {
	fileName = set;
}
