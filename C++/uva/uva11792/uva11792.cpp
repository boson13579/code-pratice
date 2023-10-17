#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int cases;
    cin >> cases;
    while (cases--) {
        vector<vector<int>> go;
        vector<int> importSpot;
        int numSpot, lines;
        cin >> numSpot >> lines;
        int appear[numSpot + 1];
        memset(appear, 0, sizeof(appear));

        for (int i = 0; i < numSpot + 1; i++) {
            vector<int> temp;
            go.emplace_back(temp);
        }

        for (int i = 0; i < lines; i++) {
            int fspot;
            cin >> fspot;
            appear[fspot]++;
            int spot;
            while (cin >> spot and spot != 0) {
                appear[spot]++;
                go[fspot].emplace_back(spot);
                go[spot].emplace_back(fspot);
                fspot = spot;
            }
        }

        for (int i = 1; i < numSpot + 1; i++)
            if (appear[i] >= 2) importSpot.emplace_back(i);

        int mindis = 2147483640;
        int ans;
        sort(importSpot.begin(), importSpot.end());
        for (int i : importSpot) {
            int distance = 0;
            int todis[numSpot + 1];
            bool gone[numSpot + 1];

            memset(todis, 0, sizeof(todis));
            memset(gone, false, sizeof(gone));

            queue<int> near;
            near.emplace(i);

            while (!near.empty()) {
                int now = near.front();
                near.pop();

                for (auto t : go[now]) {
                    if (gone[t])
                        continue;
                    else {
                        todis[t] = todis[now] + 1;
                        gone[t] = true;
                        near.emplace(t);
                    }
                }
            }

            for (auto t : importSpot) distance += todis[t];

            if (distance < mindis) {
                mindis = distance;
                ans = i;
            }
        }

        cout << "Krochanska is in: " << ans << "\n";
    }

    return 0;
}
