// time-limit: 3000
// problem-url: https://codeforces.com/contest/1574/problem/D
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define DEBUGMODE 1
#ifdef ONLINE_JUDGE
#define DEBUGMODE 0
#endif

#define cerr if(DEBUGMODE) cerr
#define DEBUG(a) if(DEBUGMODE) cout<<(a)<<endl
#define REP(i,n) for(int i=0; i<(n); i++)
#define REPR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define EACH(i,c) for(auto (i):c)
#define endl '\n'
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define LLM LONG_LONG_MAX
#define gcd __gcd
#define pb push_back
#define MANY_TESTS ll ntests; cin>>ntests; for(ll test=1; test<=ntests; test++) 
#define contains(a,b) ((a).find(b)!=(a).end())
#define INF 1e16
#define NINF -1e16
#define cinv(n,v) ll n; cin>>n; vl v(n); cin>>v;
#define fact(f,n) vl f={0}; for(ll i=0; i<n; i++) f.push_back(f[i]*(i+1));
#define codejamout(s) cout<<"Case #"<<test<<": "<<s<<"\n";
#define LOG(x) cerr<<"Line "<<__LINE__<<":"<<#x<<" = "<<x<<endl;


typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pair<ll,ll>> vpll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll MOD=1e9+7;

template <class T, class U>
ostream& operator<<(ostream& out, const pair<T, U> &par) {out << "(" << par.first << ";" << par.second << ")"; return out;}
template <class T>
ostream& operator<<(ostream& out, const set<T> &cont) { out << "{"; for( const auto &x:cont) out << x << ", "; out << "}"; return out; }
template <class T, class U>
ostream& operator<<(ostream& out, const map<T, U> &cont) {out << "{"; for( const auto &x:cont) out << x << ", "; out << "}"; return out; }
template<class T>
ostream& operator<<(ostream& out, const vector<T> &v){ out << "[";  REP(i, v.size()) out << v[i] << ", ";  out << "]"; return out;}
// istreams
template<class T>
istream& operator>>(istream& in, vector<T> &v){ for(auto &x : v) in >> x; return in; }
template<class T, class U>
istream& operator>>(istream& in, pair<T, U> &p){ in >> p.ff >> p.ss; return in; }

template<typename T>
pair<T, ll> get_min(vector<T> &v){ typename vector<T> :: iterator it = min_element(v.begin(), v.end()); return {*it, it - v.begin()};}
template<typename T>
pair<T, ll> get_max(vector<T> &v){ typename vector<T> :: iterator it = max_element(v.begin(), v.end()); return {*it, it - v.begin()};}        
template<class T>
bool remin(T& a, const T& b){return (b<a?a=b,1:0);}
template<class T>
bool remax(T& a, const T& b){return (a<b?a=b,1:0);}

template<typename T, typename U>
T bsl(T lo, T hi, U f){ hi++; T mid; while(lo < hi){ mid = (lo + hi)/2; f(mid) ? hi = mid : lo = mid+1; } return lo; }
template<typename T, typename U>
T bsh(T lo, T hi, U f){ lo--; T mid; while(lo < hi){ mid = (lo + hi + 1)/2; f(mid) ? lo = mid : hi = mid-1; } return lo; }

ll ipow(ll b, ll p, ll m=LONG_LONG_MAX){
    ll res=1;
    while(p){
        if(p & 1) res=res*b%m;
        p>>=1;
        b=b*b%m;
    }
    return res;
}
ll getbit(ll number, ll index){return (number & (1<<index))<<index;}
ll modinv(ll number, ll mod=MOD){return ipow(number, mod-2, mod);}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll n;
    cin>>n;

    vvl v(n);
    REP(i,n){
        ll x;
        cin>>x;
        v[i].resize(x);
        cin>>v[i];
    }

    ll m;
    cin>>m;
    set<vector<ll>> banned;
    
    REP(i,m){
        vl t(n);
        cin>>t;
        banned.emplace(t);
    }

    vl tres;
    EACH(i,v) tres.pb(i.size());
    if(!contains(banned, tres)){
        REP(i,n){
            cout<<tres[i]<<" \n"[i==n-1];
        }
        return 0;
    }

    auto cnt=[&](vl t){
        ll res=0;
        REP(i,n){
            res+=v[i][t[i]-1];
        }
        cout<<t<<res<<endl;
        return res;
    };

    ll tx=0;

    EACH(i,banned){
        REP(j,n){
            if(i[j]!=1){
                vl tv=i;
                tv[j]--;
                if(!contains(banned,tv) && remax(tx,cnt(tv))){
                    tres=tv;
                }
            }
        }
    }

    REP(i,n){
        cout<<tres[i]<<" \n"[i==n-1];
    }

    return 0;
}

