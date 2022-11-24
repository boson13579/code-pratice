#include <bits/stdc++.h>
using namespace std;

int which_date(int year, int month, int day);
void display_calender(int year, int month, int day);
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    switch (which_date(a, b, c)) {
        case 0:
            cout << "Sunday" << endl;
            break;
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
    }
    cout << endl;
    display_calender(a, b, c);
    cout << endl;

    return 0;
}
int which_date(int year, int month, int day) {
    if (month == 1 or month == 2) {
        year--;
        month += 12;
    }
    return (year % 100 + (year % 100) / 4 + (year / 400) - (year / 100) * 2 +
            (26 * (month + 1) / 10) + day - 1) %
           7;
}
void display_calender(int year, int month, int day) {
    for (int i = 0; i < 7; i++) cout << "    " << i;
    cout << endl;
    for (int i = 0; i < 38; i++) cout << "=";
    cout << endl;
    int total_day = days[month];
    if (month == 2 and (year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)))
        total_day++;
    for (int i = 0; i < (which_date(year, month, 1)) * 5; i++) cout << " ";
    for (int i = 1; i <= total_day; i++) {
        if (i < 10 and i != day)
            cout << "    " << i;
        else if (i < 10 and i == day)
            cout << "   *" << i;
        else if (i >= 10 and i != day)
            cout << "   " << i;
        else
            cout << "  *" << i;
        if (which_date(year, month, i) == 6 and i != total_day) cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 38; i++) cout << "=";
}
