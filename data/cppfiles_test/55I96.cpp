#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vpl = vector<pl>;

template<class T> using V = vector<T>;
template<class T, size_t SZ> using AR = array<T,SZ>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

#define f first
#define s second
#define ft front()
#define bk back()
#define ins insert
#define rsz resize
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) int(size(x))
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)
#define each(i,x) for (auto& i: x)

void setIO(string S = "") {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    if (sz(S)) {
        freopen((S+".in").c_str(),"r",stdin);
        freopen((S+".out").c_str(),"w",stdout);
    }
}

template<class T> bool umin(T& a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> bool umax(T& a, T b) { return a < b ? a = b, 1 : 0; }
template<class T> int lwb(V<T>& a, T b) { return int(lb(all(a),b)-begin(a)); }
template<class T> int upb(V<T>& a, T b) { return int(ub(all(a),b)-begin(a)); }
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

constexpr ll bits(ll x) { assert(x >= 0);
    return x == 0 ? 0 : 63-__builtin_clzll(x); }
constexpr int msk2(int x) { return (1<<x)-1; }
constexpr int pct(ll x) { return __builtin_popcountll(x); }
const int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0}; // URDL
const int MX = 3e5+5;
const int MOD = 1e9+7;
const ll OO = 1e18;
const db PI = acos((db)-1);

inline namespace IO {
    #define M1(x) template<class T, class... U> void x(T&& t, U&&... u)
    #define M2(x) (int[]) { (x forward<U>(u),0)... }

    M1(re) { cin >> forward<T>(t); M2(cin >> ); }
    template<class T, class U> void re(pair<T,U>& x) { re(x.f,x.s); }
    template<class T> void re(vector<T>& x) { each(i,x) re(i); }

    M1(pr) { cout << forward<T>(t); M2(cout << " " << ); cout << "\n"; }
    template<class T, class U> void pr(pair<T,U>& x) { pr(x.f,x.s); }
    template<class T> void pr(vector<T>& x) {
        F0R(i,sz(x)) cout << x[i] << " ";
        pr(""); }

    void DBG() { cerr << "]" << endl; }
    template<class H, class... T> void DBG(H h, T... t) {
        cerr << to_string(h);
        if (sizeof...(t)) cerr << ", ";
        DBG(t...);
    }
    #ifdef LOCAL
        #define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
    #else
        #define dbg(...) 0
    #endif
}

const int SZ = 1<<15;
template<class T> struct node {
    const T ID{0,-1}; T comb(T a, T b) { return max(a,b); } // ck
    T v = ID, lazy = ID; node<T>* c[2] = {NULL,NULL};
    void apply(T x) { v = comb(v,x); lazy = comb(lazy,x); } // ck
    void push() {
        if (!c[0]) { F0R(i,2) c[i] = new node(); }
        if (lazy != ID) { F0R(i,2) c[i]->apply(lazy); }
        lazy = ID;
    }
    void pull() { v = comb(c[0]->v,c[1]->v); }
    void upd(int lo, int hi, T x, int l = 0, int r = SZ-1) {
        if (hi < l || r < lo) return;
        if (lo <= l && r <= hi) { apply(x); return; }
        push();
        int m = (l+r)/2;
        c[0]->upd(lo,hi,x,l,m); c[1]->upd(lo,hi,x,m+1,r);
        pull();
    }
    T query(int lo, int hi, int l = 0, int r = SZ-1) {
        if (hi < l || r < lo) return ID; // ck
        if (lo <= l && r <= hi) return v;
        push();
        int m = (l+r)/2;
        return comb(c[0]->query(lo,hi,l,m),c[1]->query(lo,hi,m+1,r));
    }
    int lower_bound(int lo, int x, int l = 0, int r = SZ-1) {
        if (r < lo || x > v) return -1;
        if (l == r) return l;
        int m = (l+r)/2;
        int res = c[0]->lower_bound(lo,x,l,m); if (~res) return res;
        return c[1]->lower_bound(lo,x,m+1,r);
    }
};

void solve(int tc) {
    int N,M; re(N,M);
    node<pi>* ST = new node<pi>();
    vector<vpi> ival(N+1);
    map<int,int> ind;
    F0R(_,M) {
        int i,l,r; re(i,l,r); --i;
        ival[i].pb({l,r});
        ind[l] = ind[r] = 0;
    }
    int co = 0; each(t,ind) t.s = ++co;
    F0R(i,N) for (auto [l,r]: ival[i]) {
        l = ind[l]; r = ind[r];
    }
    ival[N].pb({0,co+1});
    vi dp(N+1), lst(N+1);
    F0R(i,N+1) {
        pi bes{0,-1};
        for (auto [l,r]: ival[i]) umax(bes,ST->query(l,r));
        dp[i] = ++bes.f;
        lst[i] = bes.s; bes.s = i;
        for (auto [l,r]: ival[i]) ST->upd(l,r,bes);
    }
    int cur = N;
    vi ans;
    while (cur >= 0) {
        int nxt = lst[cur];
        FOR(i,nxt+1,cur) ans.pb(i+1);
        cur = nxt;
    }
    sort(all(ans));
    pr(sz(ans)); pr(ans);
}

int main() {
    setIO();
    int TC = 1; /*re(TC);*/
    FOR(i,1,TC+1) solve(i);
}