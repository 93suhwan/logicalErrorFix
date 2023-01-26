#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
# define ll long long            
#define inf             1e18
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 const int mod=1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int main() 
{
	
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll t;
	cin>>t;
	while(t--)
	{
      ll n,f=2;
      cin>>n;
      ll ans=2*n;
      for(ll i=3;i<=ans;i++)
      {
        f*=i;
        f%=mod;
      }
      cout<<f/2<<"\n";
    }
	return 0;
}
