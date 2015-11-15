#ifndef LIST_H
#define LIST_H
 

#include <iostream>
#include "node.h"
#include "node.cpp"
 
using namespace std;
 
template <class T>
 
class List
{
	private:
		Node<T> *m_head;
		int m_num_nodes;

	public:
	        List();
	        ~List();
 
		void add_head(T);
		void add_end(T);
		void concat(List);
		void del_all();
		void del_by_data(T);
		void del_by_position(int);
		void fill_by_user(int);
		void nointersection(List);
		int search(T);
		void invert();
		void print();
		void sort();
		 

};
 
#endif // LIST_H
