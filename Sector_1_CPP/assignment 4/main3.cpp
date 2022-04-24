#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string name;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    string new1 = "";
    string new2 = "";
    int flag = 0;
    char space=' ';
    cout << name << endl;
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] ==space) 
        {
            flag = 1;
            continue;
        }
        if (flag == 1)
        {
            new2 = new2 + name[i];
        }
        else
        {
            new1 = new1 + name[i];
        }
    }
    cout<<new1<<endl;
    cout<<new2<<endl;
}