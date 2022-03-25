#include <bits/stdc++.h>
using namespace std;

int sum2(int a){

    if(a == 1)
        return 2;
    return 2*a + sum2(a-1);
    
}

int main(){

    cout<<sum2(50)<<"\n";

    system("pause");
    return 0;
}