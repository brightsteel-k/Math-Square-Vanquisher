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
#include "lists/intset.h"

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
         * @return the solution sequence of numbers, or NULL if the
         *         board was improperly initialized.
         */
        int * BeginSolving();

    private:
        int * boardNumbers = NULL;
        OrderingStructure<int*> * boardsToTest = NULL;
        int * boardOptions = NULL;
        OrderingStructure<int*> * optionsToTest = NULL;
        
        /**
         * Prepare internal lists to keep track of baord solving progress.
         */
        void Initialize();

        /**
         * Determines if the board's equations have been violated along the 
         * x column and y row of the slot i, using the current value of boardNumbers.
         * @return false iff a board equation has been violated.
         */
        bool IsBoardValid(int i);

        /**
         * @pre boardNumbers is full enough that the equation along column x
         *      is complete (no missing numbers).
         * Determines if the board's equation along column x has been violated,
         * using the current value of boardNumbers.
         * @return true iff the board equation is fulfilled.
         */
        bool IsColumnValid(int x);

        /**
         * @pre boardNumbers is full enough that the equation along row y
         *      is complete (no missing numbers).
         * Determines if the board's equation along row y has been violated,
         * using the current value of boardNumbers.
         * @return true iff the board equation is fulfilled.
         */
        bool IsRowValid(int y);
};
#endif
