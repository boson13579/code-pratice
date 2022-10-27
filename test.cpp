#include <bits/stdc++.h>
using namespace std;

map<string, int> team;
// vector<vector<string>> teams;

struct player {
    string num;
    player *next;
};

player *teamID[1000];
player *q = NULL;
player *qrear = NULL;

int qq = 1;

int main() {
    int team_num;
    while (cin >> team_num and team_num != 0) {
        cout<<"Scenario #"<<qq++;
        q = NULL;
        qrear = NULL;
        for (int i = 0; i < team_num; i++) {
            teamID[i] = NULL;
            int n;
            cin >> n;
            while (n--) {
                string temp;
                cin >> temp;
                team.emplace(temp, i);
            }
        }
        string tempstr;
        cin.ignore();
        while (getline(cin, tempstr) and tempstr != "STOP") {
            if (tempstr[0] == 'E') {
                stringstream ss(tempstr);
                string trash, num;
                ss >> trash >> num;
                player *temp = new player;
                temp->num = num;
                temp->next = NULL;
                if (teamID[team[num]] != NULL) {
                    temp->next = teamID[team[num]]->next;
                    teamID[team[num]]->next = temp;
                    teamID[team[num]] = temp;
                } else {
                    if (q != NULL) {
                        qrear->next = temp;
                        qrear = temp;
                        teamID[team[num]] = temp;
                    } else {
                        q = temp;
                        qrear = temp;
                        teamID[team[num]] = temp;
                    }
                }
            } else {
                cout << q->num << " ";
                player *temp = q;
                q = q->next;
                free(temp);
            }
        }
    }

    return 0;
}
