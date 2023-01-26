#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_pset tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
#define endl '\n'
#define pll pair<ll,ll>
#define rep(i,n) for(ll i=0;i<n;i++)
#define f(i,j,n) for(ll i=j;i<n;i++)
#define mod 1000000007   
#define INF 1000000000000000000
#define ff first
#define ss second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pie 3.141592653589793238462643383279
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define SB(a) sort(a.begin(),a.end(),greater<ll>());
#define SS(a) sort(a.begin(),a.end());
#define vll vector<ll>
#define vpll vector<pll>
vector<bool> prime;
vector<ll> fact,inv,primes,factors,pf;
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

ll power(ll a,ll b)
{
	if(a==1||b==0)	return 1;
	ll c=power(a,b/2);
	ll res=1;
	res=c*c;
	if(res>=mod)	res%=mod;
	if(b%2)	res*=a;
	if(res>=mod)	res%=mod;
	return res;
}
void factorial(ll n)
{
	fact.resize(n+1);
	fact[0]=1;
	for(ll i=1;i<=n;i++)
	{
		fact[i]=fact[i-1]*i;
		if(fact[i]>=mod)	fact[i]%=mod;
	}
}
ll ncr(ll n,ll r)
{
	if(n<r||n<0||r<0)	return 0;
	ll b=inv[n-r];
	ll c=inv[r];
	ll a=fact[n]*b;
	if(a>=mod)	a%=mod;
	a*=c;
	if(a>=mod)	a%=mod;
	return a;
}
void sieve(ll n)
{
    prime.assign(n+1,1);
	prime[1]=false;
    for(ll p=2;p*p<=n;p++)
	{
		if(prime[p])
		{
			for(ll i=p*p;i<=n;i+=p)	prime[i]=false;
		}
	}	
    for(ll i=2;i<n+1;i++)
	{
		if(prime[i]) primes.push_back(i);
	} 
}
void prime_sieve(ll n)
{
	pf.assign(n+1,0);
	rep(i,n+1) pf[i]=i;
	for(ll i=2;i<=n;i++)
	{
		if (pf[i]==i)
		{
			for(ll j=i;j<=n;j+=i) pf[j]=i;
		}
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------
// Always remember: if (condition) if (condition) statement; This doesn't work !!
// Always increase boundaries for global or frequency questions
// pow((ll)10,i) doesn't work sometimes. It is better to use multiple of 10 in arrays. Always remember this.
// delete values when defining global if there are multiple testcases
// don't try to be smart and make stupid mistakes
void solve()
{
    ll n;cin>>n;
    int arr[n];
    ll cnt=0;
    double sum=0;
    rep(i,n)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    sum/=n;
    int sm=0;
    // rep(i,n)
    // {
    //     if(arr[i]==sum)
    //     cnt++;
    // }
    double x=sum*2;
    sort(arr,arr+n);
    int i=0,j=n-1;
    while(i<=j)
    {
        if(arr[i]==sum)
        {
            sm++;
            i++;
        }
        else if(arr[i]+arr[j]==x)
        {
            int xx=arr[i],yy=arr[j];
            int xi=1,xj=1;
            int c=i,d=j;
            i++;
            while(arr[i]==xx)
            {
                xi++;
                i++;
            }
            j--;
            while(arr[j]==yy)
            {
                xj++;
                j--;
            }
            
            cnt+=xi*xj;
        }
       else  if(arr[i]+arr[j]>x)j--;
       else  if(arr[i]+arr[j]<x)i++;
        
    }
    // rep(i,n)
    // {
    //     f(j,i+1,n)
    //     {
    //         if(arr[i]+arr[j]==x)
    //         cnt++;
    //     }
    // }
    cnt+=((sm*(sm-1))/2);
    cout<<cnt<<endl;
}
int main()
{
	//freopen("Input1.txt","r",stdin);
	//freopen("Output1.txt","w",stdout);
	fast();
	ll T=1;
	cin>>T;
	rep(z,T) solve();
}