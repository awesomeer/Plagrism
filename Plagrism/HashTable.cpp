#include "pch.h"
#include "HashTable.h"
#include <iostream>

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
	int sum = 0;
	for (string s : input) {
		for (int i = 0; i < s.length(); i++)
			sum += s[i];
	}

	return sum % tableSize;
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

		sum += _Min_value(compareCount, toCount);
	}

	return sum;
}

HashTable::~HashTable(){

}
