#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
#define setpr(x) cout<<fixed<<setprecision(x)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pi pair<int,pii>
#define pr pair<int,node*>
#define endl '\n'
const int inf=2e9;
const int mod=1e9+7;
const int N=1e5+5;
void solve()
{
    int n,k; cin>>n>>k;
    if(!k)
    {
        cout<<1<<endl;
        return;
    }
    int val=1;
    for(int i=1;i<n;i++)
    {
        val*=(long long)2;
        val%=mod;
    }
    int gr=0,sm,eq;
    if(n%2==0)gr=1;
    sm=val; if(n%2)sm--; sm=(sm%mod+mod)%mod;
    eq=val; if(n%2==0)eq--; else eq++;
    eq=(eq%mod+mod)%mod;
    int dp[k][2]; dp[0][0]=sm; dp[0][1]=(gr+eq)%mod;
    for(int i=1;i<k;i++)
    {
        dp[i][1]=gr*(dp[i-1][0]+dp[i-1][1])%mod;
        dp[i][1]%=mod;
        dp[i][1]+=eq*dp[i-1][1]%mod;
        dp[i][0]=eq*dp[i-1][0]%mod;
        dp[i][0]+=sm*(dp[i-1][0]+dp[i-1][1])%mod;
    }
    cout<<dp[k-1][1]<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--)solve();
    return 0;
}
