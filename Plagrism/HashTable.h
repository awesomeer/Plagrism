#pragma once
#include <vector>
#include <string>

using namespace std;

class HashTable{
	public:
		HashTable();
		HashTable(int size);
		void insert(vector<string>, string);
		int getNumCollesion(string, string);
		~HashTable();

	private:
		typedef struct HashNode {
			string fileName;
			int fileIndex;
			struct HashNode * next;
		}HashNode_t;

		int hash(vector<string>);

		HashNode_t ** root;
		int tableSize;

};

