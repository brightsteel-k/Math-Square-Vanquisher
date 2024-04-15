/**
 * @file        solver.cpp
 * @description Partial implementation of an abstract solver class.
 */

#include "solver.h"

void Solver::SetBoard(Board * b) {
    board = b;
    width = b->width;
    height = b->height;
}

bool Solver::IsReady() {
    if (width <= 0 || height <= 0)
        return false;
    return board->IsComplete();
}