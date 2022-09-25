#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int case_num;
    cin >> case_num;
    for(int i=1; i<case_num+2; i++){
        string str;
        getline(cin,str);

        for(int j=0; j<str.length(); j++){
            if(str[j] == 'd' or str[j] == 'D')
                cout << "a";
            else if(str[j] == 'm' or str[j] == 'M')
                cout << "b";
            else if(str[j] == 'b' or str[j] == 'B')
                cout << "c";
            else if(str[j] == 'g' or str[j] == 'G')
                cout << "d";
            else if(str[j] == 't' or str[j] == 'T')
                cout << "e";
            else if(str[j] == 'h' or str[j] == 'H')
                cout << "f";
            else if(str[j] == 'j' or str[j] == 'J')
                cout << "g";
            else if(str[j] == 'k' or str[j] == 'K')
                cout << "h";
            else if(str[j] == 'p' or str[j] == 'P')
                cout << "i";
            else if(str[j] == 'l' or str[j] == 'L')
                cout << "j";
            else if(str[j] == ';')
                cout << "k";
            else if(str[j] == '\'')
                cout << "l";
            else if(str[j] == '.')
                cout << "m";
            else if(str[j] == ',')
                cout << "n";
            else if(str[j] == '[')
                cout << "o";
            else if(str[j] == ']')
                cout << "p";
            else if(str[j] == 'e' or str[j] == 'E')
                cout << "q";
            else if(str[j] == 'y' or str[j] == 'Y')
                cout << "r";
            else if(str[j] == 'f' or str[j] == 'F')
                cout << "s";
            else if(str[j] == 'u' or str[j] == 'U')
                cout << "t";
            else if(str[j] == 'o' or str[j] == 'O')
                cout << "u";
            else if(str[j] == 'n' or str[j] == 'N')
                cout << "v";
            else if(str[j] == 'r' or str[j] == 'R')
                cout << "w";
            else if(str[j] == 'v' or str[j] == 'V')
                cout << "x";
            else if(str[j] == 'i' or str[j] == 'I')
                cout << "y";
            else if(str[j] == 'c' or str[j] == 'C')
                cout << "z";
            else
                cout << " ";
        }
        if(i!=1)
            cout << '\n';
    }
    return 0;
}