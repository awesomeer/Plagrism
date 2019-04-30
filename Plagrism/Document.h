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
		void outPermutations();


		vector<vector<string>> getSequence();
		int getLenWord();
		string getFilePath();
		string getFileName();

		void setSequence(vector<vector<string>> set);
		void setLenWord(int set);
		void setFilePath(string set);
		void setFileName(string set);

		vector<string> operator [](int x);

		~Document();
};

