#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
private:
    Node *head;

    void printListRecursive(Node *n){
        if(n == NULL){
            return;
        }
        cout << n->data << ", ";
        printListRecursive(n->next);
    }

    void addNodeAtEndRecursive(int data, Node *&n){
        if(n == NULL){
            n = new Node;
            n->data = data;
            n->next = NULL;
            return;
        }
        addNodeAtEndRecursive(data, n->next);
    }

    void deleteAllNodes(Node *&n){
        if(n == NULL){
            return;
        }
        Node *temp = n;
        n = n->next;
        delete temp;
        deleteAllNodes(n);
    }


    void printListReverse(Node *n){
        // complete this recursive function
	if (n == NULL)
		return;
	printListReverse(n->next);
	cout << n->data << ", ";
    }

    int sumOfList(Node *n){
        // complete this recursive function
          int sum = 0;
   while (head != NULL) {
     sum += head->data; 
     head = head->next;
   }
   return sum;
    }

public:
    LinkedList(){
        head = NULL;
    }

    // Deletes the first node from the list
    void deleteFirstNode(){
        if(head == NULL){
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Deletes the last node from the list
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

    // Adds a node at the front position of the list
    void addNodeAtFront(int data){
        Node *n = new Node;
        n->data = data;
        n->next = head;
        head = n;
    }

    // Adds a node at the end of the list
    void addNodeAtEnd(int data){
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

    // Inserts a node at the specified position
    // The front node's position is 0
    void insertNode(int data, int position){
        if(position==0){
            addNodeAtFront(data);
        }else{
            Node *current = head;
            for(int i=0; i<position-1; i++){
                current = current->next;
            }
            Node *n = new Node;
            n->data = data;
            n->next = current->next;
            current->next = n;
        }
    }

    // Inserts a node at the specified position
    // The front node's position is 0
    void deleteNode(int position){
        if(position==0){
            deleteFirstNode();
        }else{
            Node *current = head;
            for(int i=0; i<position-1; i++){
                current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
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

    void printList(){
        printListRecursive(head);
    }

    void addNodeAtEndRecursive(int data){
        addNodeAtEndRecursive(data,head);
    }

    void deleteAllNodes(){
        deleteAllNodes(head);
    }

    void printListReverse(){
        printListReverse(head);
    }

    int sumOfList(){
        return sumOfList(head);
    }

};

int main(){
    LinkedList LL;
    LL.addNodeAtEndRecursive(6);
    LL.addNodeAtEndRecursive(4);
    LL.addNodeAtEndRecursive(5);
    LL.printList();
    cout <<endl;
    cout <<"The reverse List: ";
    LL.printListReverse();
    cout << endl;
    cout<<"The sum: "<<LL.sumOfList()<<endl;
    // Complete the printListReverse(Node *n) function
    // Complete the sumOfList(Node *n) function
    // Test these two functions in the main function
}
