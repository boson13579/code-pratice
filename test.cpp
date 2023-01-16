#include <bits/stdc++.h>
using namespace std;
int data[30][30];
bool isFull(int a, int b, int c,int d){
	for(int i=a;i<=c;i++){
		for(int j=b;j<=d;j++){
			if(!data[i][j]) return false;
		}
	}
	return true;
}
int main() {
	int a;
	cout<<a<<endl;
	return 0;
}