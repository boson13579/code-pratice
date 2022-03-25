#include <iostream>
using namespace std;

int find_k(int n){
    
    n-=2;
    if(n > 0)
        if(n%4 > 2)
            return int(n/4+1);
        else
            return int(n/4);
    
    //process negative
    if(n%4 > 2)
        return int(n/4);
    else
        return int(n/4-1);
} 
int main(){

    int test = 19;
    int ans = find_k(test);
    cout<<"find_k("<<test<<") = "<<ans<<"\n";
    system("pause");
}