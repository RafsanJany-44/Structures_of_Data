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
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout << "Values in the stack: " << endl;
    while(!s1.isEmpty()){
        cout<<s1.Top()<<" ";
        s1.pop();
    }

    cout << endl << "Making stack empty..." << endl;
    s1.makeEmpty();
    cout << "Values in the stack: " << endl;
    while(!s1.isEmpty()){
        cout<<s1.Top()<<" ";
        s1.pop();
    }
}



