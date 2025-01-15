#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    bool flag = 0;
    while (getline(cin, str))
    {
        for (int j = 0; j < str.length(); ++j)
        {
            if (str[j] == '\"' && flag == 0)
            {
                flag = 1;
                cout << "``";
            }
            else if (str[j] == '\"' && flag == 1)
            {
                flag = 0;
                cout << "''";
            }
            else
            {
                cout << str[j];
            }
        }

        cout << endl;
    }

    return 0;
}