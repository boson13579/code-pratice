#include <bits/stdc++.h>
using namespace std;

struct student {
    int score;
    string name;
};

student arr[1000010];

int a;
int now = 0;

bool cmp(student a, student b) {
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.name < b.name;
}

void qsort(int l, int r) {

    if (l >= r) return;

    student pivot = arr[l];

    int i = l, j = r + 1;

    while (i < j) {
        i++;
        j--;

        while (cmp(pivot, arr[i]) and i < a) i++;
        while (cmp(arr[j], pivot) and j > 0) j--;

        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    cout << "The index of the " << ++now << "-th pivot is " << j << ".\n";
    qsort(l, j - 1);
    qsort(j + 1, r);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> a;
    for (int i = 0; i < a; i++) cin >> arr[i].name >> arr[i].score;

    qsort(0, a - 1);

    for (int i = 0; i < a; i++)
        cout << arr[i].name << " " << arr[i].score << "\n";
    return 0;
}
