#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> values;

    int num = 5000; // a random number != 0
    int sum = 0;

    while (num != 0)
    {
        cin>>num;
        values.push_back(num);

        sum += num;
    }

    sort(values.begin(), values.end());

    int maxi = values[values.size() -1];
    int mini = values[1];

    int average = sum /( values.size() -1);

    cout<<"Minimum Value "<<mini<<"\n";
    cout<<"Maximum Value "<<maxi<<"\n";
    cout<<"Range "<<maxi - mini<<endl;
    cout<<"Average "<<average<<endl;
    
}