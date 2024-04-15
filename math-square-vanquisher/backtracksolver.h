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
         * Sets the Board that this Backtrackolver will attempt to solve.
         * See Solver::SetBoard()
         * @param b the Board to solve.
         */
        void SetBoard(Board * b);

        /**
         * Signals the BacktrackSolver to begin solving.
         * @return the solution sequence of numbers.
         */
        int * BeginSolving();

        /**
         * Clears internal lists that keep track of board solving progress.
         */
        void DeleteBoardLists();

    private:
        int * boardNumbers = NULL;
        OrderingStructure<int*> * boardsToTest = NULL;
        int * boardOptions = NULL;
        OrderingStructure<int*> * optionsToTest = NULL;
};
#endif
