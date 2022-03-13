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

void PrintStack(Stack<char> s)
{
    Stack<char> temp;
    while (s.isEmpty() == false)
    {
        temp.push(s.top());
        s.pop();
    }  
 
    while (temp.isEmpty() == false)
    {
        char t = temp.top();
        cout << t << " ";
        temp.pop();
        s.push(t); 
    }
}

// main
int main()
{
    char infix[100];
    //char postfix[100];
    string postfix;
    cout<<"Enter the Infix:"<<endl;
    cin >> infix;
    int n=strlen(infix);
    Stack<char> s(n);

    
    /*int i=0;
    while(!s.isFull()){
        s.push(st[i]);
        i++;
    }
    cout << endl;
    cout << "Printing stack.." << endl;
    while(!s.isEmpty()){
        cout << s.top() << endl;
        s.pop();
    }*/
    for(int i = 0; i < n; i++) {
        char c = infix[i];

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            postfix += c;
        else if(c == '(')
            s.push('(');
        else if(c == ')') {
            while(s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while(!s.isEmpty() && get_precedence(infix[i]) <= get_precedence(s.top())) {
                postfix += s.top();
                s.pop(); 
            }
            s.push(c);
        }
        cout<<postfix<<"-----"<< endl;
        PrintStack(s);
        
    }
    while(!s.isEmpty()) {
        postfix += s.top();
        s.pop();
    }
    cout<<"The Postfix of the given Infix:"<<endl;
    cout << postfix << endl;
}
//  (4+8)*(6-5)/((3-2)*(2+2))