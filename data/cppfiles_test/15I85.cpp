#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e2+5;
const int N=1e6+5;
const int mod=1e9+7;

ll dp[M][M];
int k,n,freq[M][M];
vector<int>adj[M],dpV;

void DFS(int x,int p)
{
    int i;
    freq[x][0]=1;
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            DFS(y,x);
            for(i=1;i<n;i++)freq[x][i] += freq[y][i-1];
        }
    }
}

ll DP(int cur,int cnt)
{
    if(cnt > k)return 0;
    if(cur == (int)dpV.size())return (cnt == k);
    ll &ans=dp[cur][cnt];
    if(ans > -1)return ans;
    ans=DP(cur+1,cnt);
    ans += dpV[cur]*DP(cur+1,cnt+1);
    return ans %= mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,j,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        if(k == 2)ans=(1ll*n*(n-1))/2;
        else
        {
            ans=0;
            for(i=1;i<=n;i++)
            {
                memset(freq,0,sizeof(freq));
                DFS(1,0);
                for(j=1;j<n;j++)
                {
                    dpV.clear();
                    for(int it : adj[i])
                    {
                        if(freq[it][j-1])dpV.emplace_back(freq[it][j-1]);
                    }
                    if((int)dpV.size() >= k)
                    {
                        memset(dp,-1,sizeof(dp));
                        ans += DP(0,0);
                        if(ans >= mod)ans -= mod;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
