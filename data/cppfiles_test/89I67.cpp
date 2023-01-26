#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>e[200001];
int s[200001];
bool vis[200001];
int ans=0;
int dfs(int now)
{
    if(vis[now])return 0;
    vis[now]=true;
    int an=0,bo=0;
    for(auto x:e[now])
    if(vis[x]==false)
    {
        s[x]--;
        if(s[x]==0)an++;
        else {
            int qwq=dfs(x);
            if(qwq==0)an++;
            bo|=qwq;
        }
    }
    ans+=max(an-1,0ll);
    if(bo==0)return 1;
    else return 0;
}
main()
{
    int t;cin>>t;while(t--){
        int n;
        cin>>n;
        for(int x=1;x<=n;x++)
        e[x].clear(),vis[x]=false,s[x]=0;
        for(int x=1;x<n;x++)
        {
            int y,z;
            cin>>y>>z;
            e[y].push_back(z);
            e[z].push_back(y);
            s[y]++;
            s[z]++;
        }
        ans=0;
        dfs(1);
        cout<<ans+1<<endl;
    }
}