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
const ll inf = int(3e10);

class solve{

    set<pair<ll,int>> triples;
    set<pair<ll,int>> E[maxn];
    set<pair<int,pi>> sub;
    map<pi,int> weight;

    ll triple_sum[maxn];

    int n,m;

public:
    solve(){
        cin >> n >> m;
        rep(i,n) E[i].clear();
        triples.clear();
        rep(i,n){
            triple_sum[i] = inf;
            triples.insert({triple_sum[i],i});
        }
        sub.clear();
        weight.clear();

        rep(_,m){
            int u,v,w; cin >> u >> v>>w; u--,v--;
            add(u,v,w);
        }

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
    
    pi hh(const pi &p){
        auto [x, y] = p;
        return mp(min(x,y),max(x,y));
    };

    void query(){
        auto ans = triples.begin()->first;

        auto it = sub.begin();

        vector<pair<ll,pi>> edges(0);



        rep(_,10){
            if(it==sub.end()) break;
            edges.emplace_back(mp(it->first, hh(it->second)));
            it++;
        }

        sort(edges.begin(), edges.end());
        edges.erase(unique(edges.begin(), edges.end()), edges.end());

        // dbg(edges);

        ll ans2=inf;

        rep(i,sz(edges))rep(j,i){
            auto [a,b] = edges[i].second;
            auto [c,d] = edges[j].second;
            if(a==c||b==c||a==d||b==d) continue;
            ans2 = min(ans2, edges[i].first+edges[j].first);
        }

        // dbg(ans2);

        cout << min(ans,ans2) << endl;
    }

    void update_triples(int u){
        ll new_sum = 0;
        if (sz(E[u]) < 3){
            new_sum = inf;
        }else{
            auto it = E[u].begin();
            rep(_,3){
                new_sum += it->first;
                it++;
            }
        }

        if (new_sum!=triple_sum[u]){
            triples.erase(triples.find(mp(triple_sum[u],u)));
            triples.insert(mp(new_sum, u));
            triple_sum[u] = new_sum;
        }

        // dbg(triples);

    }
    void add_edge(int u, int v, int w){
        bool change=0;
        if (sz(E[u]) < 3){
            sub.insert(mp(w,mp(u,v)));
            change=1;
        }else{

            auto it = E[u].begin();
            auto p = mp(w, v);
            rep(_,3){
                if (p.first < it->first || p.first == it->first && p.second < it->second) change=1;
                it++;
            }
            if (change){ // remove orignal 3nd edge from top edges
                it--;
                auto [_w, _v] = *it;
                sub.erase(sub.find(mp(_w,mp(u,_v))));
                sub.insert(mp(w,mp(u,v)));
            }
        }
        E[u].insert({w, v});

        if (change){
            update_triples(u);
        }

    }
    void add(int u, int v, int w){
        add_edge(u, v, w);
        add_edge(v, u, w);
        weight[hh(mp(u,v))]=w;
    }

    void del_edge(int u, int v, int w){
        bool change=0;

        if (sz(E[u]) < 3){
            change = 1;
            sub.erase(sub.find({w,{u,v}}));
        }else{
            auto it = E[u].begin();
            auto p = mp(w,v);
            rep(_,3){
                if (p.first == it->first && p.second == it->second) change=1;
                it++;
            }
            if(change){
                if (it!=E[u].end()) sub.insert({it->first,{u, it->second}});
                sub.erase(sub.find({w,{u,v}}));
            }
        }

        E[u].erase(E[u].find({w, v}));

        if(change){
            update_triples(u);
        }

    }

    void del(int u, int v){
        auto w = weight[hh(mp(u,v))];
        del_edge(u,v,w);
        del_edge(v,u,w);
    }

};

int main(){
    sync;
    int cas = 1;
    // cin >> cas;
    rep(ca, cas) solve();
    return 0;
}