#include <iostream>
using namespace std;

int main () {
	
	double length = 3000;
	int day = 0;
	
	while (length > 5){
		day++;
		length /= 2;
	}

	cout<<day<<"\n";

	system("pause");
	return 0;
}