/**
 *  @file        stack.cpp
 *  @description Implementation of the Stack class.
 */

#include "stack.h"

template <class T>
Stack<T>::Stack() {
	num_items = 0;
	head = NULL;
}

template <class T>
Stack<T>::~Stack() {
	deallocateList(head);
}

template <class T>
void Stack<T>::deallocateList(ListNode* n) {
	if (n == nullptr)
		return;

	deallocateList(n->next);
	delete(n);
}

template <class T>
void Stack<T>::Push(const T& item) {
	ListNode * newNode = new ListNode();
	newNode->next = head;
	newNode->data = item;
	head = newNode;
	num_items++;
}

template <class T>
T Stack<T>::Pop() {
	ListNode * prevNode = head;
	T item = prevNode->data;
	head = prevNode->next;
	delete(prevNode);
	num_items--;
	return item;
}

template <class T>
void Stack<T>::Add(const T& item) {
	Push(item);
}

template <class T>
T Stack<T>::Remove() {
	return Pop();
}

template <class T>
T Stack<T>::Peek() {
	return head->data;
}

template <class T>
bool Stack<T>::IsEmpty() const {
	return num_items == 0;
}

template <class T>
size_t Stack<T>::Size() const {
	return num_items;
}