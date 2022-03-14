#include<iostream>
using namespace std;
int main(){

    int c=10;
    {
        int i=10;
        c=i+c;
        cout <<c<<" "<<i<<endl;
    }
    //cout <<c<<" "<<i<<endl;  --> not valid
}