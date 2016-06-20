#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <istream>
#include <string>

using namespace std;

template <typename Data>
class list{
private:
	struct Node{
	Data data; 
	Node * NextNode;
	};

public:
	typedef struct Node * NewType;

	void print( NewType _pAIL );
	int length( NewType _pAIL );
	bool empty( NewType _pAIL );
	void clear( NewType & _pAIL );
	bool front( NewType _pAIL, int & _retrievedVal );
	bool back( NewType _pAIL, int & _retrievedVal );
	bool pushFront( NewType & _pAIL, int _newVal );
	bool pushBack( NewType & _pAIL, int _newVal );
	bool popFront( NewType & _pAIL, int & _retrievedVal );
	bool popBack( NewType & _pAIL, int & _retrievedVal );
	NewType find( NewType _pAIL, int _targetVal );
	bool insert( NewType & _pAIL, NewType _pAnte, int _newVal );
	bool remove( NewType & _pAIL, NewType _pAnte, int & _retrievedVal );
};

#endif