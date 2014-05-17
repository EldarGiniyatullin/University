#include <iostream>
#include "testuniquelist.h"
#include "listtest.h"

using std::cout;

int main()
{
    TestUniqueList testUniqueList;
    QTest::qExec(&testUniqueList);

    cout << "\n";

    ListTest listTest;
    QTest::qExec(&listTest);

    cout << "\n";



    UniqueList<int> *a = new UniqueList<int>;
    try
    {
        a->deleteValue(5);
    }
    catch(UniqueList<int>::NoValueInList &)
    {
        cout << "\nNoValueInList exception is caught";
    }

    a->addValue(5);

    try
    {
        a->addValue(5);
    }
    catch(UniqueList<int>::ValueIsAddedYet &)
    {
        cout << "\nValueIsAddedYet exception is caught";
    }

    delete a;

    cout << "\n";

    system("pause");
}

