#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll N=1e6+1;
const ll INF=2e14+10;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	int in=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i and a[i] == 1 and a[i-1] == 0) in = i;
		if(i==n-1 and a[i] == 0) in = i+1;
	}
	if(in == -1){
		cout<<"-1\n";
		return;
	}
	if(in == n){
		for(int i=1;i<=n+1;i++) cout<<i<<' ';
		cout<<'\n';
		return;
	}
	for(int i=1;i<=in;i++) cout<<i<<' ';
	cout<<n+1<<' ';
	for(int i=in+1;i<=n;i++) cout<<i<<' ';
	cout<<'\n';
}

int main(){	
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout<<fixed<<setprecision(12);
	int T=1;
	cin>>T;
	while(T--) solve();
}