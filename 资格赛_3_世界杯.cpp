#include <bits/stdc++.h>
using namespace std;

int main()
{
    double p[16][16] = {0};
    for(int i = 0;i<16;i++)
    {
        for(int j  =0;j<16;j++)
        {
            cin>>p[i][j];
        }
    }
    double round[4][16] = {0};
    //round 0
    for(int i = 0;i<16;i++)
    {
        if(i%2) round[0][i] = p[i][i-1];
        else round[0][i] = p[i][i+1];
    }
    //round 1-round3
    int base = 2;
    for(int i = 1;i<4;i++,base*=2)
    {
        for(int j = 0;j<16;j++)
        {
            if(j%(base*2)>=base)
            {
                for(int k = j/(base*2)*(base*2);k<j/(base*2)*(base*2)+base;k++)
                {
                    round[i][j] += round[i-1][j]*round[i-1][k]*p[j][k];
                }
            }
            else
            {
                for(int k = j/(base*2)*(base*2)+base;k<j/(base*2)*(base*2)+base*2;k++)
                {
                    round[i][j] += round[i-1][j]*round[i-1][k]*p[j][k];
                }
            }
        }
    }
    for(int i  =0;i<15;i++) cout<<round[3][i]<<' ';
    cout<<round[3][15];
    return 0;
}
