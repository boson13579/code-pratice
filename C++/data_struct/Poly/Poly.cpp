#include <bits/stdc++.h>
using namespace std;

struct node {
    int co, ex;
    node *next;
};

node *add1, *add2;
node *rear;

void print(node *a) {
    if (a->co != 0) {
        cout << a->co << " " << a->ex << " ";
    }
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    add1 = new node;
    int a;
    cin >> a >> (add1->co) >> (add1->ex);
    a--;
    add1->next = NULL;
    rear = add1;
    while (a--) {
        node *temp = new node;
        temp->next = NULL;
        cin >> (temp->co) >> (temp->ex);
        rear->next = temp;
        rear = rear->next;
    }

    add2 = new node;
    cin >> a >> (add2->co) >> (add2->ex);
    a--;
    add2->next = NULL;
    rear = add2;
    while (a--) {
        node *temp = new node;
        temp->next = NULL;
        cin >> (temp->co) >> (temp->ex);
        rear->next = temp;
        rear = rear->next;
    }

    while (!(add1 == NULL and add2 == NULL)) {
        if (add1 != NULL and add2 != NULL) {
            if (add1->ex == add2->ex) {
                add1->co += add2->co;
                print(add1);
                add1 = add1->next;
                add2 = add2->next;
                continue;
            }
            if (add1->ex > add2->ex) {
                print(add1);
                add1 = add1->next;
                continue;
            } else {
                print(add2);
                add2 = add2->next;
                continue;
            }
        }
        if (add1) {
            print(add1);
            add1 = add1->next;
            continue;
        }
        if (add2) {
            print(add2);
            add2 = add2->next;
            continue;
        }
    }

    cout << "\n";
    return 0;
}
