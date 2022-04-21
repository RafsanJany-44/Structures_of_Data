#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *left;
    Node *right;
};

class BinarySearchTree{
    private:
        Node* root;

        void insertNode(Node *&tree, string data){
            if(tree == NULL){
                tree = new Node;
                tree->data = data;
                tree->left = NULL;
                tree->right = NULL;
            }else if(data < tree->data){
                insertNode(tree->left,data);
            }else{
                insertNode(tree->right,data);
            }
        }

        void printInOrder(Node *tree){
            if(tree == NULL){
                return;
            }
            printInOrder(tree->left);
            cout << tree->data << ", ";
            printInOrder(tree->right);
        }

        int treeLength(Node *tree){
            if(tree==NULL){
                return 0;
            }
            return 1+treeLength(tree->left)+treeLength(tree->right);
        }

        bool findNode(Node *tree, string data){
            if(tree==NULL){
                return false;
            }

            if(tree->data == data){
                return true;
            }else if(data < tree->data){
                return findNode(tree->left,data);
            }else{
                return findNode(tree->right,data);
            }
        }

        Node* retrieveNode(Node *tree, string data){
            if(tree==NULL){
                return NULL;
            }

            if(tree->data == data){
                return tree;
            }else if(data < tree->data){
                return retrieveNode(tree->left,data);
            }else{
                return retrieveNode(tree->right,data);
            }
        }

        void deleteNode(Node *&tree, string data){
            if(tree == NULL){
                return;
            }
            if(tree->data == data){
                if(tree->left == NULL && tree->right == NULL){
                    delete tree;
                    tree = NULL;
                }else if(tree->left != NULL){
                    string maxLeftNode = findMaxNode(tree->left);
                    tree->data = maxLeftNode;
                    deleteNode(tree->left,maxLeftNode);
                }else{
                    string minRightNode = findMinNode(tree->right);
                    tree->data = minRightNode;
                    deleteNode(tree->right,minRightNode);
                }
            }else if(tree->data < data){
                deleteNode(tree->right,data);
            }else{
                deleteNode(tree->left,data);
            }
        }

        string findMinNode(Node *tree){
            if(tree == NULL){
                return "None";
            }else if(tree->left == NULL){
                return tree->data;
            }else{
                return findMinNode(tree->left);
            }
        }

        string findMaxNode(Node *tree){
            if(tree == NULL){
                return "None";
            }else if(tree->right == NULL){
                return tree->data;
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
        void insertNode(string data){
            insertNode(root,data);
        }

        void printInOrder(){
            printInOrder(root);
        }

        string treeLength(){
            treeLength(root);
        }

        Node* retrieveNode(string data){
            return retrieveNode(root,data);
        }

        bool findNode(string data){
            return findNode(root,data);
        }

        void deleteNode(string data){
            deleteNode(root,data);
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
    bst.insertNode("abc dfasdf");
    bst.insertNode("asdf adf");
    bst.insertNode("asdf fasdf");
    bst.insertNode("asdf lkoj");
    bst.insertNode("fadf ljlkj");
    bst.insertNode("adf lkj");
    bst.insertNode("w");
    bst.insertNode("h");
    bst.printInOrder();
    cout<<endl;
    if(bst.checkDuplicate()==1){
        
        cout<<"The tree has duplicate values!!"<<endl;
    }
    else{
        cout<<"The tree has not duplicate values!!"<<endl;
    }
    

}