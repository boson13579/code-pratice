#include <iostream>
using namespace std;

int main()
{
    int number, temp;
    cin >> number;

    int count = 0;
    for (int i = 1; i <= number; i++)
    {   
        cout<<i<<"\n";
        // temp = i;
        while (i % 5 == 0)
        {
            count += 1;
            i /= 5;
        }
    }

    cout << count << endl;

    return 0;
}