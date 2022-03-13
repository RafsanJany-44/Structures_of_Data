#include <iostream>
using namespace std;
//add
class FullQueue{};
class EmptyQueue{};

class Queue
{
  private:
    int front;
    int rear;
    char* items;
    int queueSize;
  public:
    Queue();
    Queue(int queueSize);
    ~Queue();
    void makeEmpty();
    bool isEmpty();
    bool isFull();
    void enqueue(char item);
    char dequeue();
};

// Definitions
Queue::Queue(int qSize){
    queueSize = qSize + 1;
    front = queueSize - 1;
    rear = queueSize - 1;
    items = new char[queueSize];
}

Queue::Queue(){
    queueSize = 11;
    front = queueSize - 1;
    rear = queueSize - 1;
    items = new char[queueSize];
}

Queue::~Queue(){
    delete [] items;
}

void Queue::makeEmpty(){
    front = queueSize - 1;
    rear = queueSize - 1;
}

bool Queue::isEmpty(){
    return (rear == front);
}

bool Queue::isFull(){
    return ((rear+1)%queueSize == front);
}

void Queue::enqueue(char item){
    if(isFull()){
        throw FullQueue();
    }else{
        rear = (rear +1) % queueSize;
        items[rear] = item;
    }
}

char Queue::dequeue(){
    if(isEmpty()){
        throw EmptyQueue();
    }else{
        front = (front + 1) % queueSize;
        return items[front];
    }
}

// main
int main()
{
    int qSize;
    char i;
    cout << "Enter the size of the queue: ";
    cin >> qSize;
    Queue q(qSize);

    cout << "Enter " << qSize << " items into the queue: " << endl;
    while(!q.isFull()){
        cin>>i;
        q.enqueue(i);
    }
    cout << endl;

    cout << "Dequeuing " << qSize/2 << " items from the queue: " << endl;
    for(int i=0; i<qSize/2; i++){
        cout << q.dequeue() << ", ";
    }
    cout << endl << endl;

    cout << "Enter " << qSize/2 << " items into the queue: " << endl;
    while(!q.isFull()){
        cin>>i;
        q.enqueue(i);
    }
    cout << endl;

    cout << "Dequeuing all items from the queue: " << endl;
    while(!q.isEmpty()){
        cout << q.dequeue() << ", ";
    }
    cout << endl;
}
