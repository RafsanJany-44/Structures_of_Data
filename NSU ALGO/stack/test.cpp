#include <iostream>
using namespace std;

int main()
{
    char st[100];
    cin >> st;
    int len = strlen(st);
    for (int i=0;i<len;i++){
        cout << st[i];
    }
}