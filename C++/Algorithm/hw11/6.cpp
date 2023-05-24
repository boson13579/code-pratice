#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("6.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> parent(n + 1, vector<int>(n + 1, 0));

    // init self to be 0
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = w;
        // parent[u][v] = u;
    }

    auto print = [&]() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][j] == INT_MAX)
                    cout << "inf ";
                else
                    cout << setw(3) << dis[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    };

    cout << "Init" << endl;
    print();
    cout << "------------------------\n\n";
    //floyd-warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] != INT_MAX and dis[k][j] != INT_MAX) {
                    if(dis[i][j] > dis[i][k] + dis[k][j]) {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                        parent[i][j] = k;
                    }
                    
                }
            }
        }
        print();
        // print parent
        cout << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << parent[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\n";
    }

    return 0;
}

/*
6 10
1 5 -1
2 1 1
2 4 2
3 2 2
3 6 -8
4 1 -4
4 5 3
5 2 7
6 2 5
6 3 10
*/