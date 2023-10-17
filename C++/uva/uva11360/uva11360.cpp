#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> row(vector<vector<int>> &arr,int n,int a,int b) {
    vector<vector<int>> temp = arr;
    for (int i = 0; i < n; i++) {
        temp[a][i] = arr[b][i];
        temp[b][i] = arr[a][i];
    }
    return temp;
}
vector<vector<int>> col(vector<vector<int>> &arr,int n,int a,int b) {
    vector<vector<int>> temp = arr;
    for (int i = 0; i < n; i++) {
        temp[i][a] = arr[i][b];
        temp[i][b] = arr[i][a];
    }
    return temp;
}
vector<vector<int>> inc(vector<vector<int>> &arr,int n) {
    vector<vector<int>> temp = arr;
    for (int i=0 ; i<n ; i++) {
        for (int t=0 ; t<n ; t++) {
            temp[i][t]++;
            if (temp[i][t] == 10) temp[i][t] = 0;
        }
    }
    return temp;
}
vector<vector<int>> dect(vector<vector<int>> &arr,int n) {
    vector<vector<int>> temp = arr;
    for (int i=0 ; i<n ; i++) {
        for (int t=0 ; t<n ; t++) {
            temp[i][t]--;
            if (temp[i][t] == -1) temp[i][t] = 9;
        }
    }
    return temp;
}
vector<vector<int>> trans(vector<vector<int>> &arr,int n) {
    vector<vector<int>> temp = arr;
    for (int i = 0; i < n; i++) {
        for (int t = 0; t < n; t++) {
            temp[i][t] = arr[t][i];
        }
    }
    return temp;
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int t,cases = 1;
    cin >> t;
    while (t--) {
        int b;
        cin >> b;
        vector<vector<int>> array;
        for (int i = 0; i < b; i++) {
            vector<int> temp;
			string tempss;
            cin >> tempss;
            for (int t = 0; t < b; t++) {
                temp.emplace_back(int(tempss[t])-48);
            }
            array.emplace_back(temp);
        }
        int c;
        cin >> c;
        for (int i = 0; i < c; i++) {
            string qq;
            cin >> qq;
            if (qq == "row") {
                int c1, c2;
                cin >> c1 >> c2;
                array = row(array, b, c1-1, c2-1);
            }

            if (qq == "col") {
                int c1, c2;
                cin >> c1 >> c2;
                array = col(array, b, c1-1, c2-1);
            }
            if (qq == "inc") array = inc(array, b);
            if (qq == "dec") array = dect(array, b);
            if (qq == "transpose") array = trans(array, b);
        }
		cout<<"Case #"<<cases++<<"\n";
        for (auto i : array) {
            for (auto t : i) {
                cout << t << "";
            }
            cout << "\n";
        }
		cout<<"\n";
    }

    return 0;
}
