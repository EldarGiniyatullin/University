#include <iostream>
#include <fstream>
#include "parsetree.h"
#include "testparsetree.h"


using namespace std;

int main()
{
    TestParseTree testParseTree;
    QTest::qExec(&testParseTree);

    ParseTree* a = new ParseTree();
    ifstream fin("expression.txt");
    if (!fin.is_open())
    {
        cout << "Error file_1";
        return 0;
    }
    ofstream fout("result.txt", ios_base::trunc);
    if (!fout.is_open())
    {
        cout << "Error file_2";
        return 0;
    }
    try
    {
        fout << a->calculate();
    }
    catch (ParseTree::NoParsedExpression &)
    {
        cout << "\nAn expression is not parsed yet\n";
    }
    catch (Division::DivisionByZero &)
    {
        cout << "\nDivision by zero!\n";
    }
    a->parseExpression(fin);
    fin.close();
    a->printTree(fout);
    fout << " = ";
    fout << a->calculate();
    fout.close();
    delete a;
    system("pause");
}

