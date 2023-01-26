#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
  
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

long long mod = 1e9+7;
const int N = 2e5+5;
vector<long long>fact(N), invfact(N);

long long power(long long x, long long y)
{
    long long ans = 1;

    while(y>0)
    {
        if(y&1)
            ans = (ans * x)%mod;

        y/=2LL;
        x = (x*x)%mod;
    }

    return ans;
}

void precompute()
{
    fact[0] = fact[1] = 1;
    for(long long i = 2; i<N; i++)
    {
        fact[i] = fact[i-1] * i;
        fact[i] %=mod;
    }
    invfact[N-1] = power(fact[N - 1], mod - 2);

    for(long long i = N-2; i>=0; i--)
    {
        invfact[i] = invfact[i+1] * (i+1);
        invfact[i]%=mod;
    }
}

long long nCr(long long n, long long r)
{
    if(n < r)
        return 0;
    long long ans = fact[n];
    ans%=mod;
    ans*=invfact[r];
    ans%=mod;
    ans*=invfact[n-r];
    ans%=mod;

    return ans;
}

int main()
{  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    cin>>t;
    while(t--)
    {
        long long n, k, ans = 0, mult = 0, temp = 0;
        cin>>n>>k;
        long long p = 2;

        if(k == 0)
        {
            cout<<1<<'\n';
            continue;
        }
        for(long long i=1; p*i<=n; i++)
        {
            mult += nCr(n, p*i);
            mult%=mod;
        }
        if(n&1)
        {
            mult+=2LL;
            mult%=mod;
        }
        else
        {
            mult++;
            mult%=mod;
        }

        for(long long r=1; r<=k; r++)
        {
            temp += nCr(k, r);
            temp%=mod;
        }
        ans = temp * mult;
        ans%=mod;
        cout<<ans<<'\n';
    }

    return 0;
}