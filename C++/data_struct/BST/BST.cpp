#include <bits/stdc++.h>
using namespace std;

struct node {
    int val = 0;
    node *left = NULL;
    node *right = NULL;
};

node *root = NULL;
void insert();
void search();
void deleten();
int height(node *now);
void traversal();

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    // ios::sync_with_stdio(0), cin.tie(0);

    string command;
    int a;
    while (cin >> command) {
        if (command == "insert") insert();
        if (command == "search") search();
        if (command == "delete") deleten();
        if (command == "height") cout << height(root) << "\n";
        if (command == "traversal") {
            traversal();
            cout << "\n";
            break;
        }
    }

    return 0;
}
void insert() {
    node *newnode = new node;
    cin >> newnode->val;
    if (root == NULL) {
        root = newnode;
        return;
    }
    node *now = root;
    while (now != NULL) {
        if (newnode->val == now->val) return;
        if (newnode->val > now->val) {
            if (now->right == NULL) {
                now->right = newnode;
                break;
            }
            now = now->right;
        } else {
            if (now->left == NULL) {
                now->left = newnode;
                break;
            }
            now = now->left;
        }
    }
    return;
}

void search() {
    int n;
    cin >> n;
    int count = 1;
    stack<node *> st;

    node *now = root;
    while (now != NULL or !st.empty()) {
        while (now != NULL) {
            st.push(now);
            now = now->left;
        }
        now = st.top();
        st.pop();
        if (count == n) {
            cout << now->val << "\n";
            return;
        }
        count++;
        now = now->right;
    }
}

void deleten() {
    int a;
    cin >> a;
    node *bededele = NULL;
    node *pre = root;
    node *now = root;
    bool right = false;
    while (now != NULL) {
        if (a == now->val) {
            bededele = now;
            break;
        }
        if (a > now->val) {
            pre = now;
            now = now->right;
            right = true;
        } else {
            pre = now;
            now = now->left;
            right = false;
        }
    }
    if (bededele == NULL) {
        cout << "cannot delete\n";
        return;
    }

    if (bededele->left != NULL and bededele->right != NULL) {
        pre = bededele;
        now = bededele->left;
        while (now->right != NULL) {
            pre = now;
            now = now->right;
        }
        bededele->val = now->val;
        if (pre == bededele) {
            pre->left = now->left;
        } else
            pre->right = now->left;
        return;
    }

    if (bededele->left != NULL) {
        if (bededele == root) {
            root = bededele->left;
            return;
        }
        if (right)
            pre->right = bededele->left;
        else
            pre->left = bededele->left;
        // pre->right = bededele -> right;
        return;
    }

    if (bededele->right != NULL) {
        if (bededele == root) {
            root = bededele->right;
            return;
        }
        if (right)
            pre->right = bededele->right;
        else
            pre->left = bededele->right;
        // pre->left = bededele -> left;
        return;
    }

    if (bededele == root) {
        root = NULL;
        return;
    }

    if (right) {
        pre->right = NULL;
        return;
    } else {
        pre->left = NULL;
        return;
    }
}

int height(node *now) {
    if (now == NULL) {
        return 0;
    }
    int l = height(now->left);
    int r = height(now->right);
    return max(l, r) + 1;
}

void traversal() {
    node *now = root;
    if (now == NULL) return;
    queue<node *> q;
    q.push(now);
    while (!q.empty()) {
        now = q.front();
        q.pop();
        cout << now->val << " ";
        if (now->left != NULL) q.push(now->left);
        if (now->right != NULL) q.push(now->right);
    }
}
