#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
 

//----------define--------------//
#define FILE_IN     "B.inp"
#define FILE_OUT    "B.out"
#define ofile       freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio         ios::sync_with_stdio(0);cin.tie(0)
#define MOD         (ll(998244353))
#define MAXN        201010
#define INF         (ll(1000000007))
#define x           first
#define y           second
#define pii         pair<int,int>
#define pll         pair<long long,long long>
#define pli         pair<long long, int>
#define piii        pair<pii,int>
#define pb          push_back
#define endl        "\n"
#define vt          vector
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> order_set;
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> order_trie;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//---------functions-------------//
class DisjointSet{ public:
    vector<int> parent, size;
    DisjointSet(int n): parent(n), size(n) { for(int i=0; i<n; i++) {parent[i] = i; size[i] = 0;}; }
    int sz(int a){return size[find(a)];}
    void join(int a, int b) { if (!check(a, b)) size[find(a)] += size[find(b)]; parent[find(b)] = find(a); }
    int find(int a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }
    bool check(int a, int b){ return find(a) == find(b); }
};
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

//---------END-------------------//

int T, n, d, ff[MAXN];
pii f[MAXN];
piii A[MAXN];
map<int, vt<piii>> F;
void xl(vt<piii> vv){ 
    if (vv.empty()) return;
    auto k = vv.back(); 
    for (auto i : vv)
        f[i.y] = {A[i.y].x.x - k.x.x, ff[i.y] - (A[i.y].x.x - k.x.x)}; 
}
void solve(){
    d = 0;
    cin >> n;
    F.clear();
    for (int i = 1; i <= n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        A[i] = {{u, v}, w};
        F[u + v - w].pb({{max(u - w, 0), u + min(0, v - w)}, i});
        //cout << u + v - w << " " << max(u - w, 0) << " " << u + min(0, v - w) << endl;
        ff[i] = w;
    }
    for (auto i : F){
        vt<piii> v = i.y;
        vt<piii> vv = {};
        sort(v.begin(), v.end());
        pii s = {-1, 0};
        for (auto w : v){
            if (s.x == -1) {
                ++d;
                s = w.x;
                vv.pb(w);
            }
            else if (w.x.x > s.y) {
                s = w.x;
                ++d;
                xl(vv);
                vv.clear();
                vv.pb(w);
            } else vv.pb(w);
        }
        xl(vv);
    }
    cout << d << endl;
    for (int i = 1; i <= n; i++)
       cout << f[i].x << " " << f[i].y << endl;
}
int check(){
    set<pii> SS = {};
    for (int i = 1; i <= n; i++){
        if (f[i].x + f[i].y != A[i].y) return 1;
        if ((A[i].x.x - f[i].x < 0) || (A[i].x.y - f[i].y < 0)) return 2;
        SS.insert({A[i].x.x - f[i].x, A[i].x.y - f[i].y});
    }
    return SS.size();
}
int main(){
    //ofile;
    cin >> T;
    while (T--){
        solve();
        //cout << (solve() == check() ? "AC" : "WA") << endl;
    }
    
}