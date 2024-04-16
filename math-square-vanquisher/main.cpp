#include <cstddef>
#include <stdio.h>
#include <iostream>
#include "lists/stack.h"
#include "lists/queue.h"
#include "lists/intset.h"
#include "backtracksolver.h"

#define ADD Operators::Add
#define SUB Operators::Sub
#define MUL Operators::Mul
#define DIV Operators::Div

Board * Make3x3Board();
Board * Make3x3BoardNice();
Board * Make4x4Board();
Board * Make5x5Board();


int main() {
    printf("Initializing board...\n\n");

    Board * board = Make4x4Board();
    
    std::cout << board->ToString() << std::endl;

    Solver * solver = new BacktrackSolver(true);
    solver->SetBoard(board);

    printf("Beginning Backtrack Solver Algorithm...\n");
    int * solution = solver->BeginSolving();

    if (solution == NULL) {
        std::cout << "\nNO SOLUTION FOUND :(" << std::endl;
    } else {
        std::cout << "\nSOLUTION: " << IntSet::ToString(solution) << std::endl;
    }

    // Memory cleanup
    delete solver;
    delete board;

    return 0;
}

Board * Make3x3Board() {
    Board * board = new Board(3);
    board->SetColumn(0, 3, MUL, DIV );
    board->SetColumn(1, 2, ADD, DIV );
    board->SetColumn(2, -12, SUB, MUL );
    board->SetRow(0, 12, ADD, SUB );
    board->SetRow(1, 6, ADD, SUB );
    board->SetRow(2, 4, ADD, DIV );
    return board;
}

Board * Make3x3BoardNice() {
    Board * board = new Board(3);
    board->SetColumn(0, 0, ADD, SUB );
    board->SetColumn(1, 3, ADD, DIV );
    board->SetColumn(2, 27, MUL, MUL );
    board->SetRow(0, 36, ADD, MUL );
    board->SetRow(1, 14, MUL, DIV );
    board->SetRow(2, 99, ADD, MUL );
    return board;
}

Board * Make4x4Board() {
    Board * board = new Board(4);
    board->SetColumn(0, 20, ADD, MUL, DIV );
    board->SetColumn(1, 70, MUL, ADD, SUB );
    board->SetColumn(2, 224, ADD, MUL, SUB );
    board->SetColumn(3, 0, MUL, ADD, SUB );
    board->SetRow(0, 86, ADD, MUL, SUB );
    board->SetRow(1, 4, SUB, ADD, DIV );
    board->SetRow(2, 39, ADD, ADD, ADD );
    board->SetRow(3, 134, ADD, MUL, SUB );
    return board;
}

Board * Make5x5Board() {
    Board * board = new Board(5);
    board->SetColumn(0, 84, MUL, ADD, SUB, DIV );
    board->SetColumn(1, 13, SUB, SUB, ADD, ADD );
    board->SetColumn(2, 848, MUL, DIV, MUL, ADD );
    board->SetColumn(3, 14, ADD, ADD, SUB, SUB );
    board->SetColumn(4, -231, ADD, DIV, SUB, MUL );
    board->SetRow(0, 560, ADD, SUB, ADD, MUL );
    board->SetRow(1, 43, MUL, SUB, SUB, MUL );
    board->SetRow(2, 165, MUL, DIV, DIV, MUL );
    board->SetRow(3, 20, SUB, SUB, ADD, ADD );
    board->SetRow(4, 16, MUL, ADD, DIV, ADD );
    return board;
}