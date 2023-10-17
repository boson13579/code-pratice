#include <bits/stdc++.h>
using namespace std;

struct dot {
    int x = 0, y = 0, dir = 0;

    dot(int a, int b, int c);
    dot();
};

struct Mystack {
    int top = -1;
    dot *arr;
    int maxSize;

    Mystack(int maxSize);
    void push(dot x);
    void pop();
    bool empty() { return (this->top == -1); }
    dot topElement() { return this->arr[this->top]; }
};

bool maze[100][100];

Mystack mystack(10000);

pair<int, int> dir[4] = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0),
                         make_pair(0, -1)};

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++)
        for (int t = 0; t < b; t++) cin >> maze[i][t];

    dot temp = dot(0, 0, 0);
    mystack.push(temp);
    maze[0][0] = true;

    bool findpath = (a == b and a == 1);

    while (!mystack.empty() and !findpath) {
        dot now = mystack.topElement();

        bool havenext = false;
        for (int i = 0; i < 4 and !havenext; i++) {
            dot next = dot(now.x + dir[i].first, now.y + dir[i].second, i);
            bool outborder =
                (next.x == a or next.x < 0 or next.y < 0 or next.y == b);

            if (next.x == a - 1 and next.y == b - 1) findpath = true;

            if (!maze[next.x][next.y] and !outborder) {
                havenext = true;
                mystack.push(next);
                maze[next.x][next.y] = true;
            }
        }
        if (!havenext) mystack.pop();
    }

    if (!findpath)
        cout << "Can't reach the exit!\n";
    else {
        dot *ansarr = mystack.arr;
        for (int i = 0; i <= mystack.top; i++) {
            if (i != mystack.top)
                cout << "(" << ansarr[i].x << "," << ansarr[i].y << ") ";
            else
                cout << "(" << ansarr[i].x << "," << ansarr[i].y << ")\n";
        }
    }

    return 0;
}

dot ::dot() {
    this->x = 0;
    this->y = 0;
    this->dir = 0;
}

dot ::dot(int a, int b, int c) {
    this->x = a;
    this->y = b;
    this->dir = c;
}
Mystack ::Mystack(int maxSize) {
    this->arr = new dot[maxSize];
    this->maxSize = maxSize;
}
void Mystack ::push(dot x) {
    if (this->top == this->maxSize - 1) {
        cout << "Stack is overflow\n";
        return;
    }
    this->top++;
    this->arr[top] = x;
}
void Mystack ::pop() {
    if (this->top == -1) {
        cout << "Stack is empty\n";
        return;
    }
    this->top--;
}
