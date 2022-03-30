#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Deletes the first node from the list
    void deleteFirstNode()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Deletes the last node from the list
    void deleteLastNode()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            deleteFirstNode();
        }
        else
        {
            Node *current = head;
            while (current->next->next != NULL)
            {
                current = current->next;
            }
            delete current->next;
            current->next = NULL;
        }
    }

    // Adds a node at the front position of the list
    void addNodeAtFront(int data)
    {
        Node *n = new Node;
        n->data = data;
        n->next = head;
        head = n;
    }

    // Adds a node at the end of the list
    void addNodeAtEnd(int data)
    {
        Node *n = new Node;
        n->data = data;
        n->next = NULL;
        if (head == NULL)
        { // list is empty
            head = n;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = n;
        }
    }

    // Inserts a node at the specified position
    // The front node's position is 0
    void insertNode(int data, int position)
    {
        if (position == 0)
        {
            addNodeAtFront(data);
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < position - 1; i++)
            {
                current = current->next;
            }
            Node *n = new Node;
            n->data = data;
            n->next = current->next;
            current->next = n;
        }
    }

    // Inserts a node at the specified position
    // The front node's position is 0
    void deleteNode(int position)
    {
        if (position == 0)
        {
            deleteFirstNode();
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < position - 1; i++)
            {
                current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    void printNodes()
    {
        Node *current = head;
        cout << "head -> ";
        while (current != NULL)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    // return the average value of all nodes
    float getAverage()
    {
        Node *current = head;
        int sum = 0;
        float avg = 0;
        int index = 0;
        while (current != NULL)
        {

            sum = sum + current->data;
            current = current->next;
            index = index + 1;
        }
        avg = (sum / index);
        return avg;
    }

    // prints the value of middle node.
    // if the list has even number of nodes
    // then print two values
  void printMiddleNode(){
    Node *current = head;
        int index = 0;
        while (current != NULL)
        {
            current = current->next;
            index = index + 1;
        }
  
      if (index%2==0){
      int mid1,mid2;
      Node *cur = head;
        int i = 0;
        while (cur != NULL)
        {
          
          if(i==(index/2)-1){
            mid1=cur->data;
          }
          if(i==(index/2)){
            mid2=cur->data;
          }
            i = i + 1;
          cur = cur->next;
        }
      cout<<"The mid(s) are: "<<mid1<<","<<mid2;
    }
    else{
      int mid;
      Node *curr = head;
        int i = 0;
        while (curr != NULL)
        {
          
          if(i==(index/2)){
            mid=curr->data;
          }
            i = i + 1;
          curr = curr->next;
        }
      cout<<"The mid is: "<<mid;
      
    }
  }

};

int main()
{
    LinkedList LL;
    LL.addNodeAtEnd(6);
    LL.addNodeAtEnd(4);
    LL.addNodeAtEnd(5);
   // LL.addNodeAtEnd(7);
    LL.printNodes();
    cout<<"The avarage:";
    cout << LL.getAverage()<<endl;
    LL.printMiddleNode();
    // Complete the getAverage() function
    // Complete the printMiddleNode() function
    // Test these two functions in the main function
}
