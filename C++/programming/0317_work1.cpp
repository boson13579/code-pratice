#include <bits/stdc++.h>
#define ROW 2
#define COL 4
using namespace std;

double average(int arr[ROW][COL]){

	double total = 0;

	for(int i=0 ; i<ROW ; i++)
		for(int t=0  ; t<COL ; t++)
			total += arr[i][t];
	return (total /= ROW*COL);
}

int main () {
	
	int arr[ROW][COL] = {6,7,8,9,10,11,12,13};

	cout << average(arr);
	 
	return 0;
}

