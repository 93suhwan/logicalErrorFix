#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define pb push_back
#define all(v) v.begin(),v.end()
#define fri(i,b,e) for(i=b;i<e;i++)
#define frr(i,b,e) for(i=b;i>e;i--)
#define M 1000000007 
template <class T>
string to_string (T t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}
 
ll ispower(ll x)
{
	return !(x&(x-1));
}
 
void swap(ll *x,ll *y)
{
    ll t=*x;
    *x=*y;
    *y=t;
}
 
/*void swap(ll *x,ll *y)
{
    ll t=*x;
    *x=*y;
    *y=t;
} */
 
/*void Sieve() 
{   ll i;
	prime[1]=0;
	//cout<<"AA";
   fri(i,2,100000001)
   prime[i]=1;
    for (ll p=2; p<=100000001; p++) 
    { 
        if (prime[p]) 
        {
            for (ll i=p*2; i<=100000001; i += p) 
                prime[i] = 0; 
        } 
    }
}*/
 
ll power(ll x, ll y) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return (temp%M*temp%M)%M; 
    else
        return (x%M*temp%M*temp%M)%M; 
} 
 
ll inv(ll a)
{
	return power(a, M - 2);
}
 
ll fact(ll n)
{
    ll ans=1;
    ll i=2;
    fri(i,2,n+1)
    {
        ans=(ans%M*i%M)%M;
    }
    return ans;
}
 
ll comb(ll n,ll r)
{
    ll n1=(fact(r)%M*fact(n-r)%M)%M;
    ll ans=1;
    ans=fact(n);
    //cout<<ans%M*inv(n1)%M;
    return (ans%M*inv(n1)%M)%M;
}
 
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
 
ll findGCD(ll arr[], ll n,ll m) 
{ 
    ll result = arr[0]+m; 
    for (ll i = 1; i < n; i++) 
    { 
    	if(arr[i]==arr[i-1])
    	continue;
        result = __gcd(arr[i]-arr[i-1]+m, result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
}
 
ll lcm(ll a,ll b)
{
    return (a*b/(__gcd(a,b)));
}
 
ll poww(ll x,ll k)
{
    ll res=0,x2=x;
    while(x2>0)
    {
        res++;
        x2/=k;
    }
    return res;
    /*if((ll)pow(k,res-1)==x)
    return --res;
    return res-1;*/
}

ll digits(ll x)
{
	ll n1=x;
	ll dig=0;
	while(n1>0)
	{
		dig++;
		n1/=10;
	}
	return dig;
}

ll calc(ll n,ll k)
{
	//cout<<-(n-1)<<" "<<n<<"\n";
	ll j=1,res;
	if(k==1)
	{
		//cout<<"1\n";
		return 1;
	}
	//l=2;
/*	while(j<k)
	{
		j+=l;
		l++;
	}*/
	j=log2(k);
	if((k&(k-1))==0)
	{
		return power(n,j)%M;
	}
	else if((k&(k+1))==0)
	{
		if(j==1)
		{
			if(k==2)
			return n;
			else
			return (n+1);
		}
		ll res=power(n,j+1)-1;
		res=(res%M*power(j-1,M-2)%M)%M;
		return res;
	}
	else
	{
		ll l=k-power(2,j);
		res=(power(n,j)%M+calc(n,l)%M)%M;
		return res;
	}
}

void solve()
{
	ll n,i,j,k;
	cin>>n>>k;
	cout<<calc(n,k)<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	//
	cin>>t;
	/*std::cout << std::fixed;
	std::cout << std::setprecision(9);// << '\n';*/
	//calc();
	while(t--)
    {
    	solve();
    //	cout.flush();
    }
    return 0;
}