#include <bits/stdc++.h>
using namespace std;

int ma , na , mb , nb;

vector<vector<int>> matrixA , matrixB;

int main () {
	freopen("test.in", "r", stdin);
	freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cout<<"Input first matrix size : ";
	cin>>ma>>na;
	cout<<"Input second matrix size : ";
	cin>>mb>>nb;
	if(na != mb)
		cout<<"Can't be multiplied\n";
	else{
		cout<<"Input first matrix\n";
		for(int i=0 ; i<ma ; i++){
			vector<int> temp ;
			matrixA.emplace_back(temp);
			for(int t=0 ,tempint; t<na ; t++){
				cin>>tempint;
				matrixA[i].emplace_back(tempint);
			}
		}
		cout<<"Input second matrix\n";
		for(int i=0 ; i<mb ; i++){
			vector<int> temp;
			matrixB.emplace_back(temp);
			for(int t=0 ,tempint; t<nb ; t++){
				cin>>tempint;
				matrixB[i].emplace_back(tempint);
			}
		}
		cout<<"Multiplication\n";
		for(int i=0 ; i<ma ; i++){
			for(int t=0 ; t<nb ; t++){
				int temp = 0;
				for(int k=0 ; k<na ; k++){
					temp += matrixA[i][k]*matrixB[k][t];
				}
				cout<<temp<<" ";
			}
			cout<<"\n";
		}
	}

	return 0;
}

