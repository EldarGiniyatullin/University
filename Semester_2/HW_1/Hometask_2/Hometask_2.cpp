#include <iostream>
#include "list.h"
#include "linkedstack.h"
#include "arraystack.h"
#include "doublylinkedlist.h"
#include "stackcalculator.h"

using namespace std;

int main()
{
//    Stack *myStack = new LinkedStack();
//    myStack->push(1);
//    myStack->pop();
//    myStack->pop();
//    delete myStack;
//    List *b = new DoublyLinkedList();
//    b->addElement(1);
//    b->deleteElement(1);
//    b->deleteElement(1);
//    b->addElement(2);
//    b->addElement(3);
//    b->deleteElement(2);
//    b->printList();
//    cout << "\n";
//    Stack *a = new ArrayStack(5);
//    a->push(1);
//    a->push('+');
//    a->push(2);
//    a->push('=');
//    a->push(4);
//    a->push(3);
//    a->pop();
//    a->push(3);
//    a->printStack();
//    delete a;
    StackCalculator *a = new StackCalculator();
    a->readOriginalExpression();
    a->reversePolishNotation();
    a->calculateReversePolishNotation();
    a->printResult();
    delete a;
}
