/**
*  @file        queue.h
*  @description Definition of the Stack class.
*/
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "orderingstructure.h"
#include "stack.h"

/**
 * Queue class: represents a standard queue. 
 *
 * O(1) running time over n operations (amortized). 
 */
template <class T>
class Queue : public OrderingStructure<T> {
    public:
        /**
         * Adds the parameter object to the back of the Queue.
         * @param item: object to be added to the Queue.
         */
        void Enqueue(const T& item);

        /**
         * Removes the object at the front of the Queue, and returns it to
         * the caller.
         * @pre: the Queue is non-empty.
         * @return: the item that used to be at the front of the Queue.
         */
        T Dequeue();

        /**
         * Adds an element to the ordering structure.
         *
         * See OrderingStructure::Add()
         */
        void Add(const T& item);

        /**
         * Removes an element from the ordering structure.
         * 
         * See OrderingStructure::Remove()
         * @pre: the Stack is non-empty. 
         */
        T Remove();

        /**
         * Finds the object at the front of the Queue, and returns it to
         * the caller. Does not alter the Queue.
         * 
         * @pre: the Queue is non-empy.
         * @return: the item at the front of the queue.
         */
        T Peek();

        /**
         * Determines if the Queue is empty.
         *
         * @return: true if the stack is empty,
         *          false otherwise.
         */
        bool IsEmpty() const;

    private:
        Stack<T> stack_1;
        Stack<T> stack_2;
};
#include "queue.cpp"
#endif
