#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter a number : \n";
    cin >> a;
    if (a % 2 == 0)
    {
        cout << a << " is Even\n";
    }
    else
    {
        cout << a << " is Odd\n";
    }


    // using switch stat 
    
    switch (a % 2)
    {
    case 0:
        cout << a << " is Even";
        break;
    default:
        cout << a << " is Odd";
        break;
    }

    return 0;
}
