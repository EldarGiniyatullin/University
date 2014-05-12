#pragma once

#include <iostream>
#include "operatorclass.h"
#include "addition.h"
#include "division.h"
#include "multiplication.h"
#include "subtraction.h"
#include "numericaloperand.h"

using std::ifstream;
using std::ofstream;

/**
 * @brief The ParseTree class implements an expression's parse tree building, calculating, printing
 */
class ParseTree // ! build the list of operator symbols - could be nice idea
{
public:
    ParseTree() : head(nullptr)
    {
    }

    ~ParseTree()
    {
        delete head;
    }

    /**
     * @brief parseExpression builds a parse tree
     * @param fin is input file with expression
     */
    void parseExpression(ifstream &fin);

    /**
     * @brief printTree prints the parse tree to file
     * @param fout is output file
     */
    void printTree(std::ofstream &fout);

    /**
     * @brief calculate calcuates parsed expression
     * @return result. Can return zero if there are some handled exceptions
     */
    double calculate();

    class NoParsedExpression{};

    void clearTree()
    {
        delete head;
        head = nullptr;
    }

protected:
    /**
     * @brief buildTree is service method that builds parts of parse tree
     * @param fin is input file with expression
     * @return pointer to the head of this part
     */
    OperatorClass *buildTree(ifstream &fin);

    /**
     * @brief returnOperatorClass determines binary operation or number
     * @param symbol is symbol of operation
     * @return OperatorClass's object
     */
    OperatorClass *returnOperatorClass(char symbol);

private:
    OperatorClass* head;
};
