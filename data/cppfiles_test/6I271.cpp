// Problem: C. Web of Lies
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define XOX
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

#define int long long
#define re return
#define beg() begin()
#define cont continue
#define ldb long double
#define db double

#define br break
#define fr first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mkp make_pair

#define pi pair<int,int>
#define pll pair<ll,ll>
#define pdb pair<db,db>
#define pldb pair<ldb,ldb>

#define vi vector<int>
#define vll vector<ll>
#define vdb vector<db>
#define vldb vector<ldb>
#define vpi vector< pi >
#define vpll vector< pll >

#define mi map<int,int>
#define mdb map<db,db>
#define mldb map<ldb,ldb>

#define si set<int>
#define sdb set<db>
#define sldb set<ldb>

#define test int t; cin>>t; while(t--)
#define scan() int n; cin>>n; int a[n]; for(int i=0;i<n;i++) cin>>a[i]
#define scan2() int n,k; cin>>n>>k; int a[n]; for(int i=0;i<n;i++) cin>>a[i]
#define print(a,n) for(int i=0;i<n;i++) cout<<a[i]<<' '
#define mem(a,v) memset(a,v,sizeof(a))
#define srt(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define cn(x) cout<<x<<"\n"
#define cs(x) cout<<x<<" "
#define c(x) cout<<x
#define all(v) v.begin(),v.end()

#define forr(i,a,b) for (int i = (a); i < (b); ++i)
#define rrof(i,a,b) for (int i = (b)-1; i >= (a); --i)


const int MOD = 1e9+7;
const ldb PI = 4*atan((ldb)1);
const int INF = 1e18;
const int NINF = -1e18;

int get_hash(string s){
	int N=1000001;
	int base[N],A=11,MD=1110111110111;
	base[0]=1;

	forr(i,1,N)
	base[i]=(base[i-1]*A)%MD;

	int hs=0;
	forr(i,0,s.size()){
		hs+=(s[i]*base[i]);
		hs%=MD;
	}

	re hs;
}

int power(int a,int n){
	int res=1;

	while(n){
		if(n%2)
		res*=a;
		a*=a;
		n/=2;
	}

	return res;
}

vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
	vector<string> __attribute__ ((unused)) args,
	__attribute__ ((unused)) int idx,
	__attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
	template <typename Head, typename... Tail>
	void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif


int32_t main(){
	fast;
	
	int n,m;
	cin>>n>>m;
	
	int cnt[n+1]={0};
	int big[n+1]={0};
	
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		
		if(x>y)
		swap(x,y);
		
		cnt[x]++;
		cnt[y]++;
		
		big[x]++;
	}
	
	set<int>ans;
	
	for(int i=1;i<=n;i++){
		if(big[i]==0 && cnt[i]!=0)
		ans.insert(i);
	}

	int q;
	cin>>q;
	
	while(q--){
		int a;
		cin>>a;
		
		if(a!=3){
			int x,y;
			cin>>x>>y;
			
			if(x>y)
			swap(x,y);
			
			if(a==1){
				cnt[x]++;
				cnt[y]++;
				
				big[x]++;
				
				if(ans.find(x)!=ans.end())
				ans.erase(x);
			}
			
			else{
				cnt[x]--;
				cnt[y]--;
				
				big[x]--;
				
				if(cnt[x]!=0 && big[x]==0)
				ans.insert(x);
			}
		}
		
		else
		cn(ans.size());
	}
		
	re 0;
}