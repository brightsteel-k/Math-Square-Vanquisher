/**
 * @file        backtracksolver.h
 * @description Definition of a solver that employs a backtracking algorithm. 
 *              Defaults to a depth-first search.
 */
#ifndef _BACKTRACKSOLVER_H_
#define _BACKTRACKSOLVER_H_

#include "solver.h"
#include "lists/queue.h"
#include "lists/stack.h"

/**
 * BacktrackSolver: represents an interface for a structure that attempts
 *   to solve a math square Board. 
 */
class BacktrackSolver : public Solver {
    public:
        /**
         * Constructor
         */
        BacktrackSolver(bool depthFirstSearch);

        /**
         * Destructor
         */
        ~BacktrackSolver();

        /**
         * Signals the BacktrackSolver to begin solving.
         * @return the solution sequence of numbers.
         */
        int * BeginSolving();

    private:
        OrderingStructure<int> * boardsToTest;
        OrderingStructure<int> * optionsToTest;
};
#endif
