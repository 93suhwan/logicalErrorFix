#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;
using namespace __gnu_pbds;
ll int mod=998244353;
typedef tree<ll int, null_type, less<ll int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define PI 3.14159265


ll int mul(ll int x, ll int y)
{
    return (x * 1ll * y) % mod;
}


ll int add(ll int x,ll int y)
{
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}


long long power(long long a, long long b,ll m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res*a)%m;
        a =(a*a)%m;
        b >>= 1;
    }
    return res%m;
}



int main() {
    IOS;
    ll int n;
    cin>>n;
    ll int val=0;
    for(int i=1;i<n;i++)
    {
        cout<<"? ";
        for(int j=1;j<n;j++)
        {
            cout<<i<<" ";
        }
        cout<<n<<endl;
        cout.flush();
        ll int ans;
        cin>>ans;
        if(ans==0)
        {
            val=i;
            break;
        }
    }
    ll int ans1[n+1];
    memset(ans1,0,sizeof(ans1));
    ans1[n]=val;
    for(int i=1;i<val;i++)
    {
        cout<<"? ";
        for(int j=1;j<n;j++)
        {
            cout<<val<<" ";
        }
        cout<<i<<endl;
        cout.flush();
        ll int ans;
        cin>>ans;
        ans1[ans]=i;
    }
    cout<<"! ";
    for(int i=1;i<=n;i++)
    cout<<ans1[i]<<" ";
    cout<<endl;
}