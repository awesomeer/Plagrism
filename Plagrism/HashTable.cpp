#include "pch.h"
#include "HashTable.h"

#include <iostream>

HashTable::HashTable() {
	tableSize = 0;
	root = nullptr;
}

HashTable::HashTable(int tableSize) {
	this->tableSize = tableSize;
	root = (HashNode_t **)malloc(sizeof(HashNode_t *) * this->tableSize);
	for (int i = 0; i < tableSize; i++)
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

void HashTable::insert(vector<string> input, string fileName) {
	int index = hash(input);
	HashNode_t * temp = root[index];

	while (temp != nullptr) {
		temp = temp->next;
	}

	if (temp == nullptr) {
		temp = new HashNode_t;
		temp->fileName = fileName;
		temp->next = nullptr;
	}
}

int HashTable::getNumCollesion(string compare, string to) {
	int sum = 0;
	for (int i = 0; i < tableSize; i++) {
		int compareCount = 0;
		int toCount = 0;
		HashNode_t * index = root[i];

		while (index != nullptr) {
			if (index->fileName == compare) {
				compareCount++;
			}
			else if (index->fileName == to) {
				toCount++;
			}
			index = index->next;
		}

		if (compareCount > 0) {
			sum += toCount;
		}
	}

	return sum;
}

HashTable::~HashTable(){

}
