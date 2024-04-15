/**
 * @file        stack.h
 * @description Definition of the Stack class.
 */

#ifndef _STACK_H_
#define _STACK_H_

#include "orderingstructure.h"

template <class T>
class Stack : public OrderingStructure<T> {
    public:
        typedef typename OrderingStructure<T>::Node ListNode;
        
        /**
         * Default constructor
         */
        Stack();

        /**
         * Destructor
         */
        ~Stack();

        /**
         * Adds the parameter object to the top of the Stack
         * @param item: the object to be added to the Stack
         */
        void Push(const T& item);

        /**
         * Removes the object on top of the Stack, and returns it.
         * @return the element that used to be at the top of the Stack.
         */
        T Pop();

        /**
         * Adds the given element to the ordering structure.
         * See OrderingStructure::Add()
         */
        void Add(const T& item);

        /**
         * @pre: the Stack is non-empty. 
         * 
         * Removes an element from the ordering structure.
         * See OrderingStructure::Remove()
         */
        T Remove();

        /**
         * @pre: the Stack is non-empty. 
         * 
         * Finds the object on top of the Stack, and returns it to the caller.
         * Unlike Pop(), this operation does not alter the Stack itself.
         * @return: the element at the top of the Stack.
         */
        T Peek();

        /**
         * Determines if the Stack is empty.
         * @return true iff the Stack is empty.
         */
        bool IsEmpty() const;

        /**
         * Return the number of items on the Stack.
         */
        size_t Size() const;

    private:
        /**
         * The number of items currently in the Stack
         */
        size_t num_items;

        /**
         * The head of the Stack's internal singly-linked list
         */
        ListNode * head;

        /**
         * Recursively frees the memory associated with the linked 
         * list starting at the parameter.
         */
        void deallocateList(ListNode *);
};

#include "stack.cpp"

#endif
