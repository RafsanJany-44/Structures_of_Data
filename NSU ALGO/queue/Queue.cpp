#include <iostream>
using namespace std;

class FullQueue{};
class EmptyQueue{};
template<typename T>
class Queue
{
  private:
    int front;
    int rear;
    T* items;
    int queueSize;
  public:
    Queue();
    Queue(int queueSize);
    ~Queue();
    void makeEmpty();
    bool isEmpty();
    bool isFull();
    void enqueue(T item);
    T dequeue();
};

// Definitions
template<typename T>
Queue<T>::Queue(int qSize){
    queueSize = qSize + 1;
    front = queueSize - 1;
    rear = queueSize - 1;
    items = new T[queueSize];
}
template<typename T>
Queue<T>::Queue(){
    queueSize = 11;
    front = queueSize - 1;
    rear = queueSize - 1;
    items = new T[queueSize];
}
template<typename T>
Queue<T>::~Queue(){
    delete [] items;
}
template<typename T>
void Queue<T>::makeEmpty(){
    front = queueSize - 1;
    rear = queueSize - 1;
}
template<typename T>
bool Queue<T>::isEmpty(){
    return (rear == front);
}
template<typename T>
bool Queue<T>::isFull(){
    return ((rear+1)%queueSize == front);
}
template<typename T>
void Queue<T>::enqueue(T item){
    if(isFull()){
        throw FullQueue();
    }else{
        rear = (rear +1) % queueSize;
        items[rear] = item;
    }
}
template<typename T>
T Queue<T>::dequeue(){
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
    Queue<char> q(qSize);

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
