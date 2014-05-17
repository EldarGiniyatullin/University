#include <iostream>

using std::cout;

class TestClass
{
public:
    TestClass()
    {
        cout << "+TestClass()\n";
    }
    ~TestClass()
    {
        cout << "-TestClass()\n";
    }

    void add(int i)
    {
        if (i == 1)
            cout << "add(1)\n";
        else
        {
            throw Exception();
        }
    }
    class Exception
    {
    public:
        Exception()
        {
            cout << "Exception thrown\n";
        }
    };
};

int main()
{
    try
    {
        TestClass a;
        TestClass b;
        a.add(1);
        b.add(2);
    }
    catch (TestClass::Exception &)
    {
        cout << "Exception is caught\n";
    }
    system("pause");
}
