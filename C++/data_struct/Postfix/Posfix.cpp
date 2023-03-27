#include <bits/stdc++.h>
using namespace std;

string infix, each, temp;
stack<string> mystack;
int number, a;

map<string, int> isp{{"(", 0},  {")", 19}, {"+", 12}, {"-", 12},
                     {"*", 13}, {"/", 13}, {"%", 13}};

map<string, int> icp{{"(", 20}, {")", 19}, {"+", 12}, {"-", 12},
                     {"*", 13}, {"/", 13}, {"%", 13}};

void stackExecute(string mystack);

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> a;
    cin.ignore();
    while (a--) {
        getline(cin, infix);
        stringstream ss(infix);
        while (ss >> each) {
            if(icp.find(each)==icp.end())
				cout<<each<<" ";
			else
				stackExecute(each);
        }
        while (!mystack.empty()) {
            cout << mystack.top() << " ";
            mystack.pop();
        }
        cout << "\n";
    }

    return 0;
}

void stackExecute(string next) {
    if (next == ")") {
        while (mystack.top() != "(") {
            cout << mystack.top() << " ";
            mystack.pop();
        }
		mystack.pop();
    }

    while (!mystack.empty() and isp[mystack.top()] >= icp[next]) {
        cout << mystack.top() << " ";
        mystack.pop();
    }
    if (next != ")") mystack.push(next);
}
