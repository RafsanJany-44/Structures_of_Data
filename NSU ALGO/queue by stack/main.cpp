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


struct Queue { 
	Stack<int> s; 

	// Enqueue an item to the queue 
	void enqueue(int x) 
	{ 
		s.push(x); 
	} 

	// Dequeue an item from the queue 
	int dequeue() 
	{ 
		if (s.isEmpty()) { 
			cout << "Queue is empty" << endl;; 
			exit(0); 
		} 

		// pop an item from the stack 
		int x = s.top(); 
		s.pop(); 

		// if stack becomes empty, return 
		// the popped item 
		if (s.isEmpty()) 
			return x; 

		// recursive call 
		int ret = dequeue(); 

		// push popped item back to the stack 
		s.push(x); 

		// return the result of deQueue() call 
		return ret; 
	} 
}; 



// main
int main()
{
Queue q; 
	q.enqueue(3); 
	q.enqueue(4); 
	q.enqueue(5); 

	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl; 
	cout << q.dequeue() << endl; 

	return 0; 
}
