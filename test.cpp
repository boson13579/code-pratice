#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#define _for(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

struct node {
    int v;
    node *l = nullptr;
    node *r = nullptr;
};

node *root = nullptr;

node *create_node(int v, node *l = nullptr, node *r = nullptr) {
    node *temp = (node *)malloc(sizeof(node));
    temp->v = v;
    temp->r = r;
    temp->l = l;
    return temp;
}

void insert_node(int v, node **t = &root) {
    if (!(*t))
        *t = create_node(v);
    else if (v < (*t)->v)
        insert_node(v, &((*t)->l));
    else
        insert_node(v, &((*t)->r));
}

void delete_node(int v, node **tt = &root) {
    node *t = *tt;
    if (!t)
        cout << "cannot delete" << endl;
    else if (t->v == v) {
        if (t->l && t->r) {
            node **m = &((*tt)->l);
            while ((*m)->r) m = &((*m)->r);
            t->v = (*m)->v;
            t = *m;
            *m = (*m)->l;
        } else if (t->l)
            *tt = t->l;
        else if (t->r)
            *tt = t->r;
        else
            *tt = nullptr;
        free(t);
    } else if (v < t->v)
        delete_node(v, &((*tt)->l));
    else
        delete_node(v, &((*tt)->r));
}

int get_height(node *t = root) {
    if (!t) return 0;
    return 1 + max(get_height(t->l), get_height(t->r));
}

int _search_i(node *t, int v, int *n, int *m) {
    if (!t) return 0;
    if (_search_i(t->l, v, n, m)) return 1;
    if (++(*n) == v) {
        *m = t->v;
        return 1;
    }
    if (_search_i(t->r, v, n, m)) return 1;
    return 0;
}

int search_i(int v) {
    int n = 0, m = 0;
    _search_i(root, v, &n, &m);
    return m;
}

void traversal() {
    queue<node *> q;
    if (root) q.push(root);
    while (!q.empty()) {
        node *t = q.front();
        q.pop();
        cout << (t == root ? "" : " ") << t->v;
        if (t->l) q.push(t->l);
        if (t->r) q.push(t->r);
    }
    cout << endl;
}

int main() {
    string s;
    while (cin >> s) {
        int x;
        if (s == "insert") {
            cin >> x;
            insert_node(x);
        } else if (s == "delete") {
            cin >> x;
            delete_node(x);
        } else if (s == "search") {
            cin >> x;
            cout << search_i(x) << endl;
        } else if (s == "height")
            cout << get_height() << endl;
        else if (s == "traversal")
            traversal();
    }
}
