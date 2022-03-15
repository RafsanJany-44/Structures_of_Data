#include <iostream>
using namespace std;
// Exception class thrown by push() when stack is full.
class FullStack{};
// Exception class thrown by pop() and Top when stack is empty.
class EmptyStack{};
// Class
template<typename T>
class Stack
{
private:
  int stackSize;
  int topIndex;
   T *items;
public:
  Stack();
  Stack(int);
  ~Stack();
  void makeEmpty();
  bool isFull();
  bool isEmpty();
  void push(T);
  void pop();
  T top();
};
// Definitions
template<typename T>
Stack<T>::Stack()
{
  stackSize = 5;
  items = new int[stackSize];
  topIndex = -1;
}
template<typename T>
Stack<T>::~Stack()
{
  delete [] items;
}
template<typename T>
Stack<T>::Stack(int stackSize)
{
  this->stackSize = stackSize;
  items = new T[stackSize];
  topIndex = -1;
}
template<typename T>
void Stack<T>::makeEmpty()
{
  topIndex = -1;
}
template<typename T>
bool Stack<T>::isEmpty()
{
  return (topIndex == -1);
}
template<typename T>
bool Stack<T>::isFull()
{
  return (topIndex ==  stackSize-1);
}
template<typename T>
void Stack<T>::push(T newItem)
{
  if(isFull())
    throw FullStack();
  topIndex++;
  items[topIndex] = newItem;
}
template<typename T>
void Stack<T>::pop()
{
  if(isEmpty())
    throw EmptyStack();
  topIndex--;
}
template<typename T>
T Stack<T>::top()
{
  if (isEmpty())
    throw EmptyStack();
  return items[topIndex];
}


int get_precedence (char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// main
int main()
{
    int qSize;
    int i;
    cout << "Enter the size of the queue: ";
    cin >> qSize;
    Queue<int> q(qSize);

    cout << "Enter " << qSize << " items into the queue: " << endl;
    while(!q.isFull()){
        cin>>i;
        q.enqueue(i);
    }
    cout << endl;


    int arr[qSize];
    int temp,temp2;
    int l=0;
    int check=-1;
    while(!q.isEmpty()){
        temp=q.dequeue();

        if (temp<check):

        arr[l]=temp;
        l++;
    }
    cout << endl;
    int k=0;

        while(!q.isFull()){
        q.enqueue(arr[k]);
        k++;
    }
    cout << endl;
    cout<<check;
}
