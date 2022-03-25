/*
*Assignment 9-1
*Name: 陳柏燊
*Student Number: 110502529
*Course 2021-CE1003-A
*/
#include <bits/stdc++.h>
using namespace std;

int A[6][6];
int B[6][6];
int am , an , bm , bn;

int main () {
	//ios::sync_with_stdio(0), cin.tie(0);
	cout<<"Matrix A size = ";cin>>am>>an;
	cout<<"Matrix B size = ";cin>>bm>>bn;
	if(an != bm)
		cout<<"Can't be multiplied\n";
	else{

		cout<<"Matrix A\n";
		for(int i=0 ; i<am ; i++){
			for(int t=0 ; t<an ; t++){
				cin>>A[i][t];
			}
		}

		cout<<"Matrix B\n";
		for(int i=0 ; i<bm ; i++){
			for(int t=0 ; t<bn ; t++){
				cin>>B[i][t];
			}
		}

		cout<<"Multiplication\n";
		for(int i=0 ; i<am ; i++){
			for(int t=0 ; t<bn ; t++){
				int temp = 0;
				for(int k=0 ; k<an ; k++){
					temp += A[i][k]*B[k][t];
				}
				cout<<temp<<" ";
			}
			cout<<"\n";
		}
	}

	return 0;
}

