#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
 
typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
 
#define mp make_pair
#define MAX *max_element
#define MIN *min_element
#define all(c) (c).begin(), (c).end()
#define GCD __gcd
#define pb push_back
 
#define inf 1e9
#define INF 1e18
#define mod 1000000007
#define N 1000006
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n+1],i,k;
        for(i=1;i<=n;i++) cin>>a[i];
        vector<ll>suf(n+2,inf);
        ll sum=0,pre[n+1];
        for(i=1;i<=n;i++)
        {
            sum+=a[i];
            pre[i]=sum;
        }
        pre[0]=0;
        int ans=0;
        for(k=1;k*(k+1)<=2*n;k++)
        {
            sum=0;
            vector<ll>vec(n+2,0);
            for(i=1;i<=n-k+1;i++)
            {
                sum=pre[i+k-1]-pre[i-1];
                if(suf[i+k]>sum)
                {
                    vec[i]=sum;
                    ans=k;
                }
            }
            if(ans<k) break;
            ll ma=0;
            for(i=n+1;i>=1;i--)
            {
                ma=max(ma,vec[i]);
                suf[i]=ma;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
