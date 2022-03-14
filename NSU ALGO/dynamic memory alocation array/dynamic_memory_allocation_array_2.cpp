#include<iostream>
#include<cstdlib>
using namespace std;

int* createArray(){
    int* A = new int[10];
    for(int i=0; i<10; i++){
        A[i] = rand()%10;
    }
    cout << "Address of array in createArray() function: " << A << endl;
    for(int i=0; i<10; i++){
        cout << A[i] << ",";
    }
    cout << endl;
    return A;
    // Dynamically created array is NOT deleted when a function returns.
    // If you return the address, the array can be used from other functions.
}

int main(){
    int* B = createArray();
    cout << "Address of array in main() function: " << B << endl;

    for(int i=0; i<10; i++){
        cout << B[i] << ",";
    }
}
