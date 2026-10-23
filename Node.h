#ifndef NODE_H
#define NODE_H

class Node {
public:
    explicit Node(int value);

    int value;
    Node* prev;
    Node* next;
};

#endif
