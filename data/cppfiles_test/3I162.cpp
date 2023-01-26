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
string s;
int dp[10][2][25][10];
int f(int i, int started,int mod, int x) {
	if(i==s.size()) {
		if(mod==0) return 1;
		return 0;
	} 
	if(dp[i][started][mod][x]!=-1) return dp[i][started][mod][x];
	if(s[i]=='X') {
		if(i==0 and x==0) return 0;
		return dp[i][started][mod][x]=f(i+1,1,(mod*10+x)%25,x);
	}
	else if(s[i]!='_') return dp[i][started][mod][x]=f(i+1,1,(mod*10+s[i]-'0')%25,x);
	int ans=0;
	for(int j=1-started;j<=9;j++) {
		ans+=f(i+1,1,(mod*10+j)%25,x);
	}
	return dp[i][started][mod][x]=ans;
}
void solve(int tc) {
	cin>>s;
	if(s=="_" or s=="X") {cout<<1<<endl; return;}
	if(s[0]=='0') { if(s=="0") cout<<1<<endl; else cout<<0<<endl; return; }
	int ans=0;
	for(int i=0;i<=9;i++) {
		memset(dp,-1,sizeof dp);
		ans=max(ans,f(0,0,0,i));
	} 
	cout<<ans<<endl;
}

int32_t main() {
	fastio
	int T=1;
	//cin>>T;
	for(int t=1;t<=T;t++) solve(t);
	return 0;
}
//tag and rating