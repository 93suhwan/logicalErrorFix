#include<bits/stdc++.h>
#include<cmath>
#define SZ(x) ((int)x.size())
#include<vector>
#include<set>
#include<map>
#include <unordered_map>
#define pb push_back
#include<string>
#include<cmath>
#define ll long long
#define lli long long int
#define REP(i,n) for(ll i=1;i<=n;i++)
#include<cctype>
#include <sstream>
#define endl "\n"
#define pairs pair<int,int>
#define ld long double
#define mod 1000000007
#define Mod 998244353
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
ll pows(ll a,ll n,ll m)
{
	a=a%m;
	ll res=1;
	while(n)
	{
	if(n%2!=0)
	{
		res=(res*a)%m;
		n--;
		}
		else
		{
			a=(a*a)%m;
			n=n/2;
			}	
	}
	return res%m;
}
ll gcd(ll a,ll b)
{
	
	if(b==0)
	return a;
	else 
	return gcd(b,a%b);
}
bool isprime(ll n)
{
	if(n==1||n==0)
	{
		return false;
	}
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
bool istrue(string s)
{
	int i=0;
	int j=s.size()-1;
	while(i<j)
	{
	if(s[i]==s[j])
	{
		i++;
		j--;
		}
		else
		{
		return false;
			}	
	}
	return true;
}
const int N=500005;
const long long INF=1e18;
set<ll> ar[N];
ll ans[N];
int main()
{
ios::sync_with_stdio(false);
	 cin.tie(0);
  cout.tie(0);
  ll TT=clock();
  TT = clock();
  ll q;
  cin>>q;
  
 	ll pos=0;
  while(q--)
  {
  
  	ll tl;
  	cin>>tl;
  	if(tl==1)
  	{
  	ll x;
	cin>>x;
    ar[x].insert(pos);
    pos++;
	}
	else
	{
	ll x,y;
	cin>>x>>y;
    if(ar[x].size()>ar[y].size())
    {
    	for(ll res:ar[y])
    	{
    		ar[x].insert(res);
		}
		swap(ar[x],ar[y]);
		ar[x].clear();
	}
	else
	{
	   for(ll res:ar[x])
    	{
    		ar[y].insert(res);
		}
		ar[x].clear();	
	}
	}
  }
  for(ll i=1;i<N;i++)
  {
  	if(ar[i].size()>0)
  	{
  		for(ll res:ar[i])
  		{
  		ans[res]=i;	
		}
	  }
  }
  for(ll i=0;i<pos;i++)
  {
  	cout<<ans[i]<<" ";
  }
  cout<<endl;
  
cerr<<"\n\nTIME: "<<(long double)(clock()-TT)/CLOCKS_PER_SEC<<" sec\n";
    return 0;
}


