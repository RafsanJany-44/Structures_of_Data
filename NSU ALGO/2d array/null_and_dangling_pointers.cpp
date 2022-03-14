#include<iostream>
//#include<conio.h>
using namespace std;

int main(){
    int gar;
    int* A;
    cout << "Address stored in pointer A is " << A << endl;
    cout << "We haven't initialized A, so this is a garbage address! " << endl;
    // where did this address come from?
    // garbage address, just like garbage in an uninitialized variable
    cout << endl;
    A = NULL; // setting address stored in A to NULL
    // A null pointer points to nothing. It does not contain any address.
    cout << "Address in A after setting it to NULL: " << A << endl;
    cout << "A null pointer does not point to any memory address." << endl;
    //getch();
    cin>>gar;

    // Now let's create an array
    cout << endl;
    cout << "Creating an array dynamically.." << endl;
    A = new int[1000000];
    for(int i=0; i<1000000; i++){
        A[i] = rand()%10;
    }
    cout << "Dynamic array was created successfully!" << endl;
    cout << "Address of the array is now stored in A. A = " << A << endl;
    cout << endl;
    //getch();
    cin>>gar;

    cout << "Deleting the array.." << endl;
    delete [] A;
    //A = NULL;
    cout << "Array has been deleted. " << endl;
    cout << "Address stored in A is now " << A << endl;
    cout << endl;
    //getch();
    cin>>gar;
    cout << "If we try to access the array now, the program might crash." << endl;
    cout << "We have deleted the array but the address is still stored in A." << endl;
    cout << "A is pointing to an area in memory that has been freed." << endl;
    cout << "We have no idea what is stored in that address now." << endl;
    cout << endl;
    cout << "This is called a dangling pointer." << endl;
    cout << "NEVER DO THIS!" << endl;
    //getch();
    cin>>gar;
}
