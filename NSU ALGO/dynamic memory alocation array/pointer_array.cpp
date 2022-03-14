#include<iostream>
using namespace std;

int main(){
    int A[5] = {5,3,7,4,1};
    cout << "A[5] = {5,3,7,4,1} " << endl;
    cout << "A = " << A << endl;
    cout << "A[0] = " << A[0] << endl;
    cout << "Address of A[0] = " << &A[0] << endl;
    cout << endl;
    int* p = &A[2];
    cout << p[0] << endl;
    cout << "Value pointed by p = " << *p << endl;
    p=p+2;
    cout << "After p=p+2" << endl;
    cout << "Value pointed by p = " << *p << endl;
    (*p)++;
    cout << "After (*p)++" << endl;
    cout << "Value pointed by p = " << *p << endl;

}
