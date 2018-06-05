//有错，待改
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,double> a,pair<int,double> b)
{
    return a.second>b.second;
}
int main()
{
    int n,m,k,C;
    cin>>n>>m>>k>>C;
    vector<double> w(m,0);
    int wsum = 0;
    for(int i  =0;i<m;i++)
    {
        int wi;
        cin>>wi;
        wsum+=wi;
        w[i] = wi;
    }
    for(int i  =0;i<m;i++)
    {
        w[i]/=wsum;
    }
    vector<int> temp(m,0);
    vector<vector<int> > score(n,temp);
    vector<int> maxscore(m,0);
    int posi,posj;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>score[i][j];
            if(score[i][j]==-1)
            {
                posi = i;
                posj = j;
                score[i][j] = 0;
            }
            maxscore[j] = max(maxscore[j],score[i][j]);
        }
    }
    vector<pair<int,double> > result(n,make_pair(0,0));

    for(int i = 0;i<n;i++)
    {
        result[i].first = i;
        for(int j = 0;j<m;j++)
        {
            result[i].second+=w[j]*(double(score[i][j])/maxscore[j]);
        }
    }
    sort(result.begin(),result.end(),cmp);

    score[posi][posj] = C;
    maxscore[posj] = C;
    vector<pair<int,double> > result2(n,make_pair(0,0));

    for(int i = 0;i<n;i++)
    {
        result2[i].first = i;
        for(int j = 0;j<m;j++)
        {
            result2[i].second+=w[j]*(double(score[i][j])/maxscore[j]);
        }
    }
    sort(result2.begin(),result2.end(),cmp);
    vector<int> ok(n,2);
    vector<int> ok2(n,2);
    for(int i = 0;i<k;i++)
    {
        ok[result[i].first] = 1;
    }
    for(int i  = k;i<n && result[i].second==result[i-1].second;i++) ok[result[i].first] = 3;
    for(int i  = k-1;i>=0 && result[i].second==result[i+1].second;i++) ok[result[i].first] = 3;
    for(int i = 0;i<k;i++)
    {
        ok2[result2[i].first] = 1;
    }
    for(int i  = k;i<n && result2[i].second==result2[i-1].second;i++) ok[result2[i].first] = 3;
    for(int i  = k-1;i>=0 && result2[i].second==result2[i+1].second;i++) ok[result2[i].first] = 3;
    for(int i = 0;i<n;i++)
    {
        if(ok[i]!=ok2[i] || ok[i]==3)
        {
            cout<<'3'<<endl;
        }
        else cout<<ok[i]<<endl;
    }
    return 0;
}
