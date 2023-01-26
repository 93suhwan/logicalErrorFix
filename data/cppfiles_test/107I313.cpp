#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
///After closer inspection you may find that the last two files contained in the library
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <functional> // for less
//namespace to use
using namespace __gnu_pbds;
#define ll long long int
#define ull unsigned long long int
#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define F first 
#define S second
#define all(v) v.begin(), v.end()
#define endl "\n"
#define LCM(m,n) m*(n/__gcd(m,n))
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<n;i++)
#define repa(i,n,a) for(ll i=a;i<n;i++)
#define tr(c,it) for(auto it=c.begin();it!=c.end();++it)
#define hell 1000000007
#define sz(x) (ll)x.size()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define LCM(m,n) m*(n/__gcd(m,n))
#define N1 1000000
#define N2 1000000000
#define vvll vector <vector <ll> >
#define vll  vector <ll>
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

void solve()
{
	ll n;
	cin>>n;
	ll a,b;
	cin>>a>>b;
	if(abs(a-b)>1)
	{
		cout<<-1<<endl;
		return;
	}
	if(n==2)
	{
		if(a+b>0)
		{
			cout<<-1<<endl;
			return;
		}
		cout<<1<<" "<<2<<endl;
		return;
	}
	ll mx=n-2;
	if(a+b>mx)
	{
		cout<<-1<<endl;
		return;
	}
	ll tot=a+b+1;
	ll lef=n-tot;
	if(a>=b)
	{
		ll st=2;
		rep(i,lef+1)
		{
			cout<<st<<" ";
			st++;
		}
		cout<<1<<" ";
		ll en=n;
		ll beg=st;
		while(en>beg)
		{
			cout<<en<<" "<<beg<<" ";
			en--;
			beg++;
		}
		if(a==b)cout<<en<<" ";

	}
	else
	{
		ll st=lef+1;
		rep(i,lef+1)
		{
			cout<<st<<" ";
			st--;
		}
		ll en=n;
		ll beg=lef+2;
		while(en>beg)
		{
			cout<<en<<" "<<beg<<" ";
			en--;
			beg++;
		}
		cout<<en<<" ";		
	}
	cout<<endl;



	
		
		


}
 
int main()
{
	ll t=1;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{	
		// cout<<t<<endl;
      solve();
	}
	
	
}