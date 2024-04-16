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
         * Constructor
         */
        BacktrackSolver():BacktrackSolver(true) {};

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

        /**
         * Sets the number of ticks that go by per status update during
         * solving phase.
         * @param t number of ticks (boards tested) per print statement.
         */
        void SetTicksPerPrint(int t);

    private:
        int ticksPerPrint = 1000000;
        int tick = 0;
        //bool debugInfo = false;

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

        
        /**
         * Determines if boardNumbers contains enough valid entries to fill the board.
         * @return true iff the board is filled with valid equations.
         */
        bool IsBoardSolved();
};

#include "backtracksolver.cpp"
#endif
