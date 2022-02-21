#include "Sorted_List.h"
#include <iostream>

using namespace std;

Sorted_List::Sorted_List()
{
    construct_sentinel();
}

// TODO
Sorted_List::~Sorted_List()
{
}

// Public functions
void Sorted_List::insert()
{
    // TODO
}

void Sorted_List::print_all()
{
    print(head);
    cout << endl;
}

// Private functions of all its kinds
void Sorted_List::construct_sentinel()
{
    head = new Node{};
    tail = head;
}

void Sorted_List::print(Node* curr)
{
    if (curr == tail)
    {
        return;
    }
    else
    {
        cout << curr->value << " ";
        print(curr->next);
    }
}

void Sorted_List::print_head()
{
    cout << "Head: " << head->value << endl;
}
void Sorted_List::print_tail()
{
    cout << "Tail: " << tail->value << endl;
}

