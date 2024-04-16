/**
 * @file        intset.h
 * @description Handler for arrays of integers stored on the heap
 *              which record their size in their first slot.
 */
#ifndef _INTSET_H_
#define _INTSET_H_

#include <string>

/**
 * IntSet data type: an integer array of fixed size where the following invariant
 *  holds:
 *  INVARIANT: the 0th slot of an integer set array records its size (number of
 *             other filled spots in the array).
 */
struct IntSet {
    /**
     * Creates a new size-recording set of integers of the 
     * given max size, filled with zeros.
     * @param size max size of the integer set.
     */
    static int* Create(unsigned int size) {
        return Create(size, 0);
    }

    /**
     * Creates a new size-recording set of integers of the 
     * given max size, initializes each spot to a default value.
     * @param size max size of the integer set.
     * @param default the default value of each spot in the set.
     */
    static int* Create(unsigned int size, int defaultVal) {
        int* arr = new int[size + 1];
        arr[0] = size;
        for (unsigned int i = 1; i < size + 1; i++) {
            arr[i] = defaultVal;
        }
        return arr;
    }

    /**
     * Creates a new size-recording set of integers of the 
     * given max size, containing all natural numbers up to size.
     * @param size max size of the integer set.
     */
    static int* Generate(unsigned int size) {
        int* arr = new int[size + 1];
        arr[0] = size;
        for (unsigned int i = 1; i < size + 1; i++) {
            arr[i] = i;
        }
        return arr;
    }

    /**
     * @pre i < size of integer set.
     * Gets the value of integer set arr at index i.
     * @return arr[i + 1]
     */
    static int Get(int* arr, int i) {
        return arr[i + 1];
    }

    /**
     * @pre i < size of integer set.
     * Sets the value of integer set arr at index i to val.
     * @return arr[i + 1] = val
     */
    static int Set(int* arr, int i, int val) {
        return arr[i + 1] = val;
    }

    /**
     * Gets the size of the integer set arr.
     * @return arr[0]
     */
    static int Size(int* arr) {
        return arr[0];
    }

    /**
     * Generates a string representation of the integer set arr.
     * @return string displaying the set.
     */
    static std::string ToString(int* arr) {
        std::string result = "{ ";
        for (int i = 0; i < arr[0]; i++) {
            result += std::to_string(arr[i+1]);
            if (i != arr[0] - 1)
                result += ", ";
        }
        result += " } [" + std::to_string(arr[0]) + "]";
        return result;
    }
    

    /**
     * Returns a new integer set with the same values
     * as the integer set arr.
     * @return Pointer to the newly allocated integer set.
     */
    static int* Copy(int* arr) {
        int size = arr[0];
        int* newArr = new int[size + 1];
        for (int i = 0; i <= size; i++) {
            newArr[i] = arr[i];
        }
        return newArr;
    }

    /**
     * Returns a new integer set with the same values
     * as the integer set arr, omitting the value at
     * index k.
     * @param arr the original integer set.
     * @param k the index of the value to omit.
     * @return pointer to the newly allocated integer set.
     */
    static int* Omit(int* arr, int k) {
        int size = arr[0];
        int* newArr = new int[size];
        newArr[0] = size - 1;
        int o = 0;
        for (int i = 0; i < size - 1; i++) {
            if (i == k)
                o = 1;
            newArr[i+1] = arr[i+1+o];
        }
        return newArr;
    }
    
    /**
     * Returns a new integer set with the same values
     * as the integer set arr, with a new value val added 
     * to the end.
     * @param arr the original integer set.
     * @param val the value to add.
     * @return pointer to the newly allocated integer set.
     */
    static int* Expand(int* arr, int val) {
        int size = arr[0];
        int* newArr = new int[size + 2];
        newArr[0] = size + 1;
        for (int i = 1; i < size + 1; i++) {
            newArr[i] = arr[i];
        }
        newArr[size + 1] = val;
        return newArr;
    }
};
#endif
