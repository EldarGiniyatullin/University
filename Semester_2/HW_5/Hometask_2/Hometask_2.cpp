#include "testset.h"
#include "set.h"

int main()
{
    TestSet testSet;
    QTest::qExec(&testSet);
    system("pause");
}

