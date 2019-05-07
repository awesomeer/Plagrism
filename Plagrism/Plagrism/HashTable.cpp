#include "pch.h"
#include "HashTable.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

HashTable::HashTable() {
	tableSize = 0;
}

HashTable::HashTable(int tableSize) {
	//Checks if tableSize iis greater that the defined maxSize
	if (tableSize > maxSize) {
		this->tableSize = maxSize;
	}
	else {
		this->tableSize = tableSize;
	}
	
	//sets all pointers to nullptr
	for (int i = 0; i < this->tableSize; i++)
		root[i] = nullptr;
}

int HashTable::hash(vector<string> input) {
	long long sum = 0;
	//iterates through all words in the chunk
	for (string s : input) {
		if(s.length() == 0)
			continue;
		//iterates through each character in each word
		for (int i = 0; i < s.length() - 1; i++)
			sum += s[i] * s[i + 1]; //hash function
			//sum += s[s.length()-i-1]*pow(37,i);
	}
	
	//makes sure a positve number is returned
	return abs(sum % tableSize);
}

void HashTable::insert(Document insert) {
	for (int i = 0; i < insert.getSequenceLen(); i++) {
		int index = hash(insert[i]);
		HashNode_t * prev = nullptr;
		HashNode_t * curr = root[index];
		
		//checks if there is no list at root[index]
		if (curr == nullptr) {
			curr = new HashNode_t{ insert.getFileName(), nullptr };
			root[index] = curr;
			continue;
		}
		
		//loops until the end of the linked list
		while (curr != nullptr) {
			prev = curr;
			curr = curr->next;
		}
	
		//inserts a new HashNode_t at the end of the list
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
		
		//traverses the linked list and counts how many times
		//compare and to are in the list
		while (pt != nullptr) {
			if (pt->fileName == compare) {
				compareCount++;
			}
			else if (pt->fileName == to) {
				toCount++;
			}

			pt = pt->next;
		}
		
		//adds the min of the two counts to sum
		if(compareCount < toCount)
			sum += compareCount;
		else
			sum += toCount;
	}

	return sum;
}

HashTable::~HashTable(){
	
}
