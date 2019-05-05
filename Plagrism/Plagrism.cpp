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

void insertDocs(vector<Document> docs, HashTable &hash) {
	for (int i = 0; i < docs.size(); i++) {
		hash.insert(docs[i]);
	}
}

int main(int argc, char * argv[]){
	string mainDir = argv[1];
	vector<string> files;
	getdir(mainDir, files);
	files.erase(files.begin(), files.begin() + 2); //gets rid of . and .. dir

	
	vector<Document> docs;
	for (int i = 0; i < files.size(); i++) {
		Document add(mainDir + '\\' + files[i], atoi(argv[2]));
		docs.push_back(add);
	}

	HashTable test(10000);
	insertDocs(docs, test);

	for (int i = 0; i < docs.size()-1; i++) {
		for (int j = i + 1; j < docs.size(); j++) {
			cout << test.getNumCollesion(docs[i].getFileName(), docs[j].getFileName()) << endl;
		}
	}

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
