#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
private:
    Node *head;
public:
    LinkedList(){
        head = NULL;
    }

    void deleteFirstNode(){
        if(head == NULL){
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLastNode(){
        if(head == NULL){
            return;
        }
        if(head->next == NULL){
            deleteFirstNode();
        }else{
            Node *current = head;
            while(current->next->next!=NULL){
                current=current->next;
            }
            delete current->next;
            current->next = NULL;
        }
    }

    void addNodeAtFront(int data){
        Node *n = new Node;
        n->data = data;
        n->next = head;
        head = n;
    }

    void appendNode(int data){
        Node *n = new Node;
        n->data = data;
        n->next = NULL;
        if(head==NULL){ //list is empty
            head = n;
        }else{
            Node *current = head;
            while(current->next!=NULL){
                current=current->next;
            }
            current->next = n;
        }
    }

    void printNodes(){
        Node *current = head;
        cout << "head -> ";
        while(current!=NULL){
            cout << current->data << " -> ";
            current=current->next;
        }
        cout << endl;
    }
        void printLastNode(){
        Node *current = head;
        cout << "Last -> ";
        int i=0;
        while(i<this->getLength()-1){
            current=current->next;
            i++;
        }
        cout << current->data;
    }

    int getLength() {  
    int count = 0; 
    Node* current = head;
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count; 
} 

};

int main(){
    // Create a LinkedList
    LinkedList L;
    // Add two nodes at the beginning of the list
    L.addNodeAtFront(1);
    L.addNodeAtFront(10);
    // Print the list
    L.printNodes();
    // Add two nodes at the end of the list
    L.appendNode(2);
    L.appendNode(3);
    // Print the list
    L.printNodes();
 /*   // Delete the last node
    L.deleteLastNode();
    // Print the list
    L.printNodes();
    // Delete the first node
    L.deleteFirstNode();
    // Print the list
    L.printNodes();*/
    cout << L.getLength();
    L.printLastNode();
}
