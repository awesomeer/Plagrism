#pragma once
#include <vector>
#include <string>

using namespace std;

class HashTable{
	public:
		HashTable();
		HashTable(int size);
		~HashTable();

	private:
		typedef struct HashNode {
			vector<string> data;
			struct HashNode * next;
		}HashNode_t;

		HashNode_t ** root;
		int tableSize;

};

