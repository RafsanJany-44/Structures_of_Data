#include<iostream>
using namespace std;

int main(){
    int A[5] = {5,3,7,4,1};
    cout << "A[5] = {5,3,7,4,1} " << endl;
    cout << "A = " << A << endl;
    cout << "A[0] = " << A[0] << endl;
    cout << "Address of A[0] = " << &A[0] << endl;
    cout << endl;
    int* p = &A[2];  // it will allocate the adress of A[2] whic value is 7
    cout << p[0] << endl;// it will print the address of the A[2]
    cout << "Value pointed by p = " << *p << endl; 
    p=p+2;
    cout << "After p=p+2" << endl;
    cout << "Value pointed by p = " << *p << endl;
    (*p)++;   // it will increase the value of 1 to 2
    cout << "After (*p)++" << endl;
    cout << "Value pointed by p = " << *p << endl;

}
