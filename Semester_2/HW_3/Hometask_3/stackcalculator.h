/*****
 *
 * Calculator is potentially expand to a larger number of operators
 *
 *****/

#pragma once

#include "stack.h"
#include "doublylinkedlist.h"
#include "linkedstack.h"
#include <QString>


/**
 * @brief The StackCalculator class is class for calculation of simple expressions
 * @detailed The StackCalculator can read expression string-variable,
 * convert it to Reverse Polish Notation (RPN), check its correctness
 * and calculate the result
 * Calculator is potentially expand to a larger number of operators
 * @detailed the algorithm of this calculator you can read here
 * http://ru.wikipedia.org/wiki/RPN
 */
class StackCalculator: public LinkedStack, public DoublyLinkedList
{
public:
    StackCalculator();
    ~StackCalculator();
    /**
     * @brief reversePolishNotation converts the expression added to StackCalculator::originalExpression
     * to RPN if needed and adds it to StackCalculator::convertedExpression
     */
    void reversePolishNotation();
    /**
     * @brief calculateReversePolishNotation
     * @return the result of calculation
     */
    double calculateReversePolishNotation();
    DoublyLinkedList *originalExpression;
    /**
     * @brief convertedExpression contains the expression after to-RPN-conversion
     */
    DoublyLinkedList *convertedExpression;
    /**
     * @brief result is the result of calculated expression
     */
    double result;
    /**
     * @brief expInString contains expression
     */
    QString expInString;
    class IncorrectExpression{};
    bool isExpressionCorrect();
    double calculateExpression(QString expression);
    /**
     * @brief readExpressionFromString builds originalExpression from expInString
     */
    void readExpressionFromString();
protected:
    /**
     * @brief isCorrect is false if expression's incorrectness revealed
     */
    bool isCorrect;
    /**
     * @brief isOperatorLast equals true if the previous processed symbol in StackCalculator::reversePolishNotation()
     * was the symbol of binary operator or "("
     */
    bool isOperatorLast;
    /**
     * @brief isExpressionConverted equals true if the original expression is converted to RPN and added to
     * StackCalculator::convertedExpression
     */
    bool isExpressionConverted;
    /**
     * @brief operators is queue of operators needed for conver
     */
    LinkedStack *operators;
    /**
     * @param symbol is symbol to check
     * @return true if all next 4 is-functions return false
     */
    bool isOtherSymbol(char symbol);
    /**
     * @param symbol is symbol to check
     * @return true if it is the symbol of operator
     */
    bool isOperator(char symbol);
    /**
     * @param symbol is symbol to check
     * @return true if it is the symbol of number
     */
    bool isOperand(char symbol);
    /**
     * @param symbol is symbol to check
     * @return true if the symbol equals "(" or ")"
     */
    bool isBreak(char symbol);
    /**
     * @brief incorrectExpression includes actions occurring after detection expression's incorrectness
     */
    void incorrectExpression();
    /**
     * @brief orderOfOperator defines the order of binary operation numerically
     * @param symbolOfOperator. The operation determines by its symbol
     * @return number. The greater number, the higher order of operation
     */
    unsigned char orderOfOperator(char symbolOfOperator);
    /**
     * @brief calculate calculates simple binary operations (sum, subtraction, multiplication, division)
     * @param firstNumber is first operand
     * @param secondNumber is second operand
     * @param operationSign is symbol that determines the operation
     * @return the result of operation
     */
    double calculate(double firstNumber, double secondNumber, char operationSign);
private:/**
     * @brief readingNumberFromString reads double number from QString-variable
     * @param symbol - first symbol in expInString to read number from
     */
    void readingNumberFromString(int &symbol);
    /**
     * @brief readingNumber reads number from the console
     */
    void readingNumber();
    /**
     * @brief correctnessCheck checks the correctness of expression
     * @return true if expression is still correct
     */
    bool correctnessCheck();
};
