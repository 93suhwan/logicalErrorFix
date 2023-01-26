#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;

#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                    
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 400;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, q, a[N];
vector<int> g[N];
int tin[N], tout[N], timer, up[N][20];

void dfs(int v, int par = 0){
    tin[v] = ++timer;
    up[v][0] = par;
    for(int i = 1; i < 20; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];
    
    for(auto to : g[v]){
        if(to != par){
            dfs(to, v);    
        }
    }

    tout[v] = timer;
}
bool is_par(int u, int v){
    return (tin[u] <= tin[v] && tout[v] <= tout[u]);    
}

int lca(int a, int b){
    if(is_par(a, b)) return a;
    if(is_par(b, a)) return a;
    for(int i = 19; i >= 0; i--)
        if(!is_par(up[a][i], b))
            a = up[a][i];
    return up[a][0];
}
int t[N];
         
void upd(int pos, int val){
    for(; pos < N; pos |= (pos + 1))
        t[pos] += val;
}

void upd(int l, int r, int x){
    upd(l, x);
    upd(r + 1, -x);
}

int get(int r){
    int res = 0;
    for(; r >= 0; r = (r & (r + 1)) - 1)
        res += t[r];
    return res;
}

main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = abs(a[i]);
    }  
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    
    for(int i = 1; i <= n; i++)
        upd(tin[i], tout[i], a[i]);

    while(q--){
        int type;
        int u, v, x;
        cin >> type;
        if(type == 2){
            cin >> u >> v;
            if(u == v){
                cout << "0\n";
                continue;
            }                     
            int l = lca(u, v);
            cout << 2 * (get(tin[u]) + get(tin[v]) - get(tin[l]) - get(tin[up[l][0]])) - a[u] - a[v] << "\n";
        }else{
            cin >> v >> x;
            x = abs(x);
            upd(tin[v], tout[v], x - a[v]);
            a[v] = x;
        }
    }  

}