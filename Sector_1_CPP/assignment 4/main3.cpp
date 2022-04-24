#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string name;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    string new1 = firstName(name);
    string new2 = firstName(name);
    cout<<new1<<endl;
    cout<<new2<<endl;

}


string firstName(string name){
    string first_name = "";
    int flag = 0;
    char space=' ';
    cout << name << endl;
    for (int i = 0; i < name.length(); i++)
    {
        first_name=first_name+name[i];
        if (name[i] ==space) 
        {
            break;
        }
    }
    return first_name;
}



string lastName(string name){
    string last_name = "";
    int flag = 0;
    char space=' ';
    cout << name << endl;
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] ==space) 
        {
            flag=1;
            continue;
        }
        if(flag==1){
            last_name=last_name+name[i];
        }
    }
    return last_name;
}