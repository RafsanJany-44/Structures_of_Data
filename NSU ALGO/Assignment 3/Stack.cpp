#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){
        top = NULL;
    }

    void push(int data){
        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;
        if (top == NULL){
            top = temp;
        }
        else{
            temp->next = top;
            top = temp;
        }
    }

    void pop(){
        if (top == NULL){
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    int Top(){
        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }

    void makeEmpty(){
        while(top != NULL){
            pop();
        }
        top = NULL;
    }
};
int main(){
    //Complete the functions above
    //Call each function here in the main()
    //to test if they are working correctly
    Stack stack;
    stack.push(2);
    stack.push(0);
    stack.push(3);
    stack.push(1);
    stack.push(7);
    stack.push(4);
    stack.push(1);
    stack.push(6);
    stack.push(4);
    stack.push(2);
    cout << "Staack elements: " << endl;
    while(!stack.isEmpty()){
        cout<<stack.Top()<<" ";
        stack.pop();
    }
    cout << "Deleting each elements" << endl;
    stack.makeEmpty();
    cout << "Queue elements:  " << endl;
    while(!stack.isEmpty()){
        cout<<stack.Top()<<" ";
        stack.pop();
    }
}


