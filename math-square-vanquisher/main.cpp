#include <cstddef>
#include <stdio.h>
#include <iostream>
#include "lists/stack.h"
#include "lists/queue.h"
#include "operators.h"
#include "board.h"


#define OPERATORS Board::Operator[]

#define ADD Operators::Add
#define SUB Operators::Sub
#define MUL Operators::Mul
#define DIV Operators::Div

int main() {
    printf("TESTING TIME!\n\n");

    Queue<int> q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    
    printf("- - Queue - - \n");
    for (int i = 0; i < 3; i++) {
        printf("> %d\n", q.Dequeue());
    }
    
    Stack<int> s;
    s.Push(1);
    s.Push(2);
    s.Push(3);

    printf("- - Stack - - \n");
    for (int i = 0; i < 3; i++) {
        printf("> %d\n", s.Pop());
    }


    Board board(3);
    board.SetColumn(0, 3, MUL, DIV );
    board.SetColumn(1, 2, ADD, DIV );
    board.SetColumn(2, -12, SUB, MUL );
    board.SetRow(0, 12, ADD, SUB );
    board.SetRow(1, 6, ADD, SUB );
    board.SetRow(2, 4, ADD, DIV );
    
    std::cout << board.PrintBoard() << std::endl;

    return 0;
}