#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <initializer_list>

class Sorted_List
{
public:
    Sorted_List();
    Sorted_List(std::initializer_list<int> init_list);
    Sorted_List(Sorted_List const& copy_from);
    Sorted_List(Sorted_List && move_from);
    ~Sorted_List();

    Sorted_List& operator=(Sorted_List const& copy_from);
    Sorted_List& operator=(Sorted_List && move_from);

    void insert(int new_value);
    void print_all();
    void remove(int remove_value);
    bool is_empty();

private:
    class Node;
    // Member variables
    Node* head;
    Node* tail;

    // Inner node class
    class Node
    {
    public:
        Node() = default;
        Node(Node* next, Node* prev, int value);

        Node* next;
        Node* prev;
        int value;
    };

    void remove_list(Node* &curr);
    void remove_node(Node* &curr);
    void remove(int remove_value, Node* &curr);
    void construct_sentinel();
    void construct_node(int value, Node* &curr);
    void copy(Node* & to, Node* const& from);
    void insert(int new_value, Node* &curr);
    void print(Node* curr);

    // Help functions
    void print_head();
    void print_tail();
};

// TODO
// ostream& operator<<(ostream& out_stream, Sorted_List const& list);

#endif /* SORTED_LIST_H */