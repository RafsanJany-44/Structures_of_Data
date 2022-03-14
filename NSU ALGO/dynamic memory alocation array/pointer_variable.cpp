#include<iostream>
using namespace std;

int main(){
    int x = 234;
    cout << "x = " << x << endl;
    cout << "address of x = " << &x << endl;
    cout << endl;
    int* p = &x;
    cout << "p = " << p << endl;
    cout << "address of p = " << &p << endl;
    cout << "value pointed by p = " << *p << endl;
    cout << endl;
    int** q = &x;
    cout << "q = " << q << endl;
    cout << "address of q = " << &q << endl;
    cout << "value pointed by q = " << *q << endl;
    cout << "value pointed by *q = " << **q << endl;
}
