test: HashTable.o Document.o Plagrism.o
	g++ -std=c++11 -o test HashTable.o Document.o Plagrism.o
	rm *.o
HashTable.o: HashTable.cpp
	g++ -std=c++11 -c HashTable.cpp
Document.o: Document.cpp
	g++ -std=c++11 -c Document.cpp
Plagrism.o: Plagrism.cpp
	g++ -std=c++11 -c Plagrism.cpp
