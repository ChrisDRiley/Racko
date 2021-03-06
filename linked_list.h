/// The specification of a template class of a linked list of type NODETYPE.                                               //

#ifndef linked_list_H
#define linked_list_H
#include "single_node.h"
#include <iostream>
#include <string>
using namespace std;

template <class NODETYPE>
class linked_list
{	
	public:
		linked_list( );
		~linked_list( );	
		linked_list(linked_list<NODETYPE> &originalList);

		void destroyList();
		void initList();
		void PrintAll();
		void PrintReverse();
		void PrintReverse(ListNode<NODETYPE> *node);
		bool Search(NODETYPE &value);
		int length();
		void copyList(const linked_list<NODETYPE>& otherList);
		bool InsertLast(const NODETYPE value);
		bool InsertFirst(const NODETYPE value);
		bool InsertInOrder(const NODETYPE value);
		bool Remove( NODETYPE & value);
		bool IsEmpty( ) const;
		bool IsListSorted();
		bool Replace(NODETYPE findNode, NODETYPE replaceNode);

	private:
		ListNode<NODETYPE> *first;   		
		ListNode<NODETYPE> *current;
		ListNode<NODETYPE> *last;
		int count;
};
#include "linked_list.cpp"
#endif
