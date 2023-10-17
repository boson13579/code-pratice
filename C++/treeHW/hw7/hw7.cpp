#include <bits/stdc++.h>
using namespace std;

vector <string> arr;
string temp ,a,b;
bool ist = true;
bool is_error = false;
int main () {
	freopen("test.in", "r", stdin);
	freopen("test.out","w", stdout);
	//ios::sync_with_stdio(0), cin.tie(0);
	while(cin>>b){
		//cin.ignore();
		temp = "";
		if(b.find("[2021") != string::npos and !arr.empty() and is_error){
			cout<<arr[0]<<"\n\n";
			arr.clear();
			ist = true;
		}
		if(b.find("[2021") != string::npos and !arr.empty() and !is_error){
			arr.clear();
			ist = true;
		}
		is_error = false;
		while(temp.find("[2021") == string::npos){
			getline(cin,temp);
			if(temp == "")
				break;
			arr.emplace_back(temp);
			if(!is_error && (temp.find("error") != string::npos or temp.find("Failed") != string::npos))
				is_error = true;
		}
		if(arr[0].find("error") != string::npos or arr[0].find("Failed")!= string::npos)
			is_error = true;

		if(is_error and ist){
			a = *(arr.end()-1);
			arr.pop_back();
			cout<<b;
			for(int i=0 ; i<arr.size() ; i++)
			cout<<arr[i]<<"\n";
			cout<<"\n";
			ist = false;
			is_error = false;
		}
		else if(is_error){
			a = *(arr.end()-1);
			arr.pop_back();
			cout<<arr[0]<<"\n    "<<b;
			for(int i=1 ; i<arr.size() ; i++)
				cout<<arr[i]<<"\n";
			cout<<"\n";
			ist = false;
			is_error = false;
		}
		arr.clear();
		arr.emplace_back(a);
	}
	
	return 0;
}

