#include <iostream>
#include <string>

using namespace std;

int main() {
    string week;
    cin >> week;

    int days;

    if (week == "Monday") {
        days = 5;
    } else if (week == "Tuesday") {
        days = 4;
    } else if (week == "Wednesday") {
        days = 3;
    } else if (week == "Thursday") {
        days = 2;
    } else if (week == "Friday") {
        days = 1;
    } else { 
        days = 0; 
    }
 
    cout << days << endl;

    return 0;
}

