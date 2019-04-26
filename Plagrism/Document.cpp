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


	int bin = file.find_last_of("\\");
	if (bin != -1) {
		fileName = file.substr(bin+1, file.find_first_of('.', bin));
	}
	else {
		fileName = file.substr(0, file.find_first_of('.'));
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


Document::~Document(){

}
