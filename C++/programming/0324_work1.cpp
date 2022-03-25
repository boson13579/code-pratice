#include <bits/stdc++.h>
using namespace std;


int main () {
	
	int arr[5] = {31,17,33,22,16};

	auto *ptr = &arr[0];
	for(auto i=0 ; i<5  ; i++){
		cout<<*ptr+10<<" ";
		ptr++;
	}

	cout<<"\n";

	
	system("pause");
	return 0;
}

