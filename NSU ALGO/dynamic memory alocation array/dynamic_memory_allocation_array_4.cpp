#include<iostream>
using namespace std;

int main(){
    cout << "Trying to create a large array non-dynamically.." << endl;
    int A[1000000];
    cout << "Static array was created successfully!" << endl;
//     Why does it crash?
//     Non-dynamically or statically created variable/array are
//     stored in the stack which has limited space. If the array size
//     exceeds the allowed space, the program will crash.

//     Dynamically created variables/array are stored in the heap
//     which has a much larger capacity. See next example.
}
