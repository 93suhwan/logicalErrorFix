//clear adj and visited vector declared globally after each test case
//check for long long overflow   
//Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;
//Incase of close mle change language to c++17 or c++14  
#include <bits/stdc++.h>      
#include <ext/pb_ds/assoc_container.hpp>  
#define int long long      
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);cout.precision(dbl::max_digits10);
#define pb push_back 
#define mod 1000000007ll //998244353ll
#define lld long double
#define mii map<int, int> 
#define pii pair<int, int>
#define ll long long
#define ff first
#define ss second 
#define all(x) (x).begin(), (x).end()
#define rep(i,x,y) for(int i=x; i<y; i++)    
#define fill(a,b) memset(a, b, sizeof(a))
#define vi vector<int>
#define setbits(x) __builtin_popcountll(x)
#define print2d(dp,n,m) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++)cout<<dp[i][j]<<" ";cout<<"\n";}
typedef std::numeric_limits< double > dbl;
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
const long long N=200005, INF=2000000000000000000;
lld pi=3.1415926535897932;
int lcm(int a, int b)
{
    int g=__gcd(a, b);
    return a/g*b;
}
int power(int a, int b, int p)
    {
        if(a==0)
        return 0;
        int res=1;
        a%=p;
        while(b>0)
        {
            if(b&1)
            res=(res*a)%p;
            b>>=1;
            a=(a*a)%p;
        }
        return res;
    }
int a[N], b[N], m[N], x[N], y[N], mix[N], mxx[N];
int solve(vi id)
{
    map <int, vector <pii> > mp;
    int ans=0;
    for(auto i:id)
    {
        mp[mix[i]].pb({i, 0});
        mp[mxx[i]].pb({i, 1});
    }
    set <int> cur;
    for(auto it:mp)
    {
        vi v[2];
        for(auto p:it.ss)
        v[p.ss].pb(p.ff);
        for(auto i:v[0])
        cur.insert(i);
        if(v[1].size())
        {
            if(cur.size())
            ans++;
            for(auto i:cur)
            {
                x[i]=it.ff;
                y[i]=(a[i]+b[i]-m[i]-x[i]);
                x[i]=(a[i]-x[i]);
                y[i]=(b[i]-y[i]);
            }
            cur.clear();
        }
    }
    return ans;
}
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map <int, vi> mp;
        rep(i,0,n)
        {
            cin>>a[i]>>b[i]>>m[i];
            int sum=a[i]+b[i]-m[i];
            int mi=a[i]-min(a[i], m[i]), mx=a[i]-(m[i]-min(b[i], m[i]));
            mix[i]=mi;
            mxx[i]=mx;
            mp[sum].pb(i);
        }
        int ans=0;
        for(auto it:mp)
        ans+=solve(it.ss);
        cout<<ans<<"\n";
        rep(i,0,n)
        cout<<x[i]<<" "<<y[i]<<"\n";
    }
}