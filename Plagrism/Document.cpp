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

	/*cout << filePath << endl;
	cout << sequence.size() << endl;
	cout << fileName << endl;

	for (int i = 0; i < sequence.size(); i++) {
		for (int j = 0; j < sequence[i].size(); j++) {
			cout << sequence[i][j] << " ";
		}
		cout << '\n';
	}*/

}


Document::~Document(){

}
