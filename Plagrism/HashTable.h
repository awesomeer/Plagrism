#pragma once
#include "Document.h"
#include <vector>
#include <string>
#define maxSize 12547
using namespace std;

class HashTable{
	public:
		HashTable();
		HashTable(int size);
		void insert(Document);
		int getNumCollesion(string, string);
		~HashTable();

	private:
		typedef struct HashNode {
			string fileName;
			struct HashNode * next;
		}HashNode_t;

		int hash(vector<string>);

		HashNode_t * root[maxSize];
		int tableSize;

};

