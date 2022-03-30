#include<iostream>
using namespace std;

struct Item{
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

    }

    void dequeue(){

    }

    // returns the first item (int) without removing it
    int firstItem(){

    }

    bool isEmpty(){

    }

    void makeEmpty(){

    }
};

int main(){
    //Complete the functions above
    //Call each function here in the main()
    //to test if they are working correctly
}