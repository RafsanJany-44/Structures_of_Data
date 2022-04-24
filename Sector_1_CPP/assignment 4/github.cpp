#include <iostream>
using namespace std;
struct Contact
{
    string name;
    string phoneNumber;
    Contact *left;
    Contact *right;
};
class ContactBook{
private:
    Contact *root;
    void insertContact(Contact *&tree,string name,string phoneNumber){
        if(tree==NULL){
            tree = new Contact;
            tree->name = name;
            tree->phoneNumber = phoneNumber;
            tree->left = NULL;
            tree->right = NULL;
        }
        else if((tree->name>='A'&&tree->name<='Z')||(tree->name>='a'&&tree->name<='z')||(tree->phoneNumber>='0'&&tree->phoneNumber<='9')){
            if((name<tree->name)||(phoneNumber<tree->phoneNumber)){
                insertContact(tree->left,name,phoneNumber);
            }
            else{
                insertContact(tree->right,name,phoneNumber);
            }

        }

    }

    void printInOrder(Contact *tree){
        if(tree==NULL){
            return;
        }
        printInOrder(tree->left);
        cout<<tree->data;
        printInOrder(tree->right);
    }
    bool findContact(Contact *tree, string name){
            if(tree==NULL){
                return false;
            }

            if(tree->name == name){
                return true;
            }
            else if(name < tree->name){
                return findContact(tree->left,name);
            }
            else{
                return findContact(tree->right,name);
            }
    }
    bool searchContact(Contact *tree, string phoneNumber){
            if(tree==NULL){
                return false;
            }

            if(tree->phoneNumber == phoneNumber){
                return true;
            }
            else if(phoneNumber < tree->phoneNumber){
                return findContact(tree->left,phoneNumber);
            }
            else{
                return findContact(tree->right,phoneNumber);
            }
    }
    void deleteContact(Contact *&tree, string name, string phoneNumber){
            if(tree == NULL){
                return;
            }
            if((tree->name == name)||(tree->phoneNumber == phoneNumber)){
                if(tree->left == NULL && tree->right == NULL){
                    delete tree;
                    tree = NULL;
                }
                else if(tree->left != NULL){
                    string maxLeftContact = findMaxContact(tree->left);
                    tree->phoneNumber = maxLeftContact;
                    deleteContact(tree->left,name,maxLeftContact);
                }
                else{
                    string minRightContact = findMinContact(tree->right);
                    tree->phoneNumber = minRightContact;
                    deleteContact(tree->right,name,minRightContact);
                }
            }
            else if(tree->phoneNumber < phoneNumber){
                deleteContact(tree->right,name,phoneNumber);
            }
            else{
                deleteContact(tree->left,name,phoneNumber);
            }
    }

    void makeEmpty(Contact *&tree){
            if(tree == NULL){
                return;
            }
            makeEmpty(tree->left);
            makeEmpty(tree->right);
            delete tree;
            tree = NULL;
    }
public:
    void insertContact(string name,string phoneNumber){
        insertContact(root,name,phoneNumber);
    }
    void printInOrder(){
        printInOrder(root);
    }
    bool findContact(string name){
        return findContact(root,name);
    }
    bool searchContact(string phoneNumber){
        return searchContact(root,phoneNumber);
    }
    void deleteContact(string name,string phoneNumber){
        deleteContact(root,name,phoneNumber);
    }
    void makeEmpty(){
        makeEmpty(root);
    }
    bool isEmpty(){
        if(root == NULL){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    cout<<"********"<<endl;
    cout<<"* CONTACT BOOK *"<<endl;
    cout<<"********"<<endl;

    cout<<"------ Menu --------"<<endl;
    cout<<"1. View all contacts"<<endl;
    cout<<"2. Add new contact"<<endl;
    cout<<"3. Search a contact by name"<<endl;
    cout<<"4. Search a contact by phone number"<<endl;
    cout<<"5. Delete a contact"<<endl;
    cout<<"6. Delete all contacts"<<endl;
    cout<<"7. Exit program"<<endl;

    cout<<"--------------------"<<endl;
    int n;
    cout<<"Select an option (1-7): ";
    cin>>n;
    cout<<"--------------------"<<endl;
    ContactBook B;
    switch(n){
        case 1: cout<<"* View Contacts *"<<endl;
                if(B.isEmpty()){
                    cout<<"Contact book is empty."<<endl;
                }
                else{
                    cout<<"Showing contacts:"<<endl;
                    B.printInOrder();
                    cout<<endl;
                }
                break;
        case 2: string naam,phone;
                cout<<"* Add New Contact *"<<endl;
                cout<<"> Enter name: ";
                getline(cin,naam);
                cout<<endl;
                cin.ignore();
                cout<<"> Enter phone number: ";
                getline(cin,phone);
                cout<<endl;
                cin.ignore();
                B.insertContact(naam,phone);
                cout<<"Contact added successfully."<<endl;
                break;
        case 3: cout<<"* Search Contact By Name *"<<endl;
                string nam;
                cout<<"> Enter name: ";
                getline(cin,nam);
                cout<<endl;
                cin.ignore();
                B.findContact(nam);
                if(B.findContact(nam)==true){
                    cout<<"Matches found:"<<endl;
                    B.printInOrder();
                    cout<<endl;
                }
                else{
                    cout<<"Error: This contact does not exist."<<endl;
                }
                break;
        case 4: cout<<"* Search Contact By Phone Number *"<<endl;
                string p;
                cout<<"> Enter phone number: ";
                getline(cin,p);
                cout<<endl;
                cin.ignore();
                B.findContact(p);
                if(B.findContact(p)==true){
                    cout<<"Matches found:"<<endl;
                    B.printInOrder();
                    cout<<endl;
                }
                else{
                    cout<<"Error: This contact does not exist."<<endl;
                }
                break;
        case 5: cout<<"* Delete Contact *"<<endl;
                string number;
                cout<<"> Enter phone number: ";
                getline(cin,number);
                cout<<endl;
                cin.ignore();
                B.findContact(number);
                if(B.findContact(number)==true){
                    cout<<"Contact found:"<<endl;
                    B.printInOrder();
                    cout<<endl;
                }
                else{
                    cout<<"Error: This contact does not exist."<<endl;
                }
                char ch;
                cout<<"> Delete this contact? Enter y for yes, n for no: ";
                cin>>ch;
                if(ch=='y'){
                    B.deleteContact(number);
                    cout<<"Contact deleted successfully."<<endl;
                }
                else if(ch=='n'){
                    cout<<"Contact not deleted."<<endl;
                }
                break;
        case 6: cout<<"* Delete All Contacts *"<<endl;
                char c;
                cout<<"> Are you sure? Enter y for yes, n for no: ";
                cin>>c;
                if(c=='y'){
                    B.makeEmpty();
                    cout<<"All contacts deleted."<<endl;
                }
                else if(c=='n'){
                    cout<<"Contacts not deleted."<<endl;
                }
                break;
        case 7: char letter;
                cout<<"> Are you sure? Enter y for yes, n for no: ";
                cin>>letter;
                if(letter=='y'){
                    cout<<"* Thank you for using Contact Book *"<<endl;
                    return 0;
                }
                else if(letter=='n'){

                }
                break;
    }
}