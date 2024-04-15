/**
 * @file        backtracksolver.cpp
 * @description Implementation of a solver that employs a backtracking algorithm.
 */

#include "backtracksolver.h"


BacktrackSolver::BacktrackSolver(bool depthFirstSearch) {
    if (depthFirstSearch) {
        boardsToTest = new Stack<int*>();
        optionsToTest = new Stack<int*>();
    } else {
        boardsToTest = new Queue<int*>();
        optionsToTest = new Queue<int*>();
    }
}

void BacktrackSolver::SetBoard(Board * b) {
    if (boardNumbers != NULL) {
        delete[] boardNumbers;
        delete[] boardOptions;
    }
    Solver::SetBoard(b);

    boardNumbers = new int[width * height];
    boardOptions = new int[width * height];
}

BacktrackSolver::~BacktrackSolver() {
    while (!boardsToTest->IsEmpty()) {
        delete[] boardsToTest->Remove();
    }
    delete boardsToTest;

    while (!optionsToTest->IsEmpty()) {
        delete[] optionsToTest->Remove();
    }
    delete optionsToTest;
}

int * BacktrackSolver::BeginSolving() {
    return nullptr;
}
