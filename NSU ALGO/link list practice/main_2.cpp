#include <iostream>
using namespace std;

struct Node_1{
    int data;
    Node_1 *next;
};

class LinkedList{
private:
    Node_1 *head;

public:

    LinkedList()
    {
        head= NULL;
    }

    void addNodeAtEnd(int data){
        
        //creating a new node
        Node_1 *n=new Node_1;
        n->data=data;
        n->next=NULL;
        // n node has been created
        
        if(head==NULL){//if there is no head then the n will be the first head
            head=n;
        }

        else{
            Node_1 *current=head; //seting the head node to a current node
            while(current->next!=NULL){// travarsing all node to the last one
                current=current->next;
            }
            current->next=n;//at the last node adding the node newly created
        }
    }

    void addNodeAtEnd(int data){
        Node_1 *n= new Node_1;
        n->data=data;
        n->next=NULL;
        if (head==NULL){
            head=n;
        }
        else{
            n->next=head;
        }
    }
    
    

    void printNode(){
        Node_1 *current=head;
        while(current!=NULL){
            cout << current->data<<"-> ";
            current=current->next;
        }
        cout<<endl;
    }

};

int main(){
    LinkedList l;
    l.addNodeAtEnd(5);
    l.addNodeAtEnd(4);
    l.addNodeAtEnd(3);
    l.printNode();
    
}