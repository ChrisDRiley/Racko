#include "linked_list.h"
#include "single_node.h"
#ifndef LIST_CPP
#define LIST_CPP
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

template <class NODETYPE>
void linked_list<NODETYPE>::initList()
{
	destroyList();
	first = NULL;
	current = NULL;
	last = NULL;
	count = 0;
}


template <class NODETYPE>
linked_list<NODETYPE>::linked_list()
{
	first = NULL;
	current = NULL;
	last = NULL;
	count = 0;
}
template <class NODETYPE>
void linked_list<NODETYPE>::destroyList()
{
	ListNode<NODETYPE> *temp = new ListNode<NODETYPE>;
	while(first != NULL){
		temp = first;
		first = temp->next;
		delete temp;
	}
	count = 0; 
}
template <class NODETYPE>
linked_list<NODETYPE>::~linked_list()
{
	destroyList();
}
template <class NODETYPE>
int linked_list<NODETYPE>::length()
{
	return count;
}
template <class NODETYPE>
linked_list<NODETYPE>::linked_list(linked_list<NODETYPE> &originalList)
{
	first = NULL;
	copyList(originalList);
}
template <class NODETYPE>
void linked_list<NODETYPE>::copyList(const linked_list<NODETYPE>& otherList)
{
	ListNode<NODETYPE> *newNode; //pointer to create a node

	if (first != NULL) //if the list is nonempty, make it empty
		destroyList();

	if (otherList.first == NULL) //otherList is empty
	{
		first = NULL;
		last = NULL;
		count = 0;
	}
	else
	{
		newNode = otherList.first;
		while(newNode != NULL){
			InsertLast(newNode->data);
			newNode = newNode->next;
			count++;
		}
			
	}//end else
}//end copyList

template <class NODETYPE>
bool linked_list<NODETYPE>::Remove(NODETYPE & value)
{
	ListNode<NODETYPE> *temp = new ListNode<NODETYPE>;
	if(IsEmpty()){
		return false;
	}
	else if(first->data == value){
		value = first->data;
		temp = first;
		first = first->next;
		delete temp;
		count--;
		return true;
	}
	else{
		temp = first;
		current = first->next;
		
		while(current != NULL){
			if(current->data == value){
				value = current->data;
				temp->next = current->next;
				delete current;
				count--;
				return true;
			}
			temp = current;
			current = current->next;
		}
	}
	return false;

}
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertInOrder(const NODETYPE value)
{
	current = first;
	while(current != NULL){
		if(current->next == NULL){
			last = current;
			break;
		}
		else{
			current = current->next;
		}
	}
	ListNode<NODETYPE> *temp = new ListNode<NODETYPE>;
	if(temp != NULL){
		if(first == NULL){
			InsertFirst(value);
			count++;
			return true;
		}
		else if(value < first->data){
			InsertFirst(value);
			count++;
			return true;
		}
		else if(value >= last->data){
			InsertLast(value);
			count++;
			return true;
		}
		else{
			temp->data = value;
			current = first;
			while(current->next != NULL){
				if(value >= current->data && value < current->next->data){
					temp->next = current->next;
					current->next = temp;
					count++;
					return true;
				}
				else{
					current = current->next;
				}
			}
		}
		
	}
		
	return false;
}
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertFirst(const NODETYPE value)
{
	// A variable used to point to data that is being inserted.
	ListNode<NODETYPE> *temp = new ListNode<NODETYPE>;

	if (temp == NULL) return false;

	temp->data = value;
	if (first == NULL)
		temp->next = NULL;
	else
		temp->next = first;
	first = current = temp;

	return true;
}
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertLast(const NODETYPE value)
{
	// A variable used to point to data that is being inserted.
	ListNode<NODETYPE> *temp = new ListNode<NODETYPE>;

	if (temp == NULL) return false;
	temp->data = value;
	if (last == NULL)
	{
		last = temp;
		first = last;
	}
	else
		last->next = temp;
	last = current = temp;
	last->next = NULL;

	return true;
}

template <class NODETYPE>
bool linked_list<NODETYPE>::IsEmpty() const
{
	return (first == NULL);
}

template <class NODETYPE>
bool linked_list<NODETYPE>::Search(NODETYPE &value)
{
	current = first;
	while(current != NULL){
		if(current->data == value){
			return true;
		}
		else{
			current = current->next;
		}
	}
	return false;
}
template <class NODETYPE>
void linked_list<NODETYPE>::PrintAll()
{
	if(IsEmpty()){
		cout << "The list is empty." << endl;
	}
	else{
		current = first;
		while(current != NULL){
			cout << current->data << endl;
			current = current->next;
		}
	}
}
template <class NODETYPE>
void linked_list<NODETYPE>::PrintReverse()
{
	PrintReverse(first);	
}
template <class NODETYPE>
void linked_list<NODETYPE>::PrintReverse(ListNode<NODETYPE> *node)
{
	if(node == NULL){
		return;
	}
	PrintReverse(node->next);
	cout << node->data << endl;
}
template <class NODETYPE>
bool linked_list<NODETYPE>::Replace(NODETYPE findNode, NODETYPE replaceNode)
{
	if(IsEmpty()){
		return false;
	}
	else{
		current = first;
		while(current != NULL){
			if(current->data == findNode){
				current->data = replaceNode;
				return true;
			}
			current = current->next;
		}
	}
	return false;	
}
template <class NODETYPE>
bool linked_list<NODETYPE>::IsListSorted()
{
	NODETYPE value;
	current = first;
	while(current != NULL){
		if(current == first){
			value = current->data;
		}
		else{
			if(!(current->data < value)){
				return false;
			}
			else{
				value = current->data;
			}
		}
		current = current->next;
	}
	return true;
		
}
#endif


