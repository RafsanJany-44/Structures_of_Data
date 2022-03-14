#include<iostream>
using namespace std;

struct Contact{
    string name;
    string phoneNumber;
};

int main(){
    Contact c;
    c.name = "Abc";
    c.phoneNumber = "012345";

    cout << "Name: " << c.name << " | Phone number: " << c.phoneNumber << endl;

    Contact* p = &c;
    p->name = "Xyz";
    p->phoneNumber = "010101";

   // (*p).name = "test";
   // (*p).phoneNumber = "012321";

    // Use . with object's name
    cout << "Name: " << c.name << " | Phone number: " << c.phoneNumber << endl;
    // Use -> with object's address
    cout << "Name: " << p->name << " | Phone number: " << p->phoneNumber << endl;
}
