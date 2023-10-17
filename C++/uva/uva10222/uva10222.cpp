#include <bits/stdc++.h>
using namespace std;

int main() {
     freopen("test.in", "r", stdin);
     freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    string str = "1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";

    string ss;
    int a;
    cin >> a;cin.ignore();
    while (a--) {
        getline(cin, ss);
        for (int i = 0; i < ss.size(); i++) {
            char q = ss[i];
            if (int(q) < 91 and int(q) > 64) q = char(int(q) + 32);
            if (q == ' ')
                cout << " ";
            else
                cout << str[str.find(q) - 2];
        }
		cout<<"\n";
    }

    return 0;
}
