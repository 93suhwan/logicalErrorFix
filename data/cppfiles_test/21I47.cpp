#include<bits/stdc++.h>
#include<bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_pbds;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t){
	while(*sdbg != ',') { cerr<<*sdbg++; } cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr<<#x<<": "; for(auto i:x) cerr<<i<<" "; cerr<<endl;}}
#define debugr(l,r,x) {{cerr<<#x<<": "; for(int i=l;i<=r;i++) cerr<<x<<" "; cerr<<endl;}}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define debugr(l,r,x)
#define cerr while(0) cerr
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
typedef __int128 INT;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define priority_queue std::priority_queue
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(x,l,r) for(auto x=l; x<r; x++)
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int dp[105][105][105];
int choose[105][105];
int fac[105];
int MOD;

int solve(int n, int m, int k){
	if(dp[n][m][k]!=-1) return dp[n][m][k];
	if(n==0) return k==0;
	if(k==0 && m==0) return fac[n];
	if(m==0) return 0;
	dp[n][m][k]=0;
	int l=k;
	if(m==1) l--;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=l && j<=i && l-j<=n-i; j++){
			dp[n][m][k] += ((solve(i-1, m-1, j) * solve(n-i, m-1, l-j))%MOD * choose[n-1][i-1])%MOD;
			dp[n][m][k] %= MOD;
		}
	}
	return dp[n][m][k];
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin>>n>>m>>k>>MOD;
	choose[0][0]=1;
	fac[0]=1;
	for(int i=1; i<105; i++){
		fac[i]=(fac[i-1]*i)%MOD;
		choose[i][0]=1;
		for(int j=1; j<=i; j++){
			choose[i][j]=(choose[i-1][j-1]+choose[i-1][j])%MOD;
		}
	}
	memset(dp, -1, sizeof dp);
	cout<<solve(n, m, k)<<endl;
}