#include<iostream>
#include<cstdlib>
using namespace std;

int* createArray(){
    int A[10]; // Statically created array
    for(int i=0; i<10; i++){
        A[i] = rand()%10;
    }
    cout << "Address of array in createArray() function: " << A << endl;
    for(int i=0; i<10; i++){
        cout << A[i] << ",";
    }
    cout << endl;
    return A;
    // Statically created array is deleted when a function returns.
    // Even if you return the address, the array won't be usable.
}

int main(){
    int* p = createArray();
    cout << "Address of array in main() function: " << p << endl;

    // Why does it crash?
    // Null pointer!
    // You cannot access memory pointed by a null pointer.
    // A null pointer points to nothing.
    for(int i=0; i<10; i++){
        cout << p[i] << ",";
    }
}
