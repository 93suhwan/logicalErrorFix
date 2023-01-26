/*
  　　　　　／＞　 フ                 
  　　　　　| 　_　 _|               
  　 　　　／`ミ _x 彡               
  　　 　 /　　　 　 |                  
  　　　 /　  ヽ　　 ?                      
  　／￣|　　 |　|　|
  　| (￣ヽ＿_ヽ_)_)
  　＼二つ
 
 */  
#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef long double ld;
typedef int64_t ll;
// typedef __int128_t lll;
typedef uint64_t ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<pair<ll,ll>> vpll;
typedef pair<ll,ll> pll;
typedef vector<vector<ll>> vvll;
typedef set<ll> sll;
typedef set<ll,greater<ll>> sllg;
typedef multiset<ll> msll;
typedef multiset<ll,greater<ll>> msllg;
typedef unordered_set<ll> usll;
typedef map<ll,ll> mll;
typedef map<ll,ll,greater<ll>> mllg;
typedef unordered_map<ll,ll> umll;
typedef multimap<ll,ll> mmll;
typedef multimap<ll,ll,greater<ll>>mmllg;
typedef vvll Tree;

#define fio ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define ff first
#define ss second
#define nl "\n"
#define yes "yes"
#define no "no"
#define YES "YES"
#define NO "NO"
#define Yes "Yes"
#define No "No"
#define gp " "
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ub upper_bound
#define lb lower_bound

#define uid(a,b) uniform_int_distribution<long long>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define rep(i,x,a) for(ll i=x;i<a;i++)
#define per(i,x,a) for(ll i=a-1;i>=x;i--)

#define v1n(a, n) vector<ll> a(n); rep(i,0,n) cin >> a[i]
#define v2n(a, b, n, m) vector<ll> a(n),b(m); rep(i,0,n) cin >> a[i]; rep(i,0,m) cin >> b[i];
#define vpn(a, n) vpll a(n); rep(i,0,n) cin >> a[i].ff>>a[i].ss
#define mln(a, n, m) vector< vector<ll> > a(n,vl(m)); rep(i,0,n) rep(j,0,m) cin >> a[i][j]
#define str(s) string s; cin>>s;

// typedef variant<ld,ll,ull,int,char,float,double,string,bool> var;
// typedef vector<var> vp;
#define pv(a,b) rep(_,0,a.size()-1)cout<<a[_]<<b;cout<<a.back();cout<<nl;

const ll mod1 = 1000000007;
const ll mod2 = 998244353;
const unsigned int ev=0xAAAAAAAA;
//0xAAAAAAAA means 10101010101010101010101010101010 in binary.
//we get all even bits of n.
const unsigned int od=0x55555555;
//0x55555555 means 01010101010101010101010101010101 in binary.
//we get all odd bits of n.

#define i1(a) ll a;cin>>a;
#define i2(a,b) ll a,b;cin>>a>>b;
#define i3(a,b,c) ll a,b,c;cin>>a>>b>>c;
#define i4(a,b,c,d) ll a,b,c,d;cin>>a>>b>>c>>d;
#define i5(a,b,c,d,e) ll a,b,c,d,e;cin>>a>>b>>c>>d>>e;

#warning do all bitwise ops with 1ll to avoid overflow.

//debug starts
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr <<"\033[32m"<< ""<<__func__<<":"<<__LINE__<<" ["<< #x << "] = ["; _print(x); cerr <<"\033[0m"<< "" << nl;
#else
#define dbg(x...)
#endif
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
// void __print(__int128_t x) {cerr << x;}
// void __print(__uint128_t x) {cerr << x;}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
//debug ends

bool comp(const pair<ll,ll> &a,const pair<ll,ll> &b){return ((a.ss==b.ss)?(a.ff<b.ff):(a.ss<b.ss));}
template<typename T> T gcd(T a,T b){return __gcd((ull)a,(ull)b);}
template<typename T> T lcm(T a,T b){if(a==0&&b==0)return -1; return (a/gcd(a,b))*b;}
template<typename T> T nc2(T n){if(n<2)return 0; return n*(n-1)/2;}
template<typename T> T nc3(T n){if(n<3) return 0; return n*(n-1)/2*(n-2)/3;}

ll add(ll x, ll y,ll mod){x += y;if (x >= mod)return x - mod;return x;}
ll sub(ll x, ll y,ll mod){x -= y;if (x < 0)return x + mod;return x;}
ll mul(ll x, ll y,ll mod){return (x * 1LL * y) % mod;}

void gentree(ll n){
    vpll edges;
    rep(i,2,n+1)edges.pb({uid(1,i-1), i});
    vl perm(n + 1);
    rep(i,1,n+1)perm[i] = i;
    shuffle(perm.begin() + 1, perm.end(),rng);
    shuffle(edges.begin(), edges.end(),rng); // random order of edges
    for(auto edge : edges) {
        int a = edge.first, b = edge.second;
        if(uid(0,1))swap(a, b); // random order of two vertices
        cout<<perm[a]<<gp<<perm[b]<<nl;
    }
}

void precomp()
{    
}

void solve()
{
    i1(n);
    v1n(a,n);
    vl ans(3,0);
    ll ch1=0,ch2=0;
    rep(i,0,n){
        ans[0]=max(ans[0],(ll)(a[i]%3==1));
        ans[1]=max(ans[1],(ll)(a[i]%3==2));
        ans[2]=max(ans[2],(ll)ceil((ld)(a[i]/3)));
    }
    ll fin=ans[0]+ans[1]+ans[2];
    if(a.back()%3!=2){
        if(find(all(a),1)==a.end() && ans[0]==1 && ans[1]==1 && a.back()%3==1 && find(all(a),a.back()-1)==a.end()){
            fin--;
        }
        else if(a.back()%3==0 && ans[0]>0 && ans[1]>0){
            fin--;
        }
    }
    dbg(ans);
    cout<<fin<<nl;
}

int main()
{
    clock_t start,end; start=clock(); fio;
    cout<<fixed<<setprecision(20);
    cerr<<fixed<<setprecision(10);
    ll tc=1;
    cin>>tc;
    precomp();
    while(tc--){
        solve();
    } 
    end=clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    cerr <<"\033[35m"<< "Time taken by program is : "<< time_taken*1000<< " ms" <<"\033[0m"<< endl;  
}
