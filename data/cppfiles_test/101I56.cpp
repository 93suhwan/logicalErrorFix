#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int 
#define vi vector <long long int >
#define pii pair<long long int, long long int>
#define pb push_back
#define pf push_front
#define mod 1000000007
#define ff fflush()
#define mp make_pair
#define vvi vector<vector<ll>> 
#define vvpii vector<vector<pair<long long int , long long int >>>
#define vpii vector <pair<long long int , long long int>>

ll const mn = 1e6+2;
ll a[mn],b[mn];
bool comp(const pii a , const pii b){
	if(a.second!=b.second){
		return a.second<b.second;
	}
	else 
		return a.first<b.first;
}

void test_case(){
	ll n,m,k;
	cin>>n>>m>>k;
	vi v,h;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x; v.pb(x);
	}
	for(ll i=0;i<m;i++){
		ll x;
		cin>>x; h.pb(x);
	}
	vpii p;
	for(ll i=0;i<k;i++){
		ll x,y;
		cin>>x>>y;
		p.pb(mp(x,y));
	}
	sort(p.begin(),p.end(),comp);
	vi l,r;
	for(ll i=0;i<k;i++){
		l.pb(p[i].first); r.pb(p[i].second);
	}
	for(ll i=0;i<m;i++){
		a[i] = 0;
		b[i] = 0;
	}
	for(ll i=0;i<k;i++){
		ll y = lower_bound(r.begin(),r.end(),r[i]+1)-r.begin();
		ll x  = lower_bound(v.begin(),v.end(),l[i])-v.begin();
		if(v[x]==l[i])
			continue;
		ll j = i;
		while(j<y && l[j]<v[x]){
			j++;
		}
		a[x-1]+=j-i;
		b[x-1]+= (j-i)*(j-i);
		i = j-1;
	}
	for(ll i=0;i<k;i++){
		swap(p[i].first,p[i].second);
	}
	sort(p.begin(),p.end(),comp);
	for(ll i=0;i<k;i++){
		l[i] = p[i].first;
		r[i] = p[i].second;
	}
	ll ans = 0;
	for(ll i=0;i<n;i++){
		ans += a[i]*a[i] - b[i];
		a[i] = 0; b[i] = 0;
	}
	for(ll i=0;i<k;i++){
		ll y = lower_bound(r.begin(),r.end(),r[i]+1)-r.begin();
		ll x  = lower_bound(h.begin(),h.end(),l[i])-h.begin();
		if(h[x]==l[i])
			continue;
		ll j = i;
		while(j<y && l[j]<h[x]){
			j++;
		}
		a[x-1]+=j-i;
		b[x-1]+= (j-i)*(j-i);
		i = j-1;
	}
	for(ll i=0;i<m;i++){
		ans += a[i]*a[i] - b[i];
	}
	ans/=2;
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
 	ll t;
 	cin>>t;
 	while(t--){
 		test_case();
 	}	
 	return 0;
}