#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left = NULL;
    node *right = NULL;
};

queue<node *> q;

void pre(node *a) {
    cout << a->data << " ";
    if (a->left) pre(a->left);
    if (a->right) pre(a->right);
}

void in(node *a) {
    if (a->left) in(a->left);
    cout << a->data << " ";
    if (a->right) in(a->right);
}

void post(node *a) {
    if (a->left) post(a->left);
    if (a->right) post(a->right);
    cout << a->data << " ";
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int a;
    cin >> a;

    while (a--) {
        while (!q.empty()) q.pop();

        int m;
        node *root = new node;

        cin >> m >> (root->data);
        q.emplace(root);
        node *now = q.front();
        q.pop();

        for (int i = 0; i < m - 1; i++) {
            while (1) {
                if (now->left == NULL) {
                    node *temp = new node;
                    cin >> temp->data;
                    now->left = temp;
                    q.emplace(temp);
                    break;
                }
                if (now->right == NULL) {
                    node *temp = new node;
                    cin >> temp->data;
                    now->right = temp;
                    q.emplace(temp);
                    break;
                }
                now = q.front();
                q.pop();
            }
        }
        pre(root);
        cout << "\n";
        in(root);
        cout << "\n";
        post(root);
        cout << "\n";
    }

    return 0;
}