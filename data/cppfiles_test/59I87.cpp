/// Zengy Manga
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;

#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

using ll = long long;
using ii = pair<int, int>;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define F first
#define S second
#define f(i, a, b)  for(int i = a; i < b; i++)
#define all(a)  a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) (int)(x).size()
#define mp make_pair
#define popCnt(x) (__builtin_popcountll(x))

const int N = 1e5+5, LG = log2(N) + 1, MOD = 1e9 + 7;
const double PI = acos(-1);
void printCase() {
    static int cnt = 0;
    cout << "Case " << ++cnt << ":\n";
}
int n, m;
vector<int> adj[1005];
int a[1005], b[1005];
bool vis[1005];
int par[1005];
bool dfs(int node, int p, ll atk) {
    ///I want to check if I can add a cycle
    ///to my already connected component which I can go anywhere from
    for(auto to : adj[node]) {
        if(to != p && a[to] < atk) {  ///I can visit it
            if(vis[node] && vis[to])continue;
            ///When can I make a cycle
            ///(to && !node) ///then that means I took a path not in my set and returned to my set hence I can take it
            ///If I reach a node that was in the stack then I can call that a cycle hheh
            if(vis[to]) { /// found cycle consisting of One Path
                for(int j = node; j; j = par[j]){
                    vis[j] =  true;
                }
                return true;
            }   else if(par[to]) {  ///found a cycle consisting of Two Paths
                for(int j = node; j; j = par[j]){
                    vis[j] =  true;
                }
                for(int j = to; j; j = par[j]){
                    vis[j] =  true;
                }
                return true;
            }   else {
                par[to] = node;
                if(dfs(to, node, atk + b[to])) {
                    return true;
                }
            }
        }
    }
    return false;
}
bool check(int atk) {

    memset(vis, 0, sizeof vis);
    vis[1] = true;

    while(true) {
        ll init = atk;
        if(accumulate(vis+1,vis+n+1,0) == n)
            return true;
        f(i,1,n+1)if(vis[i])
            init += b[i];
        bool ok = false;
        memset(par,0,sizeof par);
        f(i,1,n+1)
            if(vis[i]) {
                ok |= dfs(i, 0, init);
            }
        if(!ok)
            return false;
    }


}
void doWork() {

    cin >> n >> m;
    f(i,1,n+1)  adj[i].clear();
    f(i,2,n+1)
        cin >> a[i];
    f(i,2,n+1)
        cin >> b[i];
    f(i,1,m+1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }


    int lo = 1, hi = 1e9 + 1;

    while(lo < hi) {
        int md = lo + (hi - lo) / 2;
        if(check(md))
            hi = md;
        else
            lo = md + 1;
    }

    cout << lo << "\n";

}
int32_t main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif // ONLINE_JUDGE
    int t = 1;
    cin >> t;
    while (t--) {
        doWork();
    }
    return 0;
}
