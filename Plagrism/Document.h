#pragma once
#include <string>
#include <vector>

using namespace std;

class Document{
	private:
		vector<vector<string>> sequence;
		int lenWord;
		string filePath;
		string fileName;

	public:
		Document();
		Document(string file, int n);

		~Document();
};

