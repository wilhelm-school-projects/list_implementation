#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class Sorted_List
{
public:
    Sorted_List();
    ~Sorted_List();

    void insert();
    void print_all();

private:
    class Node;

    // Member variables
    Node *head;
    Node *tail;

    // Inner node class
    class Node
    {
    public:
        Node() = default;

        Node *next;
        int value;
    };

    // Simply private functions
    void construct_sentinel();
    void print(Node* curr);

    // Help functions
    void print_head();
    void print_tail();
};

#endif /* SORTED_LIST_H */