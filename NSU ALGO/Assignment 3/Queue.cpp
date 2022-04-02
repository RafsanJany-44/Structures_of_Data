#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Queue{
private:
    Node *first;
    Node *last;
public:
    Queue(){
        first = NULL;
        last = NULL;
    }

    void enqueue(int data){
        Node *temp = new Node;
        temp->data = data;
        temp->next = NULL;
        if(first==NULL & last==NULL){
            first = temp;
            last = temp;
        }
        else{
            Node *current = first;
            while(current->next!=NULL){
                current=current->next;
            }
            current->next = temp;
            last = temp;
        }

    }

    void dequeue(){
        if(first == NULL){
            return;
        }
        Node *temp = first;
        first = first->next;
        delete temp;
    }

    // returns the first item (int) without removing it
    int firstItem(){
        return first->data;
    }

    bool isEmpty(){
        return first == NULL;
        return last == NULL;
    }

    void makeEmpty(){
        while(first != NULL){
            dequeue();
        }
        first == NULL;
        last == NULL;
    }
};

int main(){
    Queue queue;
    queue.enqueue(2);
    queue.enqueue(0);
    queue.enqueue(3);
    queue.enqueue(1);
    queue.enqueue(7);
    queue.enqueue(4);
    queue.enqueue(1);
    queue.enqueue(6);
    queue.enqueue(4);
    queue.enqueue(2);
    cout << "Queue elements: ";
    while(!queue.isEmpty()){
        cout << queue.firstItem() <<" ";
        queue.dequeue();
    }
    cout << endl;
    cout << "Deleting each elements" << endl;
    queue.makeEmpty();
    cout << "Queue elements:  " << endl;
    while(!queue.isEmpty()){
        cout << queue.firstItem() <<" ";
        queue.dequeue();
    }
}
