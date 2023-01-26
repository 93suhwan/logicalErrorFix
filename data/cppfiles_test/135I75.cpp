#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset; // find_by_order, order_of_key
#define ll long long
#define pb push_back
#define mp make_pair
#define inf 100000000000
#define mod 1000000007
#define pi pair<ll,ll>
 ll power(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return power((x%mod*x%mod)%mod,n/2)%mod;
    else                             //n is odd
        return (x%mod*(power((x%mod*x%mod)%mod,(n-1)/2)%mod))%mod;

}

ll C(ll n, ll r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans =((ans) * (n - r + i))%mod;
        ans =(ans)/i;
    }

    return ans;
}

void solve()
{
    int n,k,i,temp,ans=0,j,temp1,temp2,count=0,t1;
    vector<int> v1;
      vector<int> v2;

    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        v1.pb(temp);
    }
    sort(v1.begin(),v1.end());
    for(i=0;i<n-(k*2);i++)
    {
        ans=ans+v1[i];
    }
    for(i=n-(k*2);i<n;)
    {
        temp=v1[i];
        count=0;
        while(temp==v1[i])
        {
            count++;
            i++;
        }
        v2.pb(count);
    }
    for(i=v2.size()-1;i>=0;i--)
    {
        temp=v2[i];
        if(temp==0)
            continue;
        for(j=i-1;j>=0;j--)
        {
            if(v2[j]>1)
            {
                t1=v2[j]-1;
                if(temp<=t1)
                {
                    v2[j]=v2[j]-temp;
                    continue;
                }
                else{
                    temp=temp-t1;
                    v2[j]=1;
                    if(temp==0)
                        continue;
                }
            }
        }
        for(j=i-1;j>=0;j--)
        {
            if(v2[j]==1)
            {
                v2[j]=0;
                temp--;
                if(temp==0)
                    continue;
            }
        }
        ans=ans+temp/2;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    solve();
   return 0;
}
