/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define ll long long
#define ld long double
#define gap ' '
#define endl '\n'
#define mod 1000000007
#define pii pair<int,int>
#define vi vector<int> 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update>
ordered_set; //find_by_order(k)=kth largest,order_of_key()->number of items strictly smaller
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l,int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
int n,k,x;
string s;
void solve(int tc) {
	cin>>n>>k>>x;
	cin>>s;
	int cnt = 0;
	vector<int> v;
	for(int i=0;i<n;i++) {
		if(s[i] == 'a') { if(cnt) v.push_back(cnt), cnt = 0; }
		else cnt+=k;
	}
	if(cnt) v.push_back(cnt);
	v.push_back(0);
	for(int &x: v) x++;
	vector<int> p(v.begin(), v.end()), q(p.size()+1, 0);
	for(int i=(int)p.size()-2;i>=0;i--) p[i]*=p[i+1];
	x--;
	for(int i=0;i<v.size()-1;i++) {
		q[i] = x/v[i+1];
		x -= (x/v[i+1]) * v[i+1];
	}
	int j=0;
	cnt = 0;
	for(int i=0;i<n;i++) {
		if(s[i] == 'a') {
			if(cnt) { while(q[j]--) cout << 'b'; j++; cnt = 0;}
			cout << 'a';
		}
		else cnt+=k;
	}
	if(cnt) { while(q[j]--) cout << 'b'; j++; cnt = 0;}
	cout<<endl;
}

int32_t main() {
	fastio
	int T=1;
	cin>>T;
	for(int t=1;t<=T;t++) solve(t);
	return 0;
}
//tag and rating