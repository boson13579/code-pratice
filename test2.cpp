#include <bits/stdc++.h>
using namespace std;

struct node {
    int num;
    node *next;
};

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    node *l1 = NULL;
    node *l2 = NULL;
    node *l1rear;
    node *l2rear;
    int a;

    cin >> a;
    while (a--) {
        node *temp;
        temp = new node;
        cin >> (temp->num);
        temp->next = NULL;
        if (l1 != NULL) {
            l1rear->next = temp;
            l1rear = temp;
        } else {
            l1 = temp;
            l1rear = temp;
        }
    }
    cin >> a;
    while (a--) {
        node *temp;
        temp = new node;
        cin >> (temp->num);
        temp->next = NULL;
        if (l2 != NULL) {
            l2rear->next = temp;
            l2rear = temp;
        } else {
            l2 = temp;
            l2rear = temp;
        }
    }

    int index;
    cin >> index;
    int nowi = 0;
    node *now = l1;
    while (nowi != index) {
        now = now->next;
        nowi++;
    }
    l2rear->next = now->next;
    now->next = l2;

    node *middle = NULL;
    node *trail;
    while (l1) {
        trail = middle;
        middle = l1;
        l1 = l1->next;
        middle->next = trail;
    }

        while(middle != NULL{
        cout << middle->num << "-->";
        middle = middle->next;
	}
	cout<<"null\n";
	return 0;
}