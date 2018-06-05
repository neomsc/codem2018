#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int maxpos = 0;
    int maxhappiness = INT_MIN;
    for(int i = 0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        int happiness = a*m+b*(n-m);
        if(happiness>=maxhappiness)
        {
            maxhappiness = happiness;
            maxpos = i;
        }
    }
    vector<int> buy(k,0);
    buy[maxpos] = n;
    for(int i  =0;i<k-1;i++)
    {
        cout<<buy[i]<<' ';
    }
    cout<<buy[k-1];
    return 0;
}
