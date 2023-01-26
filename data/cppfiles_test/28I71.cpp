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


void solve()
{
   R(n);R(k);
   RA(a,n);
   int aa[n+1];
   fr(i,1,n+1)aa[i] = a[i];
   map<int,int>m;
   int mx = 0;
   int val = 0;
   for(int i = 0; i<n; i++)
   {
    a[i] -= i;
    mx = max(mx, a[i]);
    m[a[i]]+=1;
    mx = max(mx, m[a[i]]);
    if(m[a[i]] == mx)val = a[i];
   }
   int start = 0;
   for(int i = 1; i<=n; i++)
   {
    if(a[i] == val)
    {
        start = i;
        break;
    }
   }
   int b[n+1];
   b[start] = a[start] + start;
   for(int i = start+1; i<=n; i++)
   {
    b[i] = b[i-1] + 1;
    if(b[i]>n)b[i] = 1;
   }
   for(int i = 1; i<start; i++)
   {
    if(i == 1)
    {
        b[i] = b[n] +1;
        if(b[i]>n)b[i] = 1;
    }
    else
    {
        b[i] = b[i-1]+1;
        if(b[i]>n)b[i] = 1;
    }
   }
   int c = 0;
   for(int i = 1; i<=n; i++)
   {
    if(aa[i] != b[i])
    {
        c+=1;
    }
   }
   c = c/2+(c%2?1:0);
   //fr(i,1,n+1)cout<<b[i]<<endl;
   if(c>k)
   {
    cout<<0<<endl;
   }
   else
   {
    vector<int>ans;
    int pt = (n-b[1]+1)%n;
    if(n == 3)
    {
        if(c == 0 || k == 0)
        {
            cout<<1<<" "<<pt<<endl;
        }
        else
        {
            cout<<3<<" "<<0<<" "<<1<<" "<<2<<endl;
        }
        return;
    }
    ans.push_back(pt);
    cout<<ans.size()<<" ";
    fr(i,0,ans.size())
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
   }



}

signed main()
{
    fastio;
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

