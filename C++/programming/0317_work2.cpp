#include <bits/stdc++.h>
#define ROW 1
#define COL 4
using namespace std;

void add(int a[ROW][COL] , int b[ROW][COL] , int c[ROW][COL]){
	for(int i=0 ; i<ROW ; i++)
		for(int t=0 ; t<COL ; t++)
			c[i][t] = a[i][t] + b[i][t];
}

int main () {
	int a[ROW][COL] = {8,9,10,11};
	int b[ROW][COL] = {12,13,14,15};
	int c[ROW][COL];
	add(a,b,c);

	for(int i=0 ; i<ROW ; i++)
		for(int t=0 ; t<COL ; t++)
			cout<<c[i][t]<<" ";
	cout<<"\n";

	return 0;
}

