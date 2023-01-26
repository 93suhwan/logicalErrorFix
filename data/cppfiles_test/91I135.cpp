#include <bits/stdc++.h>
using namespace std;
#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;
 
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;
 
template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");
 
private:
    using ll = long long;
 
    int v;
 
    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }
 
public:
 
    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
 
    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
 
    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    friend modnum inv(const modnum& m) { return m.inv(); }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }
 
    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return modnum(*this);
    }
 
    modnum& operator ++ () {
        v ++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator -- () {
        if (v == 0) v = MOD;
        v --;
        return *this;
    }
    modnum& operator += (const modnum& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }
 
    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
 
template <typename T> T pow(T a, long long b) {
    assert(b >= 0);
    T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

#define sync ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i,n) for(int i=0; i<int(n); ++i)
#define repp(i,a,n) for(int i=a; i<int(n); ++i)
#define sz(x) int((x).size())
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define mp make_pair

template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T> &input){for (auto const& i: input) {os << i << " ";}return os;}
template<class T> std::ostream& operator<<(std::ostream& os, const std::set<T> &input){for (auto const& i: input) {os << i << " ";}return os;}
template<class T, size_t n> std::ostream& operator<<(std::ostream& os, const std::array<T, n> &input){for (size_t i=0; i<n; ++i) {os << input[i] << " ";}return os;}
template<class T1, class T2> std::ostream& operator<<(std::ostream& os, const std::pair<T1,T2> &input){os << "(" << input.first << ", " << input.second << ')';return os;}
template<class T1, class T2> std::ostream& operator<<(std::ostream& os, const std::unordered_map<T1,T2> &input){for (auto const& i: input) {os << i << " ";}return os;}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << H;debug_out(T...);}
#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

double startTime;
double getCurrentTime(){return ((double)clock() - startTime) / CLOCKS_PER_SEC;}

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<pi> vp;
typedef vector<ll> vl;
typedef vector<vi> vvi;

// === temeplate ===

const int maxn = int(1e5);
const ll inf = (long long)(4e12);

class solve{
    int n,m;
    set<pair<ll,int>> c;
    vector<set<pair<ll,int>>> a, b;
    vector<vector<pair<ll,int>>> E;
    map<pair<int,int>,ll> weight;
    set<pair<ll,pair<int,int>>> A;

public:
    pi hh(int u, int v){
        return {min(u,v),max(u,v)};
    }

    ll tri(int u){
        if (sz(a[u]) >= 3){
            auto it = a[u].begin();
            ll x=0;
            rep(i,3){
                x+=it->first;
                it++;
            }
            return x;
        }else{
            return -1;
        }
    }

    void c_ad(int u){
        ll x = tri(u);
        if (x>-1) c.insert({x, u});
    }

    void c_rm(int u){
        ll x = tri(u);
        if (x>-1) c.erase({x, u});
    }

    solve(){
        cin >> n >> m;
        E.resize(n);
        rep(i,n) E[i].clear();
        weight.clear();
        c.clear();
        A.clear();

        rep(_,m){
            int u,v,w; cin >> u >> v >> w; u--,v--;
            E[u].pb({w, v});
            E[v].pb({w, u});
            weight[hh(u, v)] = w;
        }

        // build a & b
        a.resize(n);
        b.resize(n);
        rep(u,n){
            sort(E[u].begin(), E[u].end());
            rep(i, sz(E[u])){
                if (i<3){
                    a[u].insert(E[u][i]);
                    auto [w, v] = E[u][i];
                    A.insert({w, {u, v}});
                }else{
                    b[u].insert(E[u][i]);
                }
            }
        }

        // build c
        rep(u,n) c_ad(u);

        query();

        cin >> m;
        rep(_,m){
            int o,u,v,w; cin >> o>>u >> v; u--,v--;
            if(o==1){
                cin >> w;
                add(u,v,w);
            }else{
                del(u,v);
            }
            query();
        }

    }
    
    void query(){
        ll ans = inf;
        if (sz(c)) ans = c.begin()->first;
        ll ans2 = inf;

        // dbg(A);
        if (sz(A)){
            auto [w, p] = *A.begin();
            auto [u, v] = p;

            for(auto [wu, to_u]: a[u]){
                for(auto [wv, to_v]: a[v]){
                    if(to_u!=to_v && to_u!=v && to_v!=u){
                        ans2 = min(ans2, wu+wv);
                    }
                }
            }

            auto it = A.begin();
            rep(i,12){
                it++;
                if(it==A.end()) break;

                auto [ww,pp] = *it;
                auto [uu,vv] = pp;

                if(u!=uu && u!=vv && v!=uu && v!=vv) ans2 = min(ans2, w+ww);
            }
        }
        cout << min(ans,ans2) << endl;
    }

    void add_edge(int u, int v, ll w){
        auto p = mp(w, v);

        if (sz(a[u]) < 3){
            a[u].insert(p);
            A.insert({w,{u,v}});
        }else{
            auto it = a[u].rbegin();
            if(p < *it){
                b[u].insert(*it);
                A.erase({it->first,{u,it->second}});
                a[u].erase(*it);
                a[u].insert(p);
                A.insert({w,{u,v}});
            }else{
                b[u].insert(p);
            }
        }

        
    }

    void add(int u, int v, ll w){
        weight[hh(u, v)] = w;
        c_rm(u); 
        c_rm(v);
        add_edge(u, v, w);
        add_edge(v, u, w);
        c_ad(u); 
        c_ad(v);
    }

    void del_edge(int u, int v, ll w){
        auto p = mp(w, v);

        if(a[u].find(p)==a[u].end()){
            b[u].erase(p);
        }else{
            a[u].erase(p); 
            A.erase({w,{u,v}});
            if(sz(a[u]) < 3 && sz(b[u])){
                auto it = b[u].begin();
                a[u].insert(*it);
                A.insert({it->first,{u, it->second}});
                b[u].erase(it);
            }
        }

    }

    void del(int u, int v){
        auto w = weight[hh(u, v)];
        c_rm(u); 
        c_rm(v);
        del_edge(u,v,w);
        del_edge(v,u,w);
        c_ad(u); 
        c_ad(v);
    }

};

int main(){
    sync;
    int cas = 1;
    // cin >> cas;
    rep(ca, cas) solve();
    return 0;
}