#include <cstddef>
#include <stdio.h>
#include <iostream>
#include "lists/stack.h"
#include "lists/queue.h"
#include "lists/intset.h"
#include "backtracksolver.h"


#define OPERATORS Board::Operator[]

#define ADD Operators::Add
#define SUB Operators::Sub
#define MUL Operators::Mul
#define DIV Operators::Div

int main() {
    printf("TESTING TIME!\n\n");

    Board * board = new Board(3);
    board->SetColumn(0, 3, MUL, DIV );
    board->SetColumn(1, 2, ADD, DIV );
    board->SetColumn(2, -12, SUB, MUL );
    board->SetRow(0, 12, ADD, SUB );
    board->SetRow(1, 6, ADD, SUB );
    board->SetRow(2, 4, ADD, DIV );
    
    std::cout << board->ToString() << std::endl;

    int* setOne = IntSet::Generate(5);
    int* setTwo = IntSet::Omit(setOne, 0);
    int* setThree = IntSet::Omit(setOne, 3);
    int* setFour = IntSet::Omit(setOne, 4);
    int* setFive = IntSet::Omit(setOne, 6);

    std::cout << "Set One: " << IntSet::ToString(setOne) << std::endl;
    std::cout << "Set Two: " << IntSet::ToString(setTwo) << std::endl;
    std::cout << "Set Three: " << IntSet::ToString(setThree) << std::endl;
    std::cout << "Set Four: " << IntSet::ToString(setFour) << std::endl;
    std::cout << "Set Five: " << IntSet::ToString(setFive) << std::endl;

    return 0;
}