#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename U> using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vi;
typedef vector<ll> vll;

#define FOR(i,j,k,in) for(int i=(j); i < (k);i+=in)
#define FORD(i,j,k,in) for(int i=(j); i >=(k);i-=in)
#define REP(i,b) FOR(i,0,b,1)
#define REPD(i,b) FORD(i,b,0,1)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define MANY_TESTS int tcase; cin >> tcase; while(tcase--)

const double EPS = 1e-9;
const int MOD = 1e9+7;
const ll INFF = 1e18;
const int INF = 1e9;
const ld PI = acos((ld)-1);
const vi dy = {1, 0, -1, 0, -1, 1, 1, -1};
const vi dx = {0, 1, 0, -1, -1, 1, -1, 1};

void DBG(){cout << "]" << endl;}
template<typename T, typename ...U> void DBG(const T& head, const U... args){ cout << head << "; "; DBG(args...); }
#define dbg(...) cout << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__);
#define chk() cout << "Check at line(" << __LINE__ << ") hit." << endl;

template<class T, unsigned int U>
ostream& operator<<(ostream& out, const array<T, U> &v){out << "[";  REP(i, U) out << v[i] << ", ";  out << "]"; return out;}
template <class T, class U>
ostream& operator<<(ostream& out, const pair<T, U> &par) {out << "[" << par.first << ";" << par.second << "]"; return out;}
template <class T>
ostream& operator<<(ostream& out, const set<T> &cont) { out << "{"; for( const auto &x:cont) out << x << ", "; out << "}"; return out; }
template <class T, class U>
ostream& operator<<(ostream& out, const map<T, U> &cont) {out << "{"; for( const auto &x:cont) out << x << ", "; out << "}"; return out; }
template<class T>
ostream& operator<<(ostream& out, const vector<T> &v){ out << "[";  REP(i, v.size()) out << v[i] << ", ";  out << "]"; return out;}

template<class T>
istream& operator>>(istream& in, vector<T> &v){ for(auto &x : v) in >> x; return in; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int mod = (int)998244353;
struct Mint{
    int val;
    Mint(){ val = 0; }
    Mint(long long v){
        val = (-mod <= v && v < mod) ? v : v%mod;
        if(val < 0) val+= mod;
    }
    // operators
    Mint operator-(){return Mint(-val);}
    Mint& operator+=(const Mint& other){ val+=other.val; if(val >= mod) val-=mod; return *this;}
    Mint& operator-=(const Mint& other){ val-=other.val; if(val < 0) val+=mod; return *this;}
    Mint& operator*=(const Mint& other){ val=((long long)val*other.val)%mod; return *this;}
    friend Mint binpow(Mint a, long long p){
        Mint res(1);
        while(p > 0){
            if(p&1) res*=a; a*=a; p>>=1;
        }
        return res;
    }
    friend Mint inv(Mint a){ return binpow(a, mod-2); }
    Mint& operator/=(const Mint &other){ return (*this)*=inv(other);}

    friend Mint operator+(Mint a, const Mint& b){ return a+=b; }
    friend Mint operator-(Mint a, const Mint& b){ return a-=b; }
    friend Mint operator*(Mint a, const Mint& b){ return a*=b; }
    friend Mint operator/(Mint a, const Mint& b){ return a/=b; }

    bool operator==(const Mint &other){return val == other.val;}
    bool operator!=(const Mint &other){return val != other.val;}
    bool operator<(const Mint &other){return val < other.val;}
    // io
    friend ostream& operator<<(ostream &out, Mint &a){ return out << a.val; }
};
int main(){
 	ios_base::sync_with_stdio(false);
 	cin.tie(NULL); cout.tie(NULL);
 	const int mx = (int)3e5;
 	vector<Mint> fact(mx);
 	fact[0] = Mint(1);
 	FOR(i, 1, mx, 1){
 	    fact[i] = fact[i - 1] * Mint(i);
 	}
    auto ncr = [&](int n, int r){
 	    if(n < 0) return Mint(0);
 	    if(r > n) return Mint(0);
 	    if(r < 0) return Mint(0);
        return (fact[n] / fact[r]) / fact[n - r];
    };
    int n; cin >> n;
    int lw = 0, lb = 0;
    int rw = 0, rb = 0;
    bool nonefull = true;
    int fbw = 0, fwb = 0;
    REP(i, n){
        string s; cin >> s;
        if(s[0] == 'W')
            lw++;
        else if(s[0] == 'B')
            lb++;
        if(s[1] == 'W')
            rw++;
        else if(s[1] == 'B')
            rb++;
        if(s == "BB" || s == "WW")
            nonefull = false;
        if(s == "B?" || s == "?W"){
            fbw++;
        }
        else if(s == "?B" || s == "W?"){
            fwb++;
        }
    }
    Mint ans(0);
    FOR(left_black, 0, n + 1, 1) {
        Mint left_ways = ncr(n - lb - lw, left_black - lb);
        int right_white = left_black;
        Mint right_ways = ncr(n - rw - rb ,right_white - rw);
        ans += (left_ways * right_ways);
    }
    // all, now sub ones containing at least one pair of wb, bw and there is no full
    // that's equal to all, where there is no full - those which are only wb wb wb or bw bw bw
    if(nonefull){
        Mint _all(1);
        _all *= binpow(Mint(2), n - fbw - fwb);
        Mint sub(0);
        if(fwb == 0)
            sub += Mint(1);
        if(fbw == 0){
            sub += Mint(1);
        }
        _all -= sub;
        ans -= _all;
    }
    cout << ans.val << "\n";

    return 0;
}