#include<bits/stdc++.h>
using namespace std;

/****** Debugging Class *****/
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
__attribute__ ((unused)) int LINE_NUM) { cout << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cout << ", "; else cout << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cout << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.first<<", "<<p.second<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cout<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cout<<a<<' ';__prnt(etc...);}
#ifndef ONLINE_JUDGE
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#define debug2(...) __prnt(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
/**********************************************/

void localMachine(){ 
        #ifdef LOCAL
        freopen("/home/pseudonymous/workspace/cp/input.txt","r",stdin);
        freopen("/home/pseudonymous/workspace/cp/output.txt","w",stdout);
        #endif
}

#define endl '\n'
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size()) 
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,n) for(ll i=0;i<=n;i++)
#define rep3(i,k,n) for(ll i=k;k<n?i<n:i>n;k<n?i++:i--)
#define tr(it,x) for(auto it=x.begin();it!=x.end();it++)
#define print(a) tr(i,a) cout<<i<<" ";cout<<endl;
#define clr(x) memset(x,0,sizeof(x))
#define fill(x,v) fill()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define flush fflush(stdout)
#define precision(x) cout << fixed << setprecision(x)
#define IOS_BASE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

/****** some basic operations *****/
ll gcd(ll a, ll b){return(b?__gcd(a,b):a);} 
ll lcm(ll a, ll b){return(a*(b/gcd(a,b)));}
ll powerMod(ll a,ll b,ll md){return(!b?1:(b&1?a*powerMod(a*a%md,b/2,md)%md:powerMod(a*a%md,b/2,md)%md));}
ll modInv(ll x,ll m){return powerMod(x,m-2,m);} 
/**********************************************/

const int inf=INT_MAX;
const long long INF=9e18;
const int mod=1000000007;
const long double eps=1e-9;

const int N=2e5+5;

void solve()
{
}
int main()
{
        IOS_BASE;
        localMachine();
        int t=1;
        //cin>>t;
        while(t--)
                solve();
        return 0;
}
