#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class A> using ordered_set=tree<A,null_type,less<A>,rb_tree_tag,tree_order_statistics_node_update>;

#define ll long long 
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(x) x.begin(),x.end()
#define debug(a...) cout<<#a<<": ";for(auto &it:a)cout<<it<<" ";cout<<"\n";
#define pb push_back
#define br "\n"
const int mod=998244353;
const int maxn=2e5+9;
const int INF=1e18;

// ---------------------------------------------------------------------
int n;
vector<int>sum;
// ---------------------------------------------------------------------
int getSum(int l,int r)
{
    int res=sum[r];
    if(l!=0)
        res-=sum[l-1];
    return res;
}
vector<int>fac;
void factorial()
{
    fac.assign(maxn,0);
    fac[0]=1;
    for(int i=1;i<maxn;i++)
        fac[i]=(fac[i-1]*i)%mod;
}
int binexp(int a,int b)
{
    int res=1;
    while(b!=0)
    {
        if(b%2!=0)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b=b/2;
    }
    return res;
}
int ncr(int n1,int r)
{
    if(n1<r||n1==0)
        return 0;
    int den=(fac[r]*fac[n1-r])%mod;
    int res=(fac[n1]*binexp(den,mod-2))%mod;
    return res;
}
// ---------------------------------------------------------------------
void test_case(int tno)
{
    int k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(k==0)
    {
        cout<<1<<br;
        return;
    }
    sum.assign(n,0);
    for(int i=0;i<n;i++)
    {
        sum[i]=s[i]-'0';
        if(i!=0)
            sum[i]+=sum[i-1];
    }
    vector<int>dp(n,0);
    int flag=0;
    for(int i=1;i<n;i++)
    {
        dp[i]=(dp[i]+dp[i-1])%mod;
        if(sum[i]<k)
            continue;
        flag++;
        int l=-1;
        for(int j=i;j>=0;j--)
        {
            if(getSum(j,i)==k)
                l=j;
        }
        if(flag==1)
        {
            dp[i]=(dp[i]+ncr(i-l+1,k))%mod;
            continue;
        }
        if(flag!=1)
        {
            dp[i]=(dp[i]+ncr(i-l+1,k))%mod;
            if(i>l)
                dp[i]=(dp[i]-ncr(i-l,getSum(l,i-1))+2*mod)%mod;
        }
    }
    if(flag==0)
        cout<<1<<br;
    else
        cout<<dp[n-1]<<br;
}

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif    
    int t=1;
    //cin>>t;
    factorial();
    for(int i=1;i<=t;i++)
        test_case(i);
}