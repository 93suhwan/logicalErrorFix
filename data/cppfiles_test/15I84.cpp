#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e2+5;
const int N=2e5+5;
const int mod=1e9+7;

vector<int>adj[M];
int cnt[M],dist[M];
ll fact[M],ncr[M][M];

long long BigMod(long long val,long long pow)
{
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}

ll nCr(int n,int r)
{
    if(n < r)return 0;
    return (fact[n]*BigMod(fact[r]*fact[n-r],mod-2))%mod;
}

void PreCal()
{
    int i,j;
    fact[0]=1;
    for(i=1;i<M;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        for(j=0;j<=i;j++)ncr[i][j]=nCr(i,j);
    }
}

void DFS(int x,int p)
{
    dist[x]=dist[p]+1;
    ++cnt[dist[x]];
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,j,k,n,t,x,y;
    PreCal();
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
        if(k == 2)ans=((n*(n-1))/2)%mod;
        else
        {
            ans=0;
            for(i=1;i<=n;i++)
            {
                dist[i]=-1;
                for(j=1;j<=n;j++)cnt[j]=0;
                DFS(i,i);
                for(j=1;j<n;j++)ans=(ans+ncr[cnt[j]][k])%mod;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
