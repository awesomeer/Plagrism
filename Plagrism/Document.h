#pragma once
#include <string>
#include <vector>

using namespace std;

class Document{
	private:
		vector<string> sequence;
		int numSequence;
		string FileName;

	public:
		Document();
		Document(string file, int n);

		~Document();
};

