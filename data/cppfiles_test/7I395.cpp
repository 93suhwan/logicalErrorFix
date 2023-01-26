#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define int long long
const int inf=0x3f3f3f3f;
int T,n,low[200010];
ll a[200010],b[200010],g[200010][20];
ll query(int l,int r)
{
    int p=low[r-l+1];
    return __gcd(g[l][p],g[r-(1<<p)+1][p]);
}
bool check(int mid)
{
    for(int i=1; i<n-mid; i++)
        if (query(i,i+mid-1)>1)
            return 1;
    return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        for(int i=1; i<n; i++)
            b[i]=abs(a[i+1]-a[i]);
        for(int i=1; i<n; i++)
            g[i][0]=b[i];
        for (int p=1; (1<<p)<n; p++)
            for (int i=1; i+(1<<p)-1<n; i++)
                g[i][p]=__gcd(g[i][p-1],g[i+(1<<(p-1))][p-1]);
        for(int i=2; i<n; i++)
            low[i]=low[i>>1]+1;
        int l=1,r=n-1,ans;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            if (check(mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        cout<<ans+1<<endl;
    }
}
