// Plagrism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Document.h"
#include "HashTable.h"

#include <iostream>
#include <algorithm>
#include <dirent.h>

using namespace std;

struct cheater{
	int collesion;
	string file1;
	string file2;
	
	//Operator overloading for all conditionals
	bool operator==(const cheater& argu){
		return (collesion == argu.collesion && file1 == argu.file1 && file2 == argu.file2);
	}	
	bool operator<(const cheater& argu){
		return collesion < argu.collesion;
	}
	bool operator>(const cheater& argu){
		return collesion > argu.collesion;
	}
	bool operator<=(const cheater& argu){
		return (*this < argu || *this == argu);
	}
	bool operator>=(const cheater& argu){
		return (*this > argu || *this == argu);
	}
	
	//Outputs struct contents to console
	void toString(){
		cout << collesion << ": " << file1 << " and " << file2 << endl;
	}
};

//Priebe code
int getdir(string dir, vector<string> &files)
{
	DIR *dp;
	struct dirent *dirp;
	if ((dp = opendir(dir.c_str())) == NULL) {
		cout << "Error(" << errno << ") opening " << dir << endl;
		return errno;
	}

	while ((dirp = readdir(dp)) != NULL) {
		if(string(dirp->d_name) == ".." || string(dirp->d_name) == ".")
			continue;
			
		files.push_back(string(dirp->d_name));
	}
	closedir(dp);
	return 0;
}

int main(int argc, char * argv[]){
	string mainDir = argv[1];
	vector<string> files;
	getdir(mainDir, files); //reads in the file names from the specified directory

	cout << "Creating Hash Table" << endl;
	HashTable test(100003);
	//inserts each document into the hash table
	for (int i = 0; i < files.size(); i++) {
		Document add(mainDir + "/" + files[i], atoi(argv[2]));
		test.insert(add);
		cout << i + 1 << "/" << files.size() << endl;
	}
	
	cout << "\nChecking for cheaters" << endl;
	vector<struct cheater> list; //vector to hold cheaters
	int count = 0;
	for (int i = 0; i < files.size() - 1; i++) {
		for (int j = i + 1; j < files.size(); j++) {
			//checks all unique file combinations
			int colls = test.getNumCollesion(files[i], files[j]);
			//if collisions is > than specifed a struct is created with 
			//the file names and number of collisions and pushed onto the vector
			if (colls >= atoi(argv[3])) {
				cheater add{colls, files[i], files[j]};
				list.push_back(add);
			}
		}
	}
	
	//the list vector is sorted and outputed to console
	//to reveal the cheaters
	sort(list.begin(), list.end());
	for(int i = list.size()-1; i >= 0; i--){
		list[i].toString();
	}
}
