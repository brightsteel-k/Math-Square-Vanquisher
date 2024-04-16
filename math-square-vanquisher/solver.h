/**
 * @file        calculator.h
 * @description Definition of an abstract solver class.
 */
#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <iostream>
#include "board.h"

/**
 * Solver: represents an interface for a structure that attempts
 *   to solve a math square Board. 
 */
class Solver {
    public:

        /**
         * Destructor
         */
        virtual ~Solver() {
            // nothing
        }

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
        virtual int * BeginSolving() {
            return NULL; // stub
        }

        /**
         * Uses std:cout to print a progress bar of length total units, 
         * with k units filled in.
         * @param k the current progress, k <= total
         * @param total the length of the progress bar
         */
        void UpdatePrintProgress(int k, int total);

        /**
         * Sets whether the solver will print its progress in a progress bar.
         * @param b whether or not the solver should print its progress.
         */
        void setShowProgress(bool b);

    protected:
        Board * board;
        int width;
        int height;
        int boardlength = 0;

        bool showProgress = true;
        int printedProgress = 0;
};

#include "solver.cpp"
#endif
