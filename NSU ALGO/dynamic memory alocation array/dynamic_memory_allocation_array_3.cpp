#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;

int* createArray(int length){
    int* A = new int[length];
    for(int i=0; i<length; i++){
        A[i] = rand()%10;
    }
    return A;
}

int main(){
    // Watch the memory used by this program
    // in the task manager (in Windows)
    cout << "*Watch memory used by this program while running it." << endl << endl;
    cout << "Before creating the array.." << endl;
    getch();
    int* A = createArray(1000000);
    cout << "After creating the array.." << endl;
    getch();
    delete [] A; // dynamically allocated memory can be freed by using the delete operator
    cout << "After deleting the array.." << endl;
    getch();
}
