/**
 * @file        board.h
 * @description Definition of a math square board
 */
#ifndef _BOARD_H_
#define _BOARD_H_

#include <cstdarg>
#include <string>
#include "operators.h"

class Board {
    public:
        typedef double (*Operator)(double, double);

        /**
         * Constructor: creates a d by d board.
         * @param d the width and height of the board.
         */
        Board(unsigned int d):Board(d, d) {};

        /**
         * Constructor: creates a w by h board.
         * @param w the width of the board.
         * @param h the height of the board.
         * 
         */
        Board(unsigned int w, unsigned int h);

        /**
         * Destructor
         */
        ~Board();

        /**
         * Sets the equation along column col < width.
         * @param col the relevant column number.
         * @param target the target value that the column expression equals.
         * @param ops (...) the operators along the column; must provide
         *            at least height - 1 operators.
         */
        void setColumn(unsigned int col, int target, ...);
        
        /**
         * Sets the equation along row row < height.
         * @param row the relevant row number.
         * @param target the target value that the row expression equals.
         * @param ops (...) the operators along the row; must provide
         *            at least width - 1 operators.
         */
        void setRow(unsigned int row, int target, ...);

        /**
         * Prints board equations and in appropriate configuration.
         * @return the board layout, in a string
         */
        std::string printBoard();

    private:
        unsigned int width;
        unsigned int height;

        Operator** colOperators;
        Operator** rowOperators;
        int* colTargets;
        int* rowTargets;
        bool* colReady;
        bool* rowReady;

};

#include "board.cpp"
#endif