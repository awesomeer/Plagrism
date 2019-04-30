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
	cout << "Root address: " << root << endl;
	for (int i = 0; i < tableSize; i++) {
		cout << "hash[" << i << "] = " << root[i] << endl;
	}
}


HashTable::~HashTable()
{
}
