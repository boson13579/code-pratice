#include <bits/stdc++.h>
using namespace std;

void square(int *arr){
	for(int i=0 ; i<5 ; i++)
		arr[i] = arr[i]*arr[i];
}

int main () {
	
	int arr[5] = {31,17,33,22,16}; 

	square(arr);

	for(int i=0 ; i<5 ; i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	
	system("pause");
	return 0;

}

