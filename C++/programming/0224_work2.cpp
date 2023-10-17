#include <iostream>
using namespace std;

int main () {
	
	int total = 0;
	int i = 0;

	do{
		i++;
		total += i;
	}
	while(total <1000);
	
	cout<<i<<"\n";

	system("pause");
	return 0;
}