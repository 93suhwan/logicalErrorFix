#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mx = 112345;
vector<int> adj[mx];
int h[mx], sz[mx], par[mx][20], in[mx], t = 0;


int bit[mx];
inline int lb (int x) { return x & -x; };

ll qry (int x) {
  ll ans = 0;
  while(x) ans += bit[x], x -= lb(x);
  return ans;
}

void upd (int x, int val) {
  ll ans = 0;
  while(x < mx) bit[x] += val, x += lb(x);
}

void dfs (int v) {
  in[v] = ++t; sz[v] = 1;
  for (auto u : adj[v]) {
    if (u == par[v][0]) continue;
    h[u] = 1 + h[v];
    par[u][0] = v;
    for (int i = 1; i < 20; i++) {
      par[u][i] = par[par[u][i-1]][i-1];
    }
    dfs(u); sz[v] += sz[u];
  }
}

int lca (int a, int b) {
  if (h[a] < h[b]) swap(a, b);
  for (int i = 19; i >= 0; i--) {
    if (h[par[a][i]] >= h[b]) a = par[a][i];
  }
  
  for (int i = 19; i >= 0; i--) {
    if (par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
  }
  if (a != b) a = par[a][0];
  return a;
}

int v[mx];
main () {
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] = abs(v[i]);
  }
  
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  h[1] = 1, dfs(1);
  
  for (int i = 1; i <= n; i++) {
    upd (in[i], v[i]);
    upd (in[i]+sz[i], -v[i]);
  }
  
  for (int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      c = abs(c)-v[i];
      upd (in[b], c);
      upd (in[b]+sz[i], -c);
      v[i] += c;
    } else {
      if (b == c) {
        cout << 0 << endl;
        continue;
      }
      int p = lca(b, c);
      ll nodeSum = qry(in[b]) + qry(in[c]) - qry(in[p]) - qry(in[par[p][0]]);
      cout << 2 * nodeSum - v[b] - v[c] << endl;
    }
  }
  
}
