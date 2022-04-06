#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
private:
    Node *head;

public:

    LinkedList()
    {
        head= NULL;
    }

    void addNodeAtEnd(int data){
        Node *n=new Node;
        n->data=data;
        n->next=NULL;
        if(head==NULL){
            head=n;
        }
    }
    



};