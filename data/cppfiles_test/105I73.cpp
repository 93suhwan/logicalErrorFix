#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
//#pragma GCC optimize("O3")
using namespace std;
using namespace __gnu_pbds;
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll t,n,v[30005],dp[2][3005][3005];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        dp[0][i][i]=dp[1][i][i]=0;
    for(int lg=2;lg<=n;lg++)
        for(int i=1;i<=n;i++)
        {
            int j=i+lg-1;
            dp[0][i][j]=dp[1][i][j]=1e18;
            if(j>n)
                break;
            int nr=v[i];
            int st=i;
            while(v[st]==nr&&st<=j)
                st++;
            int dr=j;
            if(st>dr)
            {
                dp[0][i][j]=dp[1][i][j]=0;
                continue;
            }
            st=i;
            dr=j;
            int num=0;
            bool okk=0;
            if(i==1&&j==n)
                okk=1;
            while(num<=40)
            {
                num++;
                ll val=dp[0][i][st]+dp[0][st+1][dr]+(v[i]!=v[st+1]);
                val=min(val,dp[0][i][st]+dp[1][st+1][dr]+(v[i]!=v[dr]));
                val=min(val,dp[1][i][st]+dp[0][st+1][dr]+(v[st]!=v[st+1]));
                val=min(val,dp[1][i][st]+dp[1][st+1][dr]+(v[st]!=v[dr]));
                dp[0][i][j]=min(dp[0][i][j],val);
                dp[1][i][j]=min(dp[1][i][j],val);
                if(st+2<=dr)
                    st++;
                else
                    break;
            }
            st=i;
            dr=j;
            while(v[dr]==nr&&dr>=i)
                dr--;
            if(st>dr)
            {
                dp[0][i][j]=dp[1][i][j]=0;
                continue;
            }
            st=j-1;
            num=0;
            okk=0;
            if(i==1&&j==n)
                okk=1;
            while(num<=40)
            {
                num++;
                ll val=dp[0][i][st]+dp[0][st+1][dr]+(v[i]!=v[st+1]);
                val=min(val,dp[0][i][st]+dp[1][st+1][dr]+(v[i]!=v[dr]));
                val=min(val,dp[1][i][st]+dp[0][st+1][dr]+(v[st]!=v[st+1]));
                val=min(val,dp[1][i][st]+dp[1][st+1][dr]+(v[st]!=v[dr]));
                dp[0][i][j]=min(dp[0][i][j],val);
                dp[1][i][j]=min(dp[1][i][j],val);
                if(st-2>=i)
                    st--;
                else
                    break;
            }
        }
    cout<<min(dp[0][1][n],dp[1][1][n])<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
