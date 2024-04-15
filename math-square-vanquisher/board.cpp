/**
 * @file        board.cpp
 * @description Implementation of a math square board
 */

#include "board.h"

Board::Board(unsigned int w, unsigned int h) {
    width = w;
    height = h;

    colOperators = new Operator*[w];
    for (int i = 0; i < w; i++) { colOperators[i] = new Operator[h-1]; }
    rowOperators = new Operator*[h];
    for (int i = 0; i < h; i++) { rowOperators[i] = new Operator[w-1]; }

    colTargets = new int[w];
    rowTargets = new int[h];

    colReady = new bool[w];
    for (int i = 0; i < w; i++) { colReady[i] = false; }
    rowReady = new bool[h];
    for (int i = 0; i < h; i++) { rowReady[i] = false; }
}

Board::~Board() {
    for (int i = 0; i < width; i++) { delete[] colOperators[i]; }
    delete[] colOperators;
    for (int i = 0; i < height; i++) { delete[] rowOperators[i]; }
    delete[] rowOperators;
    delete[] colTargets;
    delete[] rowTargets;
    delete[] colReady;
    delete[] rowReady;
}

void Board::setColumn(unsigned int col, int target, ...) {
    va_list ops;
    va_start(ops, 0);
    for (int i = 0; i < height - 1; i++) {
        colOperators[col][i] = va_arg(ops, Operator);
    }
    va_end(ops);
    colTargets[col] = target;
    if (!colReady[col])
        colReady[col] = true;
}

void Board::setRow(unsigned int row, int target, ...) {
    va_list ops;
    va_start(ops, 0);
    for (int i = 0; i < width - 1; i++) {
        rowOperators[row][i] = va_arg(ops, Operator);
    }
    va_end(ops);
    rowTargets[row] = target;
    if (!rowReady[row])
        rowReady[row] = true;
}

std::string Board::printBoard() {
    std::string result = "";
    for (int y = 0; y < height; y++) {
        // Number row
        std::string line = "";
        for (int x = 0; x < width - 1; x++) {
            line += "# " + Operators::GetSymbol(rowOperators[y][x]) + " ";
        }
        line += "= " + std::to_string(rowTargets[y]);

        // Operator row
        if (y < height - 1) {
            line += "\n";
            for (int x = 0; x < width; x++) {
                line += Operators::GetSymbol(colOperators[x][y]) + "   ";
            }
        }
        result += line + "\n";
    }

    std::string line = "";
    // Ending row
    for (int x = 0; x < width; x++) {
        line += "=   ";
    }
    line += "\n";
    for (int x = 0; x < width; x++) {
        line += std::to_string(colTargets[x]) + "   ";
    }
    result += line + "\n";
    return result;
}