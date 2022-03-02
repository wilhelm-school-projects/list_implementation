#include "Sorted_List.h"
#include <iostream>
#include <initializer_list>

using namespace std;

/* (De)constructors */
Sorted_List::Sorted_List()
{
    construct_sentinel();
}

Sorted_List::Sorted_List(initializer_list<int> init_list)
{
    construct_sentinel();
    for (int value : init_list)
    {
        insert(value);
    }
}

//Copy constructor
Sorted_List::Sorted_List(Sorted_List const& copy_from)
{   
    construct_sentinel();
    copy(head, copy_from.head);
}

//Move constructor
Sorted_List::Sorted_List(Sorted_List && move_from)
{   
    head = move_from.head;
    tail = move_from.tail;
    move_from.head = nullptr;
    move_from.tail = nullptr;
}

Sorted_List::~Sorted_List()
{
    remove_list(head);
}
//Copy Assignment
Sorted_List& Sorted_List::operator=(Sorted_List const& copy_from)
{
    copy(head, copy_from.head);
    return *this;
}

//Move Assignment
Sorted_List& Sorted_List::operator=(Sorted_List && move_from)
{
    delete tail;
    
    head = move_from.head;
    tail = move_from.tail;
    move_from.head = nullptr;
    move_from.tail = nullptr;

    return *this;
}

Sorted_List::Node::Node(Node* next, Node* prev, int value)
    :   next{next}, prev{prev}, value{value}
{
}

/* Public functions */
void Sorted_List::remove(int remove_value)
{
    remove(remove_value, head);
}

void Sorted_List::print_all()
{
    print(head);
    cout << endl;
}

bool Sorted_List::is_empty()
{
    return head == tail;
}

void Sorted_List::insert(int new_value)
{
    insert(new_value, head);
}

/* Private functions */

void Sorted_List::copy(Node*& to, Node* const& from)
{
    if (!(from->next == nullptr))
    {
        construct_node(from->value, to);
        copy(to->next, from->next);
    }
}

void Sorted_List::insert(int new_value, Node* &curr)
{
    if (is_empty())
    {
        construct_node(new_value, curr);
    }
    else if (curr == tail || new_value <= curr->value)
    {
        construct_node(new_value, curr);
    }   
    else if (new_value > curr->value)
    {
        insert(new_value, curr->next);
    }
    
}
 void Sorted_List::remove(int remove_value, Node* &curr)
 {
    if (is_empty() || curr == tail)
    {
        throw logic_error{"No such element!"};
    }
    else if (remove_value != curr->value)
    {
        remove(remove_value, curr->next);
    }   
    else
    {
        remove_node(curr);
    }
 }

void Sorted_List::remove_node(Node* &curr)
{
    Node* tmp{curr->next};
    tmp->prev = curr->prev;
    delete curr;
    curr = tmp;
}

void Sorted_List::remove_list(Node* &curr)
{
    if (curr == tail)
    {
        delete curr;
        return;
    }
    remove_list(curr->next);
    delete curr;
}

void Sorted_List::construct_node(int value, Node* &curr)
{
    curr->prev = new Node{curr, curr->prev, value};
    curr = curr->prev;
}

void Sorted_List::construct_sentinel()
{
    head = new Node{};
    tail = head;
}

void Sorted_List::print(Node* curr)
{
    if (curr != tail)
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

