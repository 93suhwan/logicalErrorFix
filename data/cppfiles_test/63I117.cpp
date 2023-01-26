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
#define M  998244353 //1000000007
#define rep(i,a,n) for(int i=a;i<n;i++)
#define INF 1e18
#define N 400005
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define endl "\n"
//typedef tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int dp[1LL<<20];
int pre[20][N];
void solve()
{
    int n;
    cin>>n;
    string s[n];
    rep(i,0,n)cin>>s[i];
    vi cnt(n);
    for(int i=0;i<n;i++)
    {
        int sum = 0;
        for(char c:s[i])
        {
            if(c == '(')sum++;
            else sum--;
        }
        cnt[i]=sum;
    }
    for(int i=0;i<n;i++)
    {
        int mn = 0;
        int sum = 0;
        for(char c:s[i])
        {
            if(c == '(')sum++;
            else sum--;
            mn = min(mn,sum);
            if(sum == mn)
            {
                int val = -mn;
                pre[i][val]+=1;
            }
        }
    }
    rep(i,0,1LL<<20)
    {
        dp[i]=-INF;
    }
    dp[0]=0;
    int ans = 0;
    int fm = (1LL<<n);
    for(int mask =0;mask<fm;mask++)
    {
        for(int j=0;j<n;j++)
        {
            if(1LL<<j & mask)
            {
                int tot = 0;
                rep(k,0,n)
                {
                    if((1LL<<k) & mask)
                    {
                        if(k == j)continue;
                        tot+=cnt[k];
                    }
                }
                if(tot < 0)continue;
                int curr = dp[(1LL<<j)^mask];
                ans = max(ans,curr + pre[j][tot]);
                if(tot + cnt[j] < 0)curr = -INF;
                else curr += pre[j][tot];
                dp[mask] = max(dp[mask],curr);
            }

        }
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
;
