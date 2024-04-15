/**
 * @file        calculator.h
 * @description Definition of an abstract solver class.
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
        virtual void SetBoard(Board * b);

        /**
         * Determines whether the Solver is prepared with a board to solve.
         * @return true iff a complete Board has been properly loaded in.
         */
        virtual bool IsReady();

        /**
         * Signals the Solver to begin solving.
         * @return the solution sequence of numbers.
         */
        virtual int * BeginSolving();

    protected:
        Board * board;
        int width;
        int height;
        int boardlength = 0;
};
#include "solver.cpp"
#endif
