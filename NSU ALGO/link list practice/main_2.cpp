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
        
        //creating a new node
        Node *n=new Node;
        n->data=data;
        n->next=NULL;
        // n node has been created
        
        if(head==NULL){//if there is no head then the n will be the first head
            head=n;
        }

        else{
            Node *current=head; //seting the head node to a current node
            while(current->next!=NULL){// travarsing all node to the last one
                current=current->next;
            }
            current->next=n;//at the last node adding the node newly created
        }
    }

    void addNodeAtFront(int data){
        Node *n=new Node;
        n->data=data;
        n->next=head;
        head=n;
    }

    void insertNodeAt(int data,int position){
        Node *n=new Node;
        n->data=data;
        n->next=NULL;
        if(head==NULL){
            head=n;
            return;
        }
        if(position==1){
            addNodeAtFront(data);
            return;
        }

        Node *current=head;
        for(int i=1;i<position-1;i++){
            cout<<current->data<<endl;
            current=current->next;   
        }
        n->next=current->next;
        current->next=n;
        
        
    }

    void deleteFirstNode(){
        if (head==NULL){
            return;
        }
        Node *current=head; //if we do not this line the the memry will be allocated with previous head
        head=head->next;
        delete head;
    }
    
    

    void printNode(){
        Node *current=head;
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
    
    l.addNodeAtFront(6);
    l.addNodeAtFront(3);
    cout<<"Current :";
    l.printNode();
    l.insertNodeAt(8,3);
    cout<<"After :";
    l.printNode();

    cout<<"After deleting the first node: ";
    l.deleteFirstNode();
    l.printNode();
    
    
}