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
    isCorrect = false;
    result = 0;
    expInString = "";
}

StackCalculator::~StackCalculator()
{
    delete operators;
    delete originalExpression;
    delete convertedExpression;
}

void StackCalculator::reversePolishNotation()
{
    delete operators;
    operators = new LinkedStack;
    if (isCorrect)
    {
        delete convertedExpression;
        convertedExpression = new DoublyLinkedList;
        DoublyLinkedList::Element *tmp;
        while (originalExpression->head && isCorrect)
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
                        if (!operators->head || operators->head->Data.symbol != '(')
                        {
                            incorrectExpression();
                            break;
                        }
                        else
                        {
                            operators->pop();
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
    if (!isCorrect)
    {
        delete convertedExpression;
        convertedExpression = new DoublyLinkedList;
    }
    delete operators;
    operators = new LinkedStack;
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
            if (!convertedExpression->head && operators->head && operators->head->isSymbol)
            {
                incorrectExpression();
                return 0;
            }
            if (!correctnessCheck())
                return 0;
            secondNumber = operators->head->Data.number;
            operators->pop();
            if (!operators->head)
            {
                if (!convertedExpression->head)
                {
                     result = secondNumber;
                    return result;
                }
                else
                {
                    incorrectExpression();
                    return 0;
                }
            }
            firstNumber = operators->head->Data.number;
            operators->pop();
            firstNumber = calculate(firstNumber, secondNumber, convertedExpression->head->Data.symbol);
            operators->push(firstNumber);
            convertedExpression->deleteElement(1);
        }
        if (isCorrect)
        {
            result = operators->head->Data.number;
            return result;
        }
    }
}

bool StackCalculator::isExpressionCorrect()
{
    return isCorrect;
}

double StackCalculator::calculateExpression(QString expression)
{
    double tmp;
    isCorrect = true;
    expInString = expression;
    delete originalExpression;
    originalExpression = new DoublyLinkedList;
    readExpressionFromString();
    if (isCorrect)
        reversePolishNotation();
    if (isCorrect)
        tmp = calculateReversePolishNotation();
    if (!isCorrect)
    {
        isOperatorLast = true;
        expInString = "";
        delete convertedExpression;
        convertedExpression = new DoublyLinkedList;
        return 0;
    }
    else
    {
        return tmp;
    }
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
    cout << "\nIncorrect expression\n";
    isOperatorLast = true;
    isCorrect = false;
}

unsigned char StackCalculator::orderOfOperator(char symbolOfOperator)
{
    switch (symbolOfOperator)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '/':
        return 2;
        break;
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

void StackCalculator::readingNumberFromString(int &symbol)
{
    QString tempNumber = "";
    bool isDot = false;
    char tmp = expInString.toStdString()[symbol];
    if (tmp == '+' || tmp == '-')
    {
        tempNumber = tempNumber + expInString[symbol++];
        tmp = expInString.toStdString()[symbol];
    }
    while (symbol < expInString.length() && ((tmp <= '9' && tmp >= '0') || tmp == '.'))
    {
        if (tmp == '.')
            if (isDot && tempNumber == "")
            {
                incorrectExpression();
                break;
            }
            else
                isDot = true;
        tempNumber = tempNumber + expInString[symbol++];
        tmp = expInString.toStdString()[symbol];
    }
    if (tempNumber == "")
    {
        incorrectExpression();
    }
    if (isCorrect)
    {
        bool isDouble = true;
        originalExpression->addElement(tempNumber.toDouble(&isDouble));
        if (!isDouble)
            incorrectExpression();
    }
    symbol--;
}

void StackCalculator::readExpressionFromString()
{
    int curr = 0;
    isOperatorLast = true;
    isCorrect = true;
    char symbol = expInString.toStdString()[curr];
    while (curr < expInString.length() && isCorrect)
    {
        symbol = expInString.toStdString()[curr];
        if (isBreak(symbol))
        {
            if ((symbol == '(' && isOperatorLast) || (symbol == ')' && !isOperatorLast))
                originalExpression->addElement(symbol);
            else
                incorrectExpression();
            if (symbol == '(')
                isOperatorLast = true;
        }
        else if (isOperator(symbol))
        {
            if (isOperatorLast)
            {                                       // for 5+(-25)
                if (symbol == '+' || symbol == '-')
                {
                    readingNumberFromString(curr);
                    if (isCorrect)
                        isOperatorLast = false;
                }
                else
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
            readingNumberFromString(curr);
            if (isCorrect)
                isOperatorLast = false;
            else
                incorrectExpression();
        }
        curr++;
    }
    if (isOperatorLast)
        incorrectExpression();
}

void StackCalculator::setExpression(const QString &expression)
{
    expInString = expression;
}

double StackCalculator::getResult()
{
    return result;
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
