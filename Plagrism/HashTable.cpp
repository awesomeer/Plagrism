#include "pch.h"
#include "HashTable.h"
#include <iostream>
#include <string>

using namespace std;

HashTable::HashTable() {
	tableSize = 0;
}

HashTable::HashTable(int tableSize) {
	if (tableSize > maxSize) {
		this->tableSize = maxSize;
	}
	else {
		this->tableSize = tableSize;
	}

	for (int i = 0; i < this->tableSize; i++)
		root[i] = nullptr;
}

int HashTable::hash(vector<string> input) {
	long long sum = 0;
	for (string s : input) {
		if(s.length() == 0)
			continue;

		for (int i = 0; i < s.length() - 1; i++)
			sum += s[i] * s[i + 1];
	}

	return abs(sum % tableSize);
}

void HashTable::insert(Document insert) {
	for (int i = 0; i < insert.getSequenceLen(); i++) {
		int index = hash(insert[i]);
		HashNode_t * prev = nullptr;
		HashNode_t * curr = root[index];

		if (curr == nullptr) {
			curr = new HashNode_t{ insert.getFileName(), nullptr };
			root[index] = curr;
			continue;
		}

		while (curr != nullptr) {
			prev = curr;
			curr = curr->next;
		}

		curr = new HashNode_t{ insert.getFileName(), nullptr };
		if (prev != nullptr) {
			prev->next = curr;
		}
	}
}

int HashTable::getNumCollesion(string compare, string to) {
	int sum = 0;
	for (int i = 0; i < tableSize; i++) {
//cout << compare << " " << to << " " << i << endl;
		int compareCount = 0;
		int toCount = 0;
		HashNode_t * pt = root[i];
		
		if (pt == nullptr)
			continue;

		while (pt != nullptr) {
			if (pt->fileName == compare) {
				compareCount++;
			}
			else if (pt->fileName == to) {
				toCount++;
			}

			pt = pt->next;
		}
//cout << compareCount << " " << toCount << endl;
		if(compareCount < toCount)
			sum += compareCount;
		else
			sum += toCount;
//		sum += _Min_value(compareCount, toCount);
	}

	return sum;
}

HashTable::~HashTable(){
//	for(int i = 0; i < tableSize; i++){
//		cout << root[i] << endl;
//	}
	cout << "tableSize " << tableSize << endl;
}
