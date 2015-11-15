#ifndef NODE_H
#define NODE_H
 
#include <iostream>
 
using namespace std;
 
template <class T>
 
class Node
{
	public:
	        Node *next;
	        T data;
	
	        Node();
	        Node(T);
	        ~Node();
	 
	        void delete_all();
	        void print();

};
 
#endif
