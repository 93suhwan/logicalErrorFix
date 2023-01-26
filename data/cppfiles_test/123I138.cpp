#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair 
using namespace std;
void db() {cout << endl;}
template <typename T, typename ...U> void db(T a, U ...b) {
    //return;
    cout << a << ' ', db(b...);
}
#ifdef Cloud
#define file freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define file ios::sync_with_stdio(false); cin.tie(0)
#endif
const int inf = 1e9, N = 2e5 + 1, mod = 1e9 + 7;
pair<int, int> ma[N];
int d[N]{}, par[N]{};
vector<int> g[N];
void dfs(int u, int p){
    ma[u] = {d[u], u};
    for (int i : g[u]) if (i != p){
        d[i] = d[u] + 1;
        par[i] = u;
        dfs(i, u);
        ma[u] = max(ma[u], ma[i]);
    }
}
signed main(){
    file;
    int n, k;
    cin >> n >> k;
    int deg[n + 1]{};
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    dfs(1, -1);
    int lf = 0;
    for (int i = 2; i <= n; i++) lf += deg[i] == 1;
    if (lf <= k){
        ll ans = 0;
        for (ll i = lf; i <= k; i++) ans = max(ans, i * (n - i));
        cout << ans;
        return 0;
    }
    set<pair<int, int>> s;
    s.insert({ma[1].fi + 1, ma[1].se});
    bool vis[n + 1]{};
    int ans = 0;
    for (int t = 0; t < k; t++){
        auto it = --s.end();
        ans += (*it).fi;
        int u = (*it).se;
        s.erase(it);
        while (!vis[u]){
            vis[u] = 1;
            for (int i : g[u]){
                if (i == par[u] or vis[i]) continue;
                s.insert({ma[i].fi - d[u], ma[i].se});
            }
            u = par[u];
            if (!u) break;
        }
    }
    //db(ans);
    cout << 1ll * (ans - k) * (k - (n - ans));
}