#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/*---------------------DEBUGGING--------------------------------------------*/
void __print(int x) {cerr << x;}
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
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/*-------------------------------------------------------------------------------------*/
#define pb push_back
//#define ll long long
#define pii pair<int,int>
#define pcc pair<char,char>
#define F first
#define S second
#define int long long
#define pi 3.141592653589793238462643383279502
#define M  998244353  //1000000007
#define rep(i,a,n) for(int i=a;i<n;i++)
#define INF 1e18
#define N 100005
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define endl "\n"
//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
vi a(1005);
int calc(int l,int r)
{
    int n = (r-l+1);
    vi v(n+1);
    vi pref(n+1);
    int mul = 1;
    for(int i=l;i<=r;i++)
    {
        int idx = (i - l + 1);
        v[idx] = a[i];
        pref[idx] = (pref[idx - 1] + mul*v[idx]);
        mul*=-1;
    }
    int ans = 0;
    for(int i=2;i<=n;i+=2)
    {
        for(int j=1;j<i;j+=2)
        {
            int val = (pref[i-1] - pref[j]);
            int r = v[i];
            int l = v[j];
            if(val > 0)r -= min(r,val);
            if(val < 0)l -= min(l,abs(val));
            ans+=min(l,r);
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin>>n;
    vi pref(n+1);
    int mul = 1;
    rep(i,1,n+1)
    {
        cin>>a[i];
    }
    int sum = 0;
    int l = 1;
    vector<pii>v;
    for(int i=1;i<=n;i++)
    {
        sum+=(mul*a[i]);
        mul*=-1;
        if(sum < 0)
        {
            v.pb({l,i});
            l=i+1;
            sum=0;
        }
    }
    if(l < n)
    {
        v.pb({l,n});
    }
    int ans = 0;
    for(auto x:v)
    {
        ans+=calc(x.F,x.S);
    }
    cout<<ans<<endl;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int tests;
   tests=1;
   //cin>>tests;
   for(int i=0;i<tests;i++)
   {
       solve();
   }
}

