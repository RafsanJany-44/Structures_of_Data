#include <iostream>
using namespace std;

// Exception class thrown by push() when stack is full.
class FullStack{};

// Exception class thrown by pop() and Top when stack is empty.
class EmptyStack{};

// Class
class Stack
{
private:
   int stackSize;
   int topIndex;
   int *items;

public:
   Stack();
   Stack(int);
   ~Stack();
   void makeEmpty();
   bool isFull();
   bool isEmpty();
   void push(int);
   void pop();
   int top();
};

// Definitions
Stack::Stack()
{
  stackSize = 5;
  items = new int[stackSize];
  topIndex = -1;
}

Stack::~Stack()
{
  delete [] items;
}

Stack::Stack(int stackSize)
{
  this->stackSize = stackSize;
  items = new int[stackSize];
  topIndex = -1;
}

void Stack::makeEmpty()
{
  topIndex = -1;
}

bool Stack::isEmpty()
{
  return (topIndex == -1);
}

bool Stack::isFull()
{
  return (topIndex ==  stackSize-1);
}

void Stack::push(int newItem)
{
  if(isFull())
    throw FullStack();
  topIndex++;
  items[topIndex] = newItem;
}

void Stack::pop()
{
  if(isEmpty())
    throw EmptyStack();
  topIndex--;
}

int Stack::top()
{
  if (isEmpty())
    throw EmptyStack();
  return items[topIndex];
}

// main
int main()
{
    int n;
    cout << "Enter the size of the stack: ";
    cin >> n;
    Stack s(n);

    cout << "Enter some values into the stack.." << endl;
    while(!s.isFull()){
        cin>>n;
        s.push(n);
    }
    cout << endl;

    cout << "Printing stack.." << endl;
    while(!s.isEmpty()){
        cout << s.top() << endl;
        s.pop();
    }
}
