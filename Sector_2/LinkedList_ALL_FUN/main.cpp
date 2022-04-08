#include <iostream>
using namespace std;
// void addNodeAtEnd(int data)
//void addNodeAtFront(int data)
//void append(int data)
//void deleteFirstNode()
//void deleteLastNode()
//void len()
//void get(int)
//void insertNodeAt(int data,int index)
//int index(int data)

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

    void append(int data){
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
        delete current; // delete key word takes a address and deete. the head,current,head->next are addrees.
    }

    void deleteLastNode(){
        if (head==NULL){
            return;
        }
        Node *current=head;

        while(current->next->next!=NULL){//hare two next used to stop the while loop before the last node
            current=current->next;
        }
        delete current->next; 
        current->next=NULL;

    }

    void deleteNodeAt(int index){
        if(head==NULL){return;}

        if(index==1){deleteFirstNode();}

        Node *current=head;
        for(int i=1;i<index-1;i++){
            current=current->next;
        }
        Node *temp=current->next;
        current->next=current->next->next;
        delete temp;
    }

    int len(){
        
        int index=0;
        Node *current=head;
        while(current!=NULL){
            current=current->next;
            index++;
        }
        return index;
    }

    int get(int index){
        if(head==NULL){
            cout<<"List is empty!"<<endl;
        }

        if(index<0){
            int  len=this->len();
            index=len+index;
        }
        int i=0; 
        Node *current = head;
        while(current!=NULL){
            if(i==index){
            return current->data;
            }
            current = current->next;
            i++;
        }
        cout<<"Index out of range, Garbage=";
    }

    int index(int data){
        if(head==NULL){
            cout<<"List is empty!"<<endl;
        }
        Node* current = head;
        int i=0;
        while(current!=NULL){
            if(current->data==data){
                return i;
            }
            i++;
            current=current->next;
        }
        cout<<"No Item Found, Garbage=";
    }
    

    void printAllNode(){
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
    l.append(9);
    l.append(7);
    l.addNodeAtFront(6);
    l.addNodeAtFront(3);
    cout<<"Current :";
    l.printAllNode();
    l.insertNodeAt(8,3);
    cout<<"After :";
    l.printAllNode();

    /* cout<<"After deleting the first node: ";
    l.deleteFirstNode();
    l.printAllNode();
    cout<<"After deleting the last node: ";
    l.deleteLastNode();
    l.printAllNode();
    cout<<"After deleting the ith node: ";
    l.deleteNodeAt(5);
    l.printAllNode();
    cout<<"Showing the ith index: ";
    cout<<l.get(3);
    l.printAllNode();*/
    //cout<<l.get(5);
   // cout<<l.len();
    cout<<endl;
    /*for(int i=0;i<l.len();i++){
        cout<<l.get(i)<<endl;

    }*/
    cout <<l.index(9);
}