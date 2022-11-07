#include <bits/stdc++.h>
using namespace std;

struct node {
    long long int num = 0;
    bool isnum = false;
	bool isNULL = false;
    char op = ' ';
    node *right = NULL;
    node *left = NULL;
};

node *root = new node;
queue<node *> q;
node *addnow = NULL;

void addelement() {
    node *newnode = new node;
    string temp;
    cin >> temp;
    if (temp.size() == 1) {
        if ((int)temp[0] > 47) {
            newnode->num = (int)temp[0] - 48;
            newnode->isnum = true;
        } else
            newnode->op = temp[0];
    }
	else{
		newnode -> isNULL = true;
	}
    while (1) {
        if (addnow == NULL) {
            addnow = q.front();
            q.pop();
        }
        if (addnow->left == NULL){
			addnow -> left = newnode;
			q.emplace(newnode);
			break;
		}
		if(addnow -> right == NULL){
			addnow -> right = newnode;
			q.emplace(newnode);
			break;
		}
		addnow = NULL;
	}	
}

long long int solve(node *now){
	if(now -> isnum)
		return now -> num;
	if(now -> op == '+')
		return solve(now -> left) + solve(now -> right);
	if(now -> op == '-')
		return solve(now -> left) - solve(now -> right);
	if(now -> op == '*')
		return solve(now -> left) * solve(now -> right);
	if(now -> op == '/')
		return solve(now -> left) / solve(now -> right);
	return 0;
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int hight;
    cin >> hight;
    char temp;
    cin >> temp;
    if ((int)temp > 47) {
        root->num = (int)temp - 48;
        root->isnum = true;
    } else
        root->op = temp;
    q.emplace(root);
    for (int i = 0; i < (1 << hight) - 2; i++) {
        addelement();
    }

	cout<<solve(root);

    return 0;
}
