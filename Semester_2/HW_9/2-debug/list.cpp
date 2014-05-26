#include "list.h"

List::List(): next(NULL)
{
    value = 0;
    length = 0;
}

List::List(int newValue)
{
    value = newValue;
    next = NULL;
    //еще это по ногам стреляло
    //length = 1;
    length = 0;
}

void List::add(int newValue)
{
    if (next == NULL)
    {
        next = new List (newValue);
        length++;
    }
    else
    {
        next->add(newValue);
        if (next->length == this->length)
            this->length++;
    }
    //вот корень зла
    //изменение длины-то наверх не шло
}
bool List::search(int valueSearch)
{
    List *temp;
    temp = this;
    while (temp != NULL)
    {
        if (temp->value == valueSearch)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
void List::showAll()
{
    List *temp;
    temp = this;
    if (temp->next == NULL)
    {
        cout << " Empty \n";
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
        cout << temp->value << " ";

    }
    cout << "\n";
}
void List::deleteFromList(int valueDelete)
{
    if (!search(valueDelete))
    {
        return;
    }
    List *temp1, *temp2;

    temp1 = this;

    if (temp1->next->value == valueDelete)    // head
    {
        temp2 = temp1->next;
        this->next = this->next->next;
        delete temp2;
        length--;
        return;
    }
    temp1 = temp1->next;
    while (temp1->next->value != valueDelete)
    {
        temp1 = temp1->next;
    }
    if (temp1->next->next == NULL) // tail
    {
        temp2 = temp1->next;
        temp1->next = NULL;
        length--;
        delete temp2;
    }
    else
    {
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        length--;
        delete temp2;
    }
}
void List::deleteAll()
{
    List *temp, *temp2;
    temp = this->next;

    while (temp != NULL)
    {
        temp2 = temp;
        temp = temp->next;
        delete temp2;
    }
    this->next = NULL;
}
int List::getValue()
{
    return next->value;
}
