#include "parsetree.h"

using std::fstream;

OperatorClass* ParseTree::buildTree(std::ifstream &fin)
{
    OperatorClass *tmp;
    char symbol = '\0';
    fin >> symbol;
    if (symbol == '(')
    {
        fin >> symbol;
        tmp = returnOperatorClass(symbol);
        tmp->left = buildTree(fin);
        tmp->right = buildTree(fin);
        fin >> symbol;
    }
    else if (symbol == '+' || symbol == '-' || (symbol >= '0' && symbol <= '9'))
    {
        fin.putback(symbol);
        double number;
        fin >> number;
        tmp = new NumericalOperand(number);
    }
    return tmp;
}

OperatorClass *ParseTree::returnOperatorClass(char symbol)
{
    switch (symbol)
    {
    case '+':
        return new Addition();
    case '-':
        return new Subtraction();
    case '*':
        return new Multiplication();
    case '/':
        return new Division();
    }
}

double ParseTree::calculate()
{
    return (!head) ? 0 : head->calculate();
}

void ParseTree::parseExpression(std::ifstream &fin)
{
    clearTree();
    try
    {
        head = buildTree(fin);
    }
    catch (OperatorClass::DivisionByZero &)
    {
        std::cout << "Division by zero!";
    }
}

void ParseTree::printTree(std::ofstream &fout)
{
    if (head)
    {
        head->print(fout);
    }
    else
        std::cout << "\nNo expression\n";
}

