/**
 * @file        operators.h
 * @description Struct storing operation methods.
 */

#ifndef _OPERATORS_H_
#define _OPERATORS_H_

#include <string>

struct Operators {
    typedef double (*Operator)(double, double);

    /**
     * Standard addition.
     * @return x + y
     */
    static double Add(double x, double y) {
        return x + y;
    }

    /**
     * Standard subtraction.
     * @return x - y
     */
    static double Sub(double x, double y) {
        return x - y;
    }

    /**
     * Standard multiplication.
     * @return x * y
     */
    static double Mul(double x, double y) {
        return x * y;
    }

    /**
     * Standard division.
     * @return x / y
     */
    static double Div(double x, double y) {
        return x / y;
    }

    static std::string GetName(Operator op) {
        if (op == Add) { return "addition"; }
        if (op == Sub) { return "subtraction"; }
        if (op == Mul) { return "multiplication"; }
        if (op == Div) { return "division"; }
        return "";
    }

    static std::string GetSymbol(Operator op) {
        if (op == Add) { return "+"; }
        if (op == Sub) { return "-"; }
        if (op == Mul) { return "x"; }
        if (op == Div) { return "/"; }
        return "";
    }
};
#endif