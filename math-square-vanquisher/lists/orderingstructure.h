/**
 * @file        orderingstructure.h
 * @description Definition of an abstract ordering structure class.
 */
#ifndef _ORDERINGSTRUCTURE_H_
#define _ORDERINGSTRUCTURE_H_


/**
 * OrderingStructure: represents an interface for a structure that orders
 *   items placed into it. 
 */
template <class T> class OrderingStructure {
    public:
        struct Node {
          T data;
          Node* next;
        };

        virtual ~OrderingStructure() {
          // nothing
        }

        /**
         * Adds the given element to the ordering structure.
         * @param item: the item to be added.
         */
        virtual void Add(const T& item) = 0;

        /**
         * @pre: the structure is not empty.
         * 
         * Removes an element from the ordering structure. 
         * @return: an element from the ordering structure.
         */
        virtual T Remove() = 0;

        /**
         * @pre: the structure is not empty.
         * 
         * Looks at the next element of the ordering structure, but does
         * not remove it.
         * @return: the next element on the ordering structure.
         */
        virtual T Peek() = 0;

        /**
         * Determines if the ordering structure is empty.
         * @return: true iff there are no elements in the ordering structure.
         */
        virtual bool IsEmpty() const = 0;
};
#endif
