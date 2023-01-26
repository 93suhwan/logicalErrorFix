#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
ll power(ll x, ll y, ll p)
{
    ll res=1; 
    x=x%p; 
    if(x==0)return 0;
    while(y>0)
    {
        if(y&1)
            res=(res*x)%p;
        y=y>>1;
        x=(x*x)%p;
    }
    return res;
} 
std::set<ll> factors(ll n)
{
    std::set<ll>v ;
	for(ll i=1;i*i<=n;i++)
	{
		if (n%i==0)
		{
			v.insert(i);
			v.insert(n/i);
		}
	}
	return(v);
}

void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int main() 
{
    fast();
	ll t;
	cin>>t;

	while(t--)
	{
	  ll n;
	  cin>>n;ll a[n];
	  std::vector<ll>e ;std::vector<ll>o ;
	  for(ll i=0;i<n;i++)
	  {
	      cin>>a[i];
	  }
	  if(n==1)
	  {
	      cout<<a[0]<<"\n";continue;
	  }
	  ll g1=a[0];ll g2=a[1];
	  for(ll i=0;i<n;i++)
	  {
	      if(i%2==0)
	      {
	          g1=__gcd(g1,a[i]);e.pb(a[i]);
	      }
	      else
	      {
	          g2=__gcd(g2,a[i]);o.pb(a[i]);
	      }
	  }
	  if(g1==g2)
	  {
	      cout<<0<<"\n";continue;
	  }
	  else
	  {int ff=0,ff1=0;
	      if(g1!=1)
	      {
	         for(ll i=0;i<o.size();i++)
	         {
	             if(o[i]%g1==0){ff=1;break;}
	         }
	         if(ff==0){cout<<g1<<"\n";continue;}
	      }
	      else if(g1==1 || ff==1)
	      {
	          if(g2!=1)
	          {
	         for(ll i=0;i<e.size();i++)
	         {
	             if(e[i]%g2==0){ff1=1;break;}
	         }
	         if(ff1==0){cout<<g2<<"\n";continue;}
	          }
	      if(ff1==1 || g2==1)
	      {
	          cout<<0<<"\n";continue;
	      }
	      
	      }
	  }
	}
	
	
	
}

