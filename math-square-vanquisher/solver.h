/**
 * @file        calculator.h
 * @description Definition of an abstract calculator class.
 */
#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "board.h"

/**
 * Solver: represents an interface for a structure that attempts
 *   to solve a math square Board. 
 */
class Solver {
    public:
        /**
         * Constructor
         */
        Solver();

        /**
         * Destructor
         */
        virtual ~Solver();

        /**
         * Sets the Board that this Solver will attempt to solve.
         * @param b the Board to solve.
         */
        void SetBoard(Board b);

        /**
         * Signals the Solver to begin solving.
         * @return the solution sequence of numbers.
         */
        virtual int * BeginSolving();

    protected:
        Board board;
};
#endif
