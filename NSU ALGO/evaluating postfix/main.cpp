#include <iostream>
#include <cmath>
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
  items = new T[stackSize];
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

int isOperator(char ch){
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;//character is an operator
      return -1;//not an operator
   }
   int isOperand(char ch){
      if(ch >= '0' && ch <= '9')
         return 1;//character is an operand
      return -1;//not an operand
   }
   float operation(int a, int b, char op){
      //Perform operation
      if(op == '+')
         return b+a;
      else if(op == '-')
         return b-a;
      else if(op == '*')
         return b*a;
      else if(op == '/')
         return b/a;
      else if(op == '^')
        return pow(b,a); 
      else
   return INT_MIN; //return negative infinity
}

float scanNum(char ch){
   int value;
   value = ch;
   return float(value-'0');//return float from character
}

// main
int main()
{
    int a, b;
   
   char postfix[100];
   cout<<"Enter a expression:";
   cin>>postfix;
   int n=strlen(postfix);
   Stack<float> s(n);
   for(int i=0; i<=n;i++){
      //read elements and perform postfix evaluation
      if(isOperator(postfix[i]) != -1){
         a = s.top();
         s.pop();
         b = s.top();
         s.pop();
         s.push(operation(a, b, postfix[i]));
      }else if(isOperand(postfix[i]) > 0){
         s.push(scanNum(postfix[i]));
      }
   }
   
   float ans= s.top();
   int count=0;
   while (!s.isEmpty()) {
       count++;
        s.pop();
    }
    if (count==1){
        cout<<"The Postfix is valid"<<endl;
        cout<<"The value is: "<<ans<<endl;
    }
    else{
        cout<<"The Postfix is invelid";
    
    }
}
