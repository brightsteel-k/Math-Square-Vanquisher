/**
 * @file        solver.cpp
 * @description Partial implementation of an abstract solver class.
 */

#include "solver.h"

void Solver::SetBoard(Board * b) {
    board = b;
    width = b->width;
    height = b->height;
    boardlength = width * height;
}

bool Solver::IsReady() {
    if (boardlength <= 0)
        return false;
    return board->IsComplete();
}

void Solver::UpdatePrintProgress(int k, int total) {
    if (printedProgress == k)
        return;
    printedProgress = k;
    std::cout << "\rSEARCHING... [";
    for (int i = 0; i < k; i++) { std::cout << '='; }
    for (int i = 0; i < total-k; i++) { std::cout << ' '; }
    std::cout << "]  ";
    std::cout.flush();
}

void Solver::setShowProgress(bool b) {
    showProgress = b;
}