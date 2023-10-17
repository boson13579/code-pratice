#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> matrix;

int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	//ios::sync_with_stdio(0), cin.tie(0);
	
	//cout<<"Input Size:";
	int n;
	while(cin>>n && n!= -1){

		//init
		matrix.clear();

		// Input
		for(int i=0 ; i<n ; i++){
			vector<int> temp;
			matrix.emplace_back(temp);
			for(int t=0 ,temp; t<n ; t++){
				cin>>temp;
				matrix[i].emplace_back(temp);
			}
		}
		
		bool ans = true;
		
		//Solve
		for(int i=0 ; i<n ; i++){
			for(int t=0 ; t<n ; t++){
				if(matrix[i][t] != matrix[n-1-i][n-1-t])
					ans = false;
					break;
				}
			if(!ans)
				break;
		}

		//print answer
		if(ans)
			cout<<"Symmetric!\n";
		else
			cout<<"Non-Symmetric!\n";

		//cout<<"Input Size:";
	}
	
	return 0;
}

