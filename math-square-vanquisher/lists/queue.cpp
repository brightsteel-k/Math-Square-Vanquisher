/**
 * @file        queue.cpp
 * @description Implementation of the Queue class.
 */

#include "queue.h"

template <class T>
Queue<T>::Queue() {
	num_items = 0;
	head = NULL;
	tail = NULL;
}

template <class T>
Queue<T>::~Queue() {
	deallocateList(head);
}

template <class T>
void Queue<T>::deallocateList(ListNode* n) {
	if (n == nullptr)
		return;

	deallocateList(n->next);
	delete(n);
}

template <class T>
void Queue<T>::Enqueue(T const& item) {
	ListNode * newNode = new ListNode();
	newNode->next = NULL;
	newNode->data = item;
	if (num_items == 0) {
		tail = newNode;
		head = newNode;
	} else {
		tail->next = newNode;
		tail = newNode;
	}
	num_items++;
}

template <class T>
T Queue<T>::Dequeue() {
	ListNode * prevNode = head;
	T item = prevNode->data;
	head = prevNode->next;
	delete(prevNode);
	num_items--;
	if (num_items == 0) {
		tail = NULL;
	}
	return item;
}

template <class T>
void Queue<T>::Add(const T& item) {
	Enqueue(item);
}

template <class T>
T Queue<T>::Remove() { 
	return Dequeue();
}

template <class T>
T Queue<T>::Peek() {
	return head->data;
}

template <class T>
bool Queue<T>::IsEmpty() const {
	return num_items == 0;
}

template <class T>
size_t Queue<T>::Size() const {
	return num_items;
}