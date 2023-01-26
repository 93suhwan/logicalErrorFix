#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less 
using namespace __gnu_pbds; 
#define _USE_MATH_DEFINES
 
using namespace std;
#define ll long long int
#define pll pair<ll,ll>
typedef tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> 
    ordered_set; 
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
#define hell 998244353
// #define sz(x) (ll)x.size()
#define pii pair<int,int>
const long long N=1e9;
const long long NN=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
const int sqt=sqrt(1e9+1)+10;
#define LCM(m,n) m*(n/__gcd(m,n))
#define N1 1000000
#define N2 1000000000
#define vvll vector <vector <ll> >
#define vll  vector <ll>



void solve()
{
	ll n,m;
	cin>>n>>m;
	vll v(n+1,0);
	rep(i,m)
	{
		ll u,c;
		cin>>u>>c;
		ll k;
		cin>>k;
		v[k]=1;
	}
	ll index=-1;
	rep1(i,n+1)
	{
		if(!v[i])
		{
			index=i;
			break;
		}
	}
	rep1(i,n+1)
	{
		if(i!=index)
		{
			cout<<i<<" "<<index<<endl;
		}

	}
	



	
	
 
	
	
 
 
	
	
 
}
 
int main()
{
	ll t=1;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	// cout<<t<<endl;
	while(t--)
	{	
		// cout<<t<<endl;
      solve();
	}
	
	
}