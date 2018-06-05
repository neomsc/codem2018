#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int totalmoney = 0;
    double totalmoneysale = 0;
    for(int i = 0;i<n;i++)
    {
        int ai,ok;
        cin>>ai>>ok;
        totalmoney+=ai;
        totalmoneysale+=ai*(ok?0.8:1);
    }
    double result = totalmoneysale;
    for(int i = 0;i<m;i++)
    {
        int bi,ci;
        cin>>bi>>ci;
        if(bi<=totalmoney) result = min(result,double(totalmoney-ci));
    }
    printf("%.2f",result);
    return 0;
}
