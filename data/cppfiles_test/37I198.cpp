#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int         long long
#define double      long double
#define ppi         pair<int,int>
#define pb          push_back
#define eb          emplace_back
#define fast        ios::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL)
#define input       freopen("input.txt","r",stdin),freopen("output.txt","w",stdout)
#define indset      tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
#define all(v)      v.begin(),v.end()
#define fo(i,j,n)   for(int i=j;i<n;++i)
#define SET(n)      cout<<fixed<<setprecision(n)
#define INF         1000000000000000000
#define M           1000000007
#define pi          3.14159265358979323846264338327950288419716939937510
#define bpc         __builtin_popcountll

int fact[200001];
void F()
{
    fact[0]=1, fact[1]=1;
    fo(i, 2, 200001) fact[i]=(fact[i-1]*i)%M;
}
int fexp(int a, int b, int m) {int ans = 1; while (b) {if (b & 1)ans = ans * a % m; b /= 2; a = a * a % m;} return ans;}
int inverse(int a, int p) {return fexp(a, p - 2, p);}
int ncr(int n, int r, int p) {if (r == 0) return 1; return (fact[n] * inverse(fact[r], p) % p * inverse(fact[n - r], p) % p) % p;}

vector<int> adj[100005];
bool A[100005];

void dfs(int node)
{
    A[node]=1;
    for(auto x:adj[node])
    {
        if(!A[x]) dfs(x);
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<ppi> node;
    fo(i,0,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb(c);
        adj[c].pb(a);
        node.eb(a,c);
    }
    vector<int> c;
    for(int i=1;i<=n;i++)
    {
        if(!A[i])
        {
            c.pb(i);
            dfs(i);
        }
    }
    for(auto x:node) cout<<x.first<<" "<<x.second<<"\n";
    if(c.size()>1)
    {
        fo(i,1,(int)c.size()) cout<<c[0]<<" "<<c[i]<<"\n";
    }
    // for(auto x:node) cout<<x.first<<" "<<x.second
    fo(i,0,100005) adj[i].clear(),A[i]=0;
    return;
}
signed main()
{
    fast;
    // input;

    auto start=chrono::high_resolution_clock::now();

    int t = 1;
    cin>>t;

    // F();
    
    fo(i,1,t+1)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
        // cout<<"\n";
    }
    
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    // cerr<<duration.count()/1000.0<<" ms\n";

    return 0;
}
