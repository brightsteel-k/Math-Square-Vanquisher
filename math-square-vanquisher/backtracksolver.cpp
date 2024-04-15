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
    Solver::SetBoard(b);
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
    if (!IsReady())
        return NULL;
    Initialize();

    int xMod = 0;
    int yMod = 0;
    // Begin
    while (true) {
        
    }

    return nullptr;
}

void BacktrackSolver::Initialize() {
    boardNumbers = new int[boardlength];
    for (int i = 0; i < boardlength; i++) { boardNumbers[i] = 0; }
    boardOptions = IntSet::Generate(boardlength);
}

bool BacktrackSolver::IsBoardValid(int i) {
    int x = i % width;
    int y = i / width;

    return (boardNumbers[boardlength - width + x] == 0 || IsColumnValid(x)) 
            && (boardNumbers[y * width + width - 1] == 0 || IsRowValid(y));
}

bool BacktrackSolver::IsColumnValid(int x) {
    double lhs = board->colOperators[x][0](boardNumbers[x], boardNumbers[x+width]);
    for (int i = 2; i < height; i++) {
        lhs = board->colOperators[x][i-1](boardNumbers[(i-1) * width + x], boardNumbers[i * width + x]);
    }
    return (int)lhs == board->colTargets[x];
}

bool BacktrackSolver::IsRowValid(int y) {
    int rowStart = y * width;
    double lhs = board->rowOperators[y][0](boardNumbers[rowStart], boardNumbers[rowStart + 1]);
    for (int i = 2; i < width; i++) {
        lhs = board->rowOperators[y][i-1](boardNumbers[rowStart + i - 1], boardNumbers[rowStart + i]);
    }
    return (int)lhs == board->rowTargets[y];
}