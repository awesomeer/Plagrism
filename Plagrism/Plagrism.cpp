// Plagrism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Document.h"
#include "HashTable.h"

#include <iostream>
#include <dirent.h>

using namespace std;

int getdir(string dir, vector<string> &files)
{
	DIR *dp;
	struct dirent *dirp;
	if ((dp = opendir(dir.c_str())) == NULL) {
		cout << "Error(" << errno << ") opening " << dir << endl;
		return errno;
	}

	while ((dirp = readdir(dp)) != NULL) {
		files.push_back(string(dirp->d_name));
	}
	closedir(dp);
	return 0;
}

void hashDocuments(vector<Document> docs, HashTable &hash) {
	for (Document doc : docs) {
		for (int i = 0; i < doc.getSequence().size(); i++) {
			hash.insert(doc[i], doc.getFileName());
		}
	}
}

int main(int argc, char * argv[]){
	string mainDir = argv[1];
	vector<string> files;
	getdir(mainDir, files);
	files.erase(files.begin(), files.begin() + 2); //gets rid of . and .. dir

	
	vector<Document> docs;
	for (int i = 0; i < files.size(); i++) {
		Document add(mainDir + '\\' + files[i], 10);
		docs.push_back(add);
	}

	HashTable test(10000);
	//hashDocuments(docs, test);

	for (int i = 0; i < docs[6].getSequence().size(); i++) {
		test.insert(docs[6][i], docs[6].getFileName());
	}
	for (int i = 0; i < docs[8].getSequence().size(); i++) {
		test.insert(docs[8][i], docs[8].getFileName());
	}
	cout << test.getNumCollesion(docs[6].getFileName(), docs[8].getFileName());
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
