#include<bits/stdc++.h>
#include<iostream>
#include <iomanip>
#include<math.h>
#include<fstream>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define fi first
#define se second
#define gap ' '
#define abs(x) ((x)>0?(x):-(x))
#define INF 1e18
#define mod 998244353
#define inf 1e9
#define pi 3.14159265358979
#include<time.h>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l,r) (rng);
}
ll powr(ll m,ll n)
{
    if(m==1)
        return 1;
    if(n==0)
        return 1;
    if(n==1)
        return m%mod;
    if(n%2)
    {
        ll te=powr(m,n/2);
        return (((te*te)%mod)*(m%mod))%mod;
    }
    else
    {
        ll te=powr(m,n/2);
        return (te*te)%mod;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int  tc=1;
    cin>>tc;
    for(int tt=1; tt<=tc; tt++)
    {
       int n;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++) cin>>a[i];
       int cnt[n+1]={0};
       for(int i=0;i<n;i++) cnt[a[i]]++;
       int ans[n+1];
       ans[0]=0;
       sort(a,a+n);
       int j=0;
       priority_queue<int> pq;
       for(int i=1;i<=n;i++)
       {
           int in=0;
           while(j<n && a[j]<i) pq.push(a[j]),j++,in++;
           if(in) {pq.pop();
           ans[i]=ans[i-1];
           }
           else if(pq.size())
           {
             int now=pq.top();
             pq.pop();
             ans[i]=ans[i-1]+i-1-now;
           }
           else {ans[i]=-1;
           for( int j=i;j<=n;j++) ans[j]=-1;
           break;
           }
       }
       for(int i=0;i<=n;i++)
        if(ans[i]!=-1)
       {
           ans[i]+=cnt[i];
       }
       for(int i=0;i<=n;i++) cout<<ans[i]<<gap;
       cout<<endl<<endl;
    }

}
