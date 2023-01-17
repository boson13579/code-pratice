#include <iostream>
using namespace std;

int main() {
    long long input;
    cin >> input;
    if (input * (input + 1) / 2 % 2 != 0)
        cout << "NO\n";
    else {
        if (input % 4 == 0) {
            cout << "YES " << input / 2 << " ";
            for (long long i = 1; i < input / 2; i += 2) cout << i << " ";
            for (long long i = input / 2 + 2; i < input + 1; i += 2)
                cout << i << " ";
            cout << input / 2 << " ";
            for (long long i = 2; i < input / 2 + 1; i += 2) cout << i << " ";
            for (long long i = input / 2 + 1; i < input + 1; i += 2)
                cout << i << " ";
            cout << "\n";
        } else if (input % 4 == 1 || input % 4 == 2)
            cout << "NO\n";
        else if (input % 4 == 3) {
            cout << "YES " << (input + 1) / 2 << " ";
            for (long long i = 1; i < (input + 1) / 2; i += 2) cout << i << " ";
            for (long long i = (input + 1) / 2; i < input + 1; i += 2)
                cout << i << " ";
            cout << (input - 1) / 2 << " ";
            for (long long i = 2; i < (input - 1) / 2; i += 2) cout << i << " ";
            for (long long i = (input + 1) / 2 + 1; i < input + 1; i += 2)
                cout << i << " ";
            cout << "\n";
        }
    }
    return 0;
}