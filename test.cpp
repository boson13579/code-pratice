#include <iostream>
using namespace std;

int main () {

	int arr[3] = {1,3,4};
	auto *ptr = arr;
	auto *qq = &arr[0];

	cout<<*ptr<<" "<<*qq<<"\n";
	return 0;
}

