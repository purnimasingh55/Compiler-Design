#include <iostream>
using namespace std;

int main()
{
    int state = 0;
    char str[20];
    cout << "Enter the string: ";
    cin >> str;
    int i = 0;
    char al;
    while ((al = str[i++]) != '\0')
    {
        switch (state)

        {
        case 0:
            if (al == 'a')
                state = 1;
            else if (al == 'b')
                state = 3;
            else
            {
                cout << "Please give a valid input";
                exit(0);
            }
            break;
        case 1:
            if (al == 'a')
                state = 0;
            else if (al == 'b')
                state = 2;
            else
            {
                cout << "Please give a valid input";
                exit(0);
            }
            break;
        case 2:
            if (al == 'a')
                state = 3;
            else if (al == 'b')
                state = 1;
            else
            {
                cout << "Please give a valid input";
                exit(0);
            }
            break;
        case 3:
            if (al == 'a')
                state = 2;
            else if (al == 'b')
                state = 0;
            else
            {
                cout << "Please give a valid input";
                exit(0);
            }
            break;
        }
        //cout<<state;
   
    }
         if (state == 0)
        {
            cout << "Input is accepted";
        }
        else
        {
            cout << "Input is not accepted";
        }
}
