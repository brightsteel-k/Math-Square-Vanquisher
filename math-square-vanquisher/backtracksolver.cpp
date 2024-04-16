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
    if (boardNumbers != NULL)
        delete[] boardNumbers;
    while (!boardsToTest->IsEmpty())
        delete[] boardsToTest->Remove();
    delete boardsToTest;

    if (boardOptions != NULL)
        delete[] boardOptions;
    while (!optionsToTest->IsEmpty())
        delete[] optionsToTest->Remove();
    delete optionsToTest;
}

int * BacktrackSolver::BeginSolving() {
    if (!IsReady())
        return NULL;
    Initialize();

    // Begin
    while (true) {
        // Base case: failure
        if (boardsToTest->IsEmpty()) {
            return NULL;
        }

        // Get current board and options to process
        boardNumbers = boardsToTest->Remove();
        boardOptions = optionsToTest->Remove();

        // Print progress
        if (++tick == ticksPerPrint) {
            tick = 0;
            if (showProgress)
                Solver::UpdatePrintProgress(boardlength - boardNumbers[1] - 1, boardlength);
            else
                std::cout << "> " << IntSet::ToString(boardNumbers) << "\n";
        }

        // Check whether current board configuration is valid.
        if (IsBoardValid(IntSet::Size(boardNumbers) - 1)) {
            // Base case: success
            if (IsBoardSolved()) {
                if (showProgress) { Solver::UpdatePrintProgress(boardlength, boardlength); }
                return boardNumbers;
            }
            
            // If not solved, prepare descendents
            int numOptions = IntSet::Size(boardOptions);
            for (int i = 0; i < numOptions; i++) {
                int n = IntSet::Get(boardOptions, i);
                boardsToTest->Add(IntSet::Expand(boardNumbers, n));
                optionsToTest->Add(IntSet::Omit(boardOptions, i));
            }
        }

        // Clean up memory
        delete[] boardNumbers;
        boardNumbers = NULL;
        delete[] boardOptions;
        boardOptions = NULL;
    }

    return nullptr;
}

void BacktrackSolver::Initialize() {
    boardsToTest->Add(IntSet::Create(0));
    optionsToTest->Add(IntSet::Generate(boardlength));
}

bool BacktrackSolver::IsBoardValid(int i) {
    int x = i % width;
    int y = i / width;

    return (boardlength - width + x >= IntSet::Size(boardNumbers) || IsColumnValid(x)) 
            && (y * width + width - 1 >= IntSet::Size(boardNumbers) || IsRowValid(y));
}

bool BacktrackSolver::IsColumnValid(int x) {
    double lhs = board->colOperators[x][0](IntSet::Get(boardNumbers, x), IntSet::Get(boardNumbers, x+width));
    for (int i = 2; i < height; i++) {
        lhs = board->colOperators[x][i-1](lhs, IntSet::Get(boardNumbers, i * width + x));
    }

    return (int)lhs == board->colTargets[x];
}

bool BacktrackSolver::IsRowValid(int y) {
    int rowStart = y * width;
    double lhs = board->rowOperators[y][0](IntSet::Get(boardNumbers, rowStart), IntSet::Get(boardNumbers, rowStart + 1));
    for (int i = 2; i < width; i++) {
        lhs = board->rowOperators[y][i-1](lhs, IntSet::Get(boardNumbers, rowStart + i));
    }

    return (int)lhs == board->rowTargets[y];
}

bool BacktrackSolver::IsBoardSolved() {
    return IntSet::Size(boardNumbers) == boardlength;
}

void BacktrackSolver::SetTicksPerPrint(int t) {
    ticksPerPrint = t;
}