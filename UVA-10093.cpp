#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    string sInput;
    int iDigit;
    int isInputLenth;
    int iSum;
    int i;
    int iMax;
    bool bConfirm;

    while (cin >> sInput)
    {
        isInputLenth = sInput.length();
        iSum = 0;
        iMax = 0;
        iDigit = 0;
        bConfirm = 0;
        for (int i = 0; i < isInputLenth; ++i)
        {
            if (isdigit(sInput[i]))
            {
                iDigit = sInput[i] - '0';
            }
            else if (isupper(sInput[i]))
            {
                iDigit = sInput[i] - 'A' + 10;
            }
            else if (islower(sInput[i]))
            {
                iDigit = sInput[i] - 'a' + 36;
            }
            iSum += iDigit;
            iMax = max(iMax, iDigit);
        }
        for (int i = iMax + 1; i <= 62 && !bConfirm && iSum != 0; i++)
        {
            if (iSum % (i - 1) == 0)
            {
                cout << i << endl;
                bConfirm = 1;
                break;
            }
        }
        if (!bConfirm && iSum != 0)
        {
            cout << "such number is impossible!" << endl;
        }
        else if (!bConfirm)
        {
            cout << "2" << endl;
        }
    }

    return 0;
}
