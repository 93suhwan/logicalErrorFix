#include "bits/stdc++.h"

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
  int n; cin >> n;
  const int block = 450;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int q; cin >> q;
  vector<int64_t> ans(q);
  vector<vector<pair<int, int>>> queries(n);
  for (int i = 0; i < q; ++i) {
    int v, k; cin >> v >> k; --v;
    queries[v].emplace_back(k, i);
  }
  vector<array<int, block>> f(n);
  vector<int> h(block + 5);
  vector<int> sz(n);
  const auto dfs1 = [&](const auto&dfs1, int u, int p) -> void {
    for (int v : adj[u]) {
      if (v == p) continue;
      dfs1(dfs1, v, u);
      for (int t = 0; t < block; ++t) {
        f[u][t] += max(1, f[v][t] - t);
      }
    }
    for (const auto&[k, idx] : queries[u]) {
      if (k < block) {
        ans[idx] = f[u][k];
      }
    }
  };
  dfs1(dfs1, 0, -1);
  const auto dfs2 = [&](const auto&dfs2, int u, int p) -> void {
    sz[u] = 1;
    for (int i = 0; i <= block; ++i) f[u][i] = 0;
    for (int v : adj[u]) {
      if (v == p) continue;
      dfs2(dfs2, v, u);
      for (int i = 0; i <= block; ++i) h[i] = 0;
      for (int i = 0; i <= min(block, sz[u]); ++i) {
        for (int j = 0; j <= sz[v] and i + j + 1 <= block; ++j) {
          h[i + j] = max(h[i + j], f[u][i] + 1);
          h[i + j + 1] = max(h[i + j + 1], f[u][i] + f[v][j]);
        }
      }
      sz[u] += sz[v];
      for (int i = 0; i <= block; ++i) f[u][i] = h[i];
    }
    for (const auto&[k,idx] : queries[u]) {
      if (k >= block) {
        for (int t = 0; t <= block; ++t) {
          ans[idx] = max(ans[idx], (int64_t)f[u][t] - 1ll * k * t);
        }
      }
    }
  };
  dfs2(dfs2, 0, -1);
  for (auto & it : ans) cout << it << '\n';
}

