#include <iostream>
#include "stackcalculator.h"

using std::cin;
using std::cout;

StackCalculator::StackCalculator()
{
    operators = new LinkedStack();
    originalExpression = new DoublyLinkedList();
    convertedExpression = new DoublyLinkedList();
    isOperatorLast = true;
    isExpressionConverted = false;
    isCorrect = true;
    result = 0;
}

StackCalculator::~StackCalculator()
{
    delete operators;
    delete originalExpression;
    delete convertedExpression;
}


void StackCalculator::readOriginalExpression()
{
    char symbol = '\0';
    cin.get(symbol);
    while (!isOtherSymbol(symbol))
    {
        if (isBreak(symbol))
        {
            originalExpression->addElement(symbol);
            if (symbol == '(')
                isOperatorLast = true;
        }
        else if (isOperator(symbol))
        {
            if (isOperatorLast)
            {                                       // for 5+(-25)
                if (symbol == '+' || symbol == '-')
                {
                    cin.putback(symbol);
                    readingNumber();
                }
                else                                // for 5+(/25)
                    incorrectExpression();
            }
            else
            {
                originalExpression->addElement(symbol);
                isOperatorLast = true;
            }
        }
        else if (isOperand(symbol))
        {
            cin.putback(symbol);
            readingNumber();
        }
        cin.get(symbol);
    }
    if (isOperatorLast)
        incorrectExpression();
}

void StackCalculator::reversePolishNotation()       // it's neccesary to write the function for "operators->head", I think. but later
{
    if (isCorrect)
    {
        DoublyLinkedList::Element *tmp;
        while (originalExpression->head)
        {
            tmp = originalExpression->head;
            originalExpression->head = originalExpression->head->next;
            tmp->next = nullptr;
            if (!tmp->isSymbol)
                convertedExpression->addElement(tmp->Data.number);
            else
            {
                if (isBreak(tmp->Data.symbol))                                  //breaks
                {
                    if (tmp->Data.symbol == '(')
                        operators->push('(');
                    else
                    {
                        while (operators->head && operators->head->Data.symbol != '(')
                        {
                            convertedExpression->addElement(operators->head->Data.symbol);
                            operators->pop();
                        }
                        if (operators->head->Data.symbol == '(')
                        {
                            operators->pop();
                        }
                        else
                        {
                            incorrectExpression();
                            break;
                        }
                    }
                }
                else                                                              //operators
                {
                    if (!operators->head)
                    {
                        operators->push(tmp->Data.symbol);
                    }
                    else
                    {                                                                                               //priorities
                        if (orderOfOperator(tmp->Data.symbol) > orderOfOperator(operators->head->Data.symbol))
                            operators->push(tmp->Data.symbol);
                        else if (orderOfOperator(tmp->Data.symbol) == orderOfOperator(operators->head->Data.symbol))
                        {
                            convertedExpression->addElement(operators->head->Data.symbol);
                            operators->pop();
                            operators->push(tmp->Data.symbol);
                        }
                        else
                        {
                            while (operators->head && orderOfOperator(operators->head->Data.symbol)>= orderOfOperator(tmp->Data.symbol))
                            {
                                convertedExpression->addElement(operators->head->Data.symbol);
                                operators->pop();
                            }
                            operators->push(tmp->Data.symbol);
                        }
                    }
                }
            }
        }
        while (operators->head)
        {
            convertedExpression->addElement(operators->head->Data.symbol);
            operators->pop();
        }
    }
}

double StackCalculator::calculateReversePolishNotation()
{
    if (isCorrect)
    {
        double firstNumber, secondNumber = 0;
        while (convertedExpression->head && isCorrect)

        {
            while (convertedExpression->head && !convertedExpression->head->isSymbol)
            {
                operators->push(convertedExpression->head->Data.number);
                convertedExpression->deleteElement(1);
            }
            if (!convertedExpression->head && operators->head)
            {
                incorrectExpression();
                break;
            }
            if (!correctnessCheck())
                break;
            secondNumber = operators->head->Data.number;
            operators->pop();
            if (!correctnessCheck())
                break;
            firstNumber = operators->head->Data.number;
            operators->pop();
            firstNumber = calculate(firstNumber, secondNumber, convertedExpression->head->Data.symbol);
            operators->push(firstNumber);
            convertedExpression->deleteElement(1);
        }
        if (isCorrect)
        {
            result = operators->head->Data.number;
        }
    }
}

void StackCalculator::printResult()
{
    if (isCorrect)
        cout << result;
}

bool StackCalculator::isOtherSymbol(char symbol)
{
    return !(isOperator(symbol) || isBreak(symbol) || isOperand(symbol));
}

bool StackCalculator::isOperator(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

bool StackCalculator::isOperand(char symbol)
{
    return (symbol >= '0' && symbol <= '9');
}

bool StackCalculator::isBreak(char symbol)
{
    return (symbol == '(' || symbol == ')');
}

void StackCalculator::incorrectExpression()
{
    cout << "\nIncorrect expression";
    isCorrect = false;
}

unsigned char StackCalculator::orderOfOperator(char symbolOfOperator)
{
    switch (symbolOfOperator)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '/':
    case '*':
        return 2;
        break;
    default:
        return 0;
        break;
    }
}

double StackCalculator::calculate(double firstNumber, double secondNumber, char operationSign)
{
    switch (operationSign)
    {
    case '+':
        return firstNumber + secondNumber;
        break;
    case '-':
        return firstNumber - secondNumber;
        break;
    case '*':
        return firstNumber * secondNumber;
        break;
    case '/':
        if (secondNumber != 0)
            return firstNumber / secondNumber;
        else
            incorrectExpression();
        break;
    default:
        break;
    }
}

void StackCalculator::readingNumber()
{
    double tempNumber = 0;
    cin >> tempNumber;
    originalExpression->addElement(tempNumber);
    isOperatorLast = false;
}

bool StackCalculator::correctnessCheck()
{
    if (!operators->head)
    {
        incorrectExpression();
        return false;
    }
    else
        return true;
}
