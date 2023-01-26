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
//#define int long long
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

void solve(){
	int n;
	string s;
	cin>>n>>s;
	int idx;
	bool good=false;
	for(int i=0; i<n; i++){
		good |= s[i]=='0';
		if(s[i]=='0') idx=i;
	}
	idx++;
	if(good){
		if(idx>n/2){
			cout<<"1 "<<idx+1<<" 1 "<<idx<<"\n";
		}
		else{
			cout<<idx<<" "<<n<<" "<<idx+1<<" "<<n<<"\n";
		}
	}
	else{
		cout<<"1 "<<n-1<<" 2 "<<n<<"\n";
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}