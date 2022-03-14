#include<iostream>
//#include<conio.h>
using namespace std;

int main(){
    int gar;
    cout << "*Watch memory used by this program when running it." << endl << endl;
    int* A;
    cout << "Array has not been created yet.." << endl;
    //getch();
    cin>>gar;
    cout << "Creating an array dynamically.." << endl;
    A = new int[1000000]; // Storing the address of this array in A
    for(int i=0; i<1000000; i++){
        A[i] = rand()%10;
    }
    cout << "Dynamic array was created successfully!" << endl;
    cout << endl;
    //getch();
    cin>>gar;
    cout << "Address of newly created array is, A = " << A << endl;
    cout << "Now storing the address of an integer variable x in A.." << endl;
    int x = 5;
    A = &x;
    //getch();
    cin >> gar;
    cout << endl;
    cout << "Address stored in A is now " << A << endl;
    cout << "We have lost the address of the array. " << endl;
    cout << "Now we cannot access or delete the array anymore." << endl;
    cout << "The array will remain in the memory until the program exits." << endl;
    cout << endl;
    cout << "This is a memory leak." << endl;
    cout << "NEVER LET THIS HAPPEN!";
   // getch();
    cin>>gar;
}
