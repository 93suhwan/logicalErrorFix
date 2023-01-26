#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vt vector<ll>
#define vvt vector<vt>
#define vvvt vector<vvt>
#define all(c) (c).begin(), (c).end()
#define rep(i, start, end) for(ll i=start; i<=end; i++)
#define sd(x) scanf("%lld", &x)

using namespace __gnu_pbds;
using namespace std;
template<class T>void read(vector<T> &a){for(ll i=0;i<a.size();i++)cin>>a[i];}
typedef
tree<
  pair<ll,ll>,
  null_type,
  less<pair<ll,ll>>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;


void solve(){
	ll n;
	cin>>n;

	vt a(n);
	read(a);
	
	int ans = 0;
	ordered_set m;
	map<ll,ll>count;
	m.insert({a[0], 0});
	count[a[0]]++;
	for(int i=1;i<n;i++){
		int cur = a[i];
		int less = m.order_of_key({cur,-1});
		int great = i - less - count[cur];
		ans+=min(less, great);
		m.insert({cur,i});
		count[cur]++;
	}

	cout<<ans<<endl;

}
int main(){
	ll t;
	cin>>t;
	
	for(int i=1;i<=t;i++){		
		solve();
	}
}