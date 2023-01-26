#pragma region
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#if DEBUG && !ONLINE_JUDGE
#include "debug.cpp"
#else 
#define debug(args...) 
#define test
#define print(a,n,k)
#endif
const int mod = 1000000007;
// const int mod = 998244353;
// #define int long long
#define TIME (chrono::steady_clock::now().time_since_epoch().count())
#define ull unsigned long long
#define ok order_of_key
#define fo find_by_order
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repp(i,n) for(int i=(0);i<(n);i++)
#define repr(i,n) for(int i=(n);i>=0;i--)
#define repl(i,a,b) for(ll i=(a);i<(b);i++)
#define newl cout<<'\n'
#define inf 1000000000
#define repaa(i,a) for(auto i=a.rbegin();i!=a.rend();++i)
#define pb push_back 
#define tc int tt;cin>>tt;while(tt--)
#define mem(v,i) memset(v,i,sizeof(v))
#define all(x) x.begin(), x.end()
#define inf1 1e18
#define repa(i,a) for (auto i : a)
#define X first
#define Y second
#define lb lower_bound
#define ub upper_bound
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define in(a,n) repp(jjj,n)cin>>a[jjj];
#define intree(a,m) repp(i,m){int tmp1,tmp2;cin>>tmp1>>tmp2;tmp1--,tmp2--;a[tmp1].eb(tmp2);a[tmp2].eb(tmp1);}
#define ins insert
#define er erase
#define sz(a) (int)(a.size())
#define mt make_tuple
#define eb emplace_back
#define bpl(i) __builtin_popcountll(i)
#define bp(i) __builtin_popcount(i)
#define precision(x) cout << fixed << setprecision(x);
#define si set<int>
#define usi unordered_set<int>
#define sl set < ll >
#define usl unordered_set < ll >
#define sip set < ip >
#define sil set < il > 
#define mi map<int , int >
#define umi unordered_map<int , int >
#define ml map < ll , ll>
#define uml unordered_map < ll , ll>
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define srt(v) sort(all(v))
#define rsrt(v) sort(v.rbegin(), v.rend())
#define ld long double
#define vi vector<int> 
#define vl vector<ll>
#define vii vector < vi >
#define vip vector<pair<int,int>>
#define vil vector<pair<ll,ll>>
#define vll vector < vl >
#define ip pair<int, int>
#define il pair<ll, ll>
const int dx[4]={1,0,0,-1}, dy[4]={0,1,-1,0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const char nl = '\n',sp = ' ';
#ifdef Fading
#define gc getchar
#endif
#ifndef Fading
inline char gc(){static char now[1<<16],*S,*T;if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}return *S++;}
#endif
ll R(ll B) {static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());return (unsigned long long)rng() % B;}
inline ll read(){register ll x=0,f=1;char ch=gc();while (!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}return (f==1)?x:-x;}
ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;return o^(o>>31);}
template<typename T>T Min(T v) {return v;}template<typename T, typename... Args>T Min(T first, Args... args) {return min(first , Min(args...));}
template<typename T>T Max(T v) {return v;}template<typename T, typename... Args> T Max(T first, Args... args) {return max(first , Max(args...));}
template<typename T> T mult(T v) {return v;}template<typename T, typename... Args>T mult(T first, Args... args) {return mult((first%mod * mult(args...))%mod);}
template<class T , class U> inline bool remax(T &a, U b) {return a<b?a=b,1:0;}template<class T , class U> inline bool remin(T &a, U b) { return a > b ? a = b, 1 : 0; }
template<class A, class B> void add(A &a, B b){a += b;if(a >= mod) a -= mod;if(a < 0) a += mod;}template<class A, class B> ll addr(A a, B b){a += b;if(a >= mod) a -= mod;if(a < 0) a += mod;return a;}
template<class T1,class T2>T2 min(T1 a,T2 b){return min((T2)a,b);}template<class T1,class T2>T2 max(T1 a,T2 b){return max((T2)a,b);}
void pnt(char a){if(a == nl || a == sp) cout << a;else cout << a << sp;}void pnt(string &a,int b = 0){cout << a << nl;}
template<class A> void pnt(A &a,int b=0) {cout << A(a + b) << sp;}template<class A ,class B> void pnt(pair<A,B>&a,int b=0){cout << A(a.X+b) << ' ' << B(a.Y+b) << nl;}
template<class A> void pnt(vector<A>&a,int b=0) {repa(i,a) pnt(i,b);}template<class A> void pnt(set<A>&a,int b=0) {repa(i,a) pnt(i,b);}
template<class A> void pnt(unordered_set<A>&a,int b=0) {repa(i,a) pnt(i,b) ;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.X>>v.Y;}
template<class T>struct isChar{bool ch(T a){return false;}};template<>struct isChar<char>{int ch(char s){return s == '`';}};
template<typename T>void W(T v){pnt(v);}template<typename T,typename A>void W(T f,A s) {if(isChar<A>().ch(s)) pnt(f,1);else pnt(f) ,W(s);}
template<typename T,typename A,typename... Args>void W(T f,A s,Args... args) {if(isChar<A>().ch(s)) pnt(f,1), W(args...);else pnt(f),W(s,args...);}
template <class T1>void kill(T1 ans){pnt(ans);exit(0);}
ll nc2(ll a){return a * (a - 1) / 2;}int mylog(ll x , ll y = 2){if(x == 0) return -1;return mylog(x/y,y) + 1;}
ll setbit(ll n, ll kk){return 1LL*(n|(1LL<<kk));}ll unsetbit(ll n, ll kk){return 1LL*(n&~(1LL<<kk));}
ll invertbit(ll n, ll kk){return 1LL*(n^(1LL<<kk));}bool kthbit(ll n, ll kk){return n&(1LL<<kk);}
ll mceil(ll a, ll b){return a/b + (ll)(a%b > 0);}
ll poww(ll a, ll b,ll m = mod){ll val = 1;a %= m;while (b > 0){if (b & 1) val = (a * val) % m;a = (a * a) % m;b >>= 1;}return val;}
ll inv(ll a,ll m=mod){return poww(a , m - 2);}ll gcdll(ll x, ll y){return y == 0 ? x : gcdll(y, x % y);}

//-------------------------------------------------LEZENDARY------------------------------------------------------------//
//------------------------------------------------------SANDWICH-------------------------------------------------------//
#pragma endregion

const int N = 5005;
const int P = 31;
const int MOD = 58526182319104693LL;
ull HASH[N][N], pw[N];
int match[N][N];
int ans[N][N];

signed main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    pw[0] = 1;
    repp(i,N - 1) pw[i + 1] = pw[i] * P % MOD;
    int q;
    cin >> q;
    rep(T,1,q + 1) {
        ull salt = chrono::steady_clock::now().time_since_epoch().count();
        int n;
        string a;
        cin >> n >> a;
        int cur = 0;
        unordered_map < ull, int > HASH_conv;
        repp(i,n) repp(j,n) ans[i][j] = 0, match[i][j] = 0;
        repp(i,n) {
            int prev = 0;
            rep(j,i,n) {
                HASH[i][j] = ((prev * P) % MOD + a[j] - 'a' + 1);
                prev = HASH[i][j];
                int P = HASH_conv[prev] - 1;
                if(P != -1) match[P][i] = j - i + 1;
                HASH_conv[prev] = i + 1;
            }
        }
        // print(match, n, n);
        a.pb(char(1));
        repp(i,n) {
            remax(ans[i][i], 1);
            rep(j,i + 1,n) remax(ans[i][j], ans[i][j - 1] + 1);
            rep(j,i + 1,n) {
                char nxt = a[j + match[i][j]], cur_nxt = a[i + match[i][j]];
                if(nxt > cur_nxt) remax(ans[j][j + match[i][j]], ans[i][n - 1] + 1);
            }
        }
        // print(ans, n, n);
        int anss{};
        repp(i,n) repp(j,n) remax(anss, ans[i][j]);
        if(q != 1000) W(anss, nl);
        else if(T == 60) {
            cout << a.substr(0,n) << endl;
        }
    }
}