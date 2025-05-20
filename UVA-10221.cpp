#include<vector>
#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#define PI acos(-1)
using namespace std;
double s, a = 0;
string unit;
int main() {
    while (cin >> s >> a >> unit) {
        if (unit == "min")  a /= 60.0;
        if (a > 180) a = 360 - a;
        double arc = 2 * PI * (6440 + s) * a / 360.0;
        double chord = (s + 6440) * sin(a * PI / 2 / 180.0) * 2;
        cout << fixed << setprecision(6) << arc << " " << chord << endl;
    }

    return 0;
}