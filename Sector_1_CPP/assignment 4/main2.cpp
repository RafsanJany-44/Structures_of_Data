#include <iostream>
#include<string.h>
using namespace std;

struct Node
{
    string data;
    string number;
    Node *left;
    Node *right;
};

class BinarySearchTree{
    private:
        Node* root;

        void insertNode(Node *&tree, string data,string number){
            if(tree == NULL){
                tree = new Node;
                tree->data = data;
                tree->number=number;
                tree->left = NULL;
                tree->right = NULL;
            }else if(number < tree->number){
                insertNode(tree->left,data,number);
            }else{
                insertNode(tree->right,data,number);
            }
        }

        void printInOrder(Node *tree){
            if(tree == NULL){
                cout<<endl;
                return;
            }
            printInOrder(tree->left);
            cout << tree->data << ", "<<tree->number;
            printInOrder(tree->right);
        }

        int treeLength(Node *tree){
            if(tree==NULL){
                return 0;
            }
            return 1+treeLength(tree->left)+treeLength(tree->right);
        }

        bool findName(Node *tree, string data){
            if(tree==NULL){
                return false;
            }

            if(tree->data == data){
                cout<<tree->data<<", "<<tree->number<<endl;
                cout<<endl;
                return true;
            }else if(data < tree->data){
                return findName(tree->left,data);
            }else{
                return findName(tree->right,data);
            }
        }

        Node* retrieveName(Node *tree, string data){
            if(tree==NULL){
                return NULL;
            }

            if(tree->data == data){
                return tree;
            }else if(data < tree->data){
                return retrieveName(tree->left,data);
            }else{
                return retrieveName(tree->right,data);
            }
        }

            bool findNumber(Node *tree, string number){
            if(tree==NULL){
                cout<<endl;
                cout<<"No contact found"<<endl;
                cout<<endl;
                return false;
            }

            if(tree->number == number){
                Node* temp=tree;
                cout<<"Contact found:"<<endl;
                cout<<tree->data<<", "<<tree->number<<endl;
                cout<<endl;
                return true;
            }else if(number < tree->number){
                return findNumber(tree->left,number);
            }else{
                return findNumber(tree->right,number);
            }
        }

        Node* retrieveNumber(Node *tree, string number){
            if(tree==NULL){
                return NULL;
            }

            if(tree->number == number){
                cout<< tree->data<<", "<<tree->number<<endl;
                return tree;
            }else if(number < tree->number){
                return retrieveNumber(tree->left,number);
            }else{
                return retrieveNumber(tree->right,number);
            }
        }

    Node* deleteNode(Node * root, string num)
    {
        if (root == NULL) return root;

        if (num.compare(root->number)<0)
            root->left = deleteNode(root->left,num);

        else if (num.compare(root->number)>0)
            root->right =deleteNode(root->right,num);

        else
        {

            if (root->left == NULL)
            {
                Node *temp = root->right;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->number = temp->number;
            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
            }
            return root;
        }
        Node* minValueNode(Node* l)
        {
        Node* current = l;

        while (current->left != NULL)
            current = current->left;

        return current;
    }

    string findMinNode(Node *tree){
            if(tree == NULL){
                return "Null";
            }else if(tree->left == NULL){
                return tree->number;
            }else{
                return findMinNode(tree->left);
            }
        }
        string findMaxNode(Node *tree){
            if(tree == NULL){
                return "Null";
            }else if(tree->right == NULL){
                return tree->number;
            }else{
                return findMaxNode(tree->right);
            }
        }
        void makeEmpty(Node *&tree){
            if(tree == NULL){
                return;
            }
            makeEmpty(tree->left);
            makeEmpty(tree->right);
            delete tree;
            tree = NULL;
        }

        int getHeight(Node *tree){
            if(tree == NULL){
                return 0;
            }
            int lsh = 1+getHeight(tree->left);
            int rsh = 1+getHeight(tree->right);

            if(lsh > rsh){
                return lsh;
            }else{
                return rsh;
            }
        }

        int countNodes(Node *tree){
            if(tree==NULL){
                return 0;
            }
            return 1+countNodes(tree->left)+countNodes(tree->right);
        }

        bool checking(Node* parent, string val) {
            if(parent == nullptr)
                return false;
            if (val == parent->data){
                return true;
            }
            else{
                bool left = checking(parent->left, val);
                bool right = checking(parent->right, val);
                return left||right;
            }
        }
        bool checkDuplicate(Node* parent) {
        if (parent != nullptr) {
            if(checking(parent->left, parent->data)) return true;
            if(checking(parent->right, parent->data)) return true;
            return checkDuplicate(parent->left)||checkDuplicate(parent->right);
        }
        else return false;
    }





    public:
        BinarySearchTree(){
            root = NULL;
        }
        void insertNode(string data,string number){
            insertNode(root,data,number);
        }

        void printInOrder(){
            printInOrder(root);
        }

        string treeLength(){
            treeLength(root);
        }

        Node* retrieveName(string data){
            return retrieveName(root,data);
        }


        Node* retrieveNumber(string number){
            return retrieveNumber(root,number);
        }

        bool findName(string data){
            return findName(root,data);
        }

        bool findNumber(string number){
            return findNumber(root,number);
        }

        void deleteNode(string number){
            deleteNode(root,number);
        }

        string findMinNode(){
            findMinNode(root);
        }
        string findMaxNode(){
            findMaxNode(root);
        }

        bool isBalanced();

        void makeEmpty(){
            makeEmpty(root);
        }

        string getHeight(){
            getHeight(root);
        }

        bool isEmpty(){
            if(root == NULL){
                return true;
            }else{
                return false;
            }
        }

        int countNodes(){
            return countNodes(root);
        }
        bool checkDuplicate()
        {
            return checkDuplicate(root);
        }
};


int main(){
    BinarySearchTree bst;
    cout<<"********************"<<endl;
    cout<<"*** CONTACT BOOK ***"<<endl;
    cout<<"********************"<<endl;
    cout<<endl;

while(true){
    cout<<"------ Menu --------"<<endl;
    cout<<"1. View all contacts"<<endl;
    cout<<"2. Add new contact"<<endl;
    cout<<"3. Search a contact by name"<<endl;
    cout<<"4. Search a contact by phone number"<<endl;
    cout<<"5. Delete a contact"<<endl;
    cout<<"6. Delete all contacts"<<endl;
    cout<<"7. Exit program"<<endl;
    int d;
    cout<<"--------------------"<<endl;
    cout<<"Select an option(1-7): ";

    cin>>d;
    cout<<"--------------------"<<endl;
    if(d==7){
        cout<<endl;
        cout<<"> Are you sure? Enter y for yes, n for no: ";
        string y;
        cin>>y;
        if(y==y){
            bst.makeEmpty();
            cout<<endl;
            break;
        }
    }

    else if(d==1){
        if(bst.isEmpty()==false){
        cout<<endl;
        cout<<"*** View Contacts ***"<<endl;
        cout<<endl;
        cout<<"Showing "<< bst.countNodes() <<" contacts:";
        bst.printInOrder();
        cout<<endl;
        }
        else{
            cout<<endl;
            cout<<"Contact book is empty."<<endl;
            cout<<endl;
        }
    }

    else if(d==2){
        string name;
        string number;
        cout<<"> Enter name: ";
        cin.ignore();
        getline(cin,name);
        cout<<"> Enter number: ";
        cin>>number;
        bst.insertNode(name,number);
        cout<<endl;
        cout<<endl;
        if(bst.checkDuplicate()==1){
            bst.deleteNode(number);
            cout<<"Error: A contact with phone number 1234 already exists."<<endl;
            cout<<endl;
            cout<<endl;
        }
        else{
        cout<<"Contact added successfully."<<endl;
        }
    }

    else if(d==4){
        cout<<endl;
        cout<<"*** Search Contact By Phone Number ***"<<endl;
        string num;
        cout<<"> Enter a Number: ";
        cout<<endl;
        cin>>num;
        bst.findNumber(num);
        
    }
    
    else if(d==5){
        cout<<"> Enter a phone number: ";
        string num;
        cin>>num;
        if(bst.findNumber(num)){
            cout<<"> Delete this contact? Enter y for yes, n for no:";
            string y;
            cin>>y;
            if(y=="y"){
                bst.deleteNode(num);
                cout<<endl;
                cout<<"Contact deleted successfully."<<endl;
                cout<<endl;
            }
        }
    }

    else if(d==6)
    {
        cout<<"*** Delete All Contacts ***"<<endl;
        cout<<endl;
        cout<<"> Are you sure? Enter y for yes, n for no: ";
        string y;
        cin>>y;
        if(y==y){
            bst.makeEmpty();
            cout<<endl;
            cout<<"All contacts deleted."<<endl;
        }
    }

    else if(d==3){
        string name;
        cout<<"Enter name: ";
        cin.ignore();
        getline(cin,name);
    }
    }

    cout<<"*** Thank you for using Contact Book ***"<<endl;

}