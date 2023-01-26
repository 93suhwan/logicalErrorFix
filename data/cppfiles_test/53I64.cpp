#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
 
#include <bits/stdc++.h>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define int         long long
#define ll          long long
#define ld	    long double
#define pb          push_back
#define pp	    pop_back()
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define mp          make_pair
#define fi           first
#define se           second
#define sz(x)       (ll)x.size()
#define fl(i,a,n)         for(ll i=a;i<n;i++)
#define bl(i,a,n)     for(ll i=n-1;i>=a;i--)
#define GCD(m,n) __gcd(m,n)


signed main()
{ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
	ll t;cin>>t;
	while(t--)
	{
		ll n,k,b=0;
		cin>>n>>k;
		ll a[n];
		fl(i,0,n)cin>>a[i];
		fl(i,1,n)
		{
			if(a[i]<a[i-1])b++;
		}
		b=b+1;
		if(b>k)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}

return 0;
}