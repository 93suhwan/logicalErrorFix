#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define int long long
#define endl "\n"
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fr(a,b,c) for(int a=b; a<c; a++)
#define frr(a,b,c) for(int a=b;a>=c;a--)
#define pb push_back
#define pii pair<int,int>
#define R(a) ll a; cin >> a;
#define RS(a) string  a; cin >> a;
typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;
#define RA(a, n) ll a[(n) + 1] = {}; fr(i, 1, (n)+1) {cin >> a[i];}
#define RM(a, n, m) int a[n + 1][m + 1] = {}; fr(i, 1, n+1) {fr(j, 1, m+1) cin >> a[i][j];}
#define reset(X) memset(X, 0, sizeof(X))
using vi=vector<int>;

void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]"<<endl;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
#define all(x) (x).begin(),(x).end()
const int inf = 1e18;
const int mod=1e9+7;
unsigned int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
int modInverse(int n, int p)
{
    return power(n, p-2, p);
}

bool cmp(pair<int,int>a, pair<int,int>b)
{
    if(b.fi>a.fi)
    {
        return 1;
    }
    else
        if(a.fi>b.fi)
        {
            return 0;
        }
        else
        {
            return a.se>b.se;
        }
    }
    const int maxn = 103;
    vector<int>adj[maxn];
    int up[maxn][21];
    int tin[maxn], tout[maxn];
    int timer;
    int dis[maxn];
    vector<int>level[maxn];
    int f[maxn];
    void prec()
    {
        f[0] = 1;
        fr(i, 1, maxn)
        {
            f[i] = f[i-1]*i;
            f[i] = f[i]%mod;
        }
    }
    void dfs(int v, int p)
    {
        tin[v] = ++timer;
        up[v][0] = p;
        
        for(int i = 1; i<21; i++)
        {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for(auto it: adj[v])
        {
            if(it != p)
            {
                dis[it] = dis[v] + 1;
                dfs(it, v);
                
            }
        }
        level[dis[v]].pb(v);
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v)
    {
        if(is_ancestor(u,v))
        {
            return u;
        }
        if(is_ancestor(v,u))
        {
            return v;
        }
        for(int i = 20; i>=0; i--)
        {
            if(!is_ancestor(up[u][i], v))
            {
                u = up[u][i];
            }
        }
        return up[u][0];
    }
    int nCr(int n, int k)
    {
        int ans = f[n];
        ans = (ans*modInverse(f[k], mod))%mod;
        ans = (ans*modInverse(f[n-k], mod))%mod;
        return ans;
    }
    void solve()
    {
        R(n);R(k);

         fr(i, 1, n)
        {
            R(x);R(y);
            adj[x].pb(y);
            adj[y].pb(x); 
        }

       int ans = 0;
       if(k == 2)
       {
        cout<<(n*(n-1))/2<<endl;
        fr(i, 1, n+1)adj[i].clear();
        return;
       }


       for(int root = 1; root <= n; root++)
       {
        
        reset(up);
        reset(tin);
        reset(tout);
        timer = 0;
        reset(dis);
                fr(i, 0, 100)
        {
            level[i].clear();
        }
        dfs(root, root);

        for(int i = 0; i<100; i++)
        {
            if(level[i].size() >= k)
            {
                bool f = 1;
                for(int j = 0; j<level[i].size(); j++)
                {
                    for(int k = j+1; k<level[i].size(); k++)
                    {
                        if(lca(level[i][j], level[i][k])!= root)
                        {
                            f = 0;
                            break;
                        }
                    }
                    if(!f)
                    {
                        break;
                    }
                }
                if(f)
                {
                    ans += nCr(level[i].size(), k);
                    ans = ans%mod;
                }
            }
        }
       }
       fr(i, 1, n+1)adj[i].clear();
       cout<<ans<<endl;




    }

    signed main()
    {
        fastio;
        prec();
    #ifndef ONLINE_JUDGE
        if(fopen("input.txt", "r"))
        {
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        }
    #endif
        int t=1;
         cin>>t;
        for(int i = 1; i<=t; i++)
        {
            solve();
        }
    }

