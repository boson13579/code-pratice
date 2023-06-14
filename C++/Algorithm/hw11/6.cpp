#include <bits/stdc++.h>
using namespace std;

int dis[100][100][100];
int main() {

    freopen("6.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    // vector<vector<int>> dis(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> parent(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n;i++) {
        for (int t = 0;t <= n; t++) {
            for (int k = 0; k <= n; k++) {
                dis[i][t][k] = INT_MAX;
            }
            dis[i][t][t] = 0;
        }
        
    }

    // init self to be 0
    for (int i = 1; i <= n; i++) {
        dis[0][i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[0][u][v] = w;
        // parent[u][v] = u;
    }

    // auto print = [&]() {
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= n; j++) {
    //             if (dis[k-1][i][j] == INT_MAX)
    //                 cout << "inf ";
    //             else
    //                 cout << setw(3) << dis[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // };

    // cout << "Init" << endl;
    // print();
    // cout << "------------------------\n\n";
    //floyd-warshall
    // for (int q = 1; q < 3;q++)
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[k][i][j] = dis[k-1][i][j];
                if (dis[k - 1][i][k] != INT_MAX and dis[k - 1][k][j] != INT_MAX) {
                    if (dis[k][i][j] > dis[k - 1][i][k] + dis[k - 1][k][j]) {
                        dis[k][i][j] = min(dis[k][i][j], dis[k - 1][i][k] + dis[k - 1][k][j]);
                        // parent[k][i][j] = k;
                    }

                }
                
            }
        }
        // print();
        // print parent
        // cout << "\n";
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << parent[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "\n";
    }


    for (int i = 1; i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cout << dis[n][i][j] << " ";
        }
        cout << endl;
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