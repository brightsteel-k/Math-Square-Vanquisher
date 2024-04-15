/**
*  @file        queue.h
*  @description Definition of the Queue class.
*/
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "orderingstructure.h"

template <class T>
class Queue : public OrderingStructure<T> {
    public:
        typedef typename OrderingStructure<T>::Node ListNode;

        /**
         * Default constructor
         */
        Queue();

        /**
         * Destructor
         */
        ~Queue();

        /**
         * Adds the parameter object to the back of the Queue.
         * @param item: object to be added to the Queue.
         */
        void Enqueue(const T& item);

        /**
         * @pre: the Queue is non-empty.
         * 
         * Removes the object at the front of the Queue, and returns it to
         * the caller.
         * @return: the item that used to be at the front of the Queue.
         */
        T Dequeue();

        /**
         * Adds an element to the ordering structure.
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
         * @pre: the Queue is non-empy.
         * 
         * Finds the object at the front of the Queue, and returns it to
         * the caller. Does not alter the Queue.
         * @return: the item at the front of the Queue.
         */
        T Peek();

        /**
         * Determines if the Queue is empty.
         *
         * @return: true iff the stack is empty.
         */
        bool IsEmpty() const;

        /**
         * Return the number of items on the Queue.
         */
        size_t Size() const;


    private:
        /**
         * The number of items currently in the Queue
         */
        size_t num_items;

        /**
         * The head of the Queue's internal singly-linked list (front)
         */
        ListNode * head;

        /**
         * The tail of the Queue's internal singly-linked list (back)
         */
        ListNode * tail;

        /**
         * Recursively frees the memory associated with the linked 
         * list starting at the parameter.
         */
        void deallocateList(ListNode *);
};

#include "queue.cpp"
#endif
