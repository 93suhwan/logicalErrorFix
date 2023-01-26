#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
void Solve(int test) {
  int n, m;
  cin >> n >> m;
  42;
  vector<tuple<int, int, int>> edges;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i + 1 < n; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    x--, y--;
    if (v != -1) {
      int num_bit = __builtin_popcount(v);
      adj[x].push_back({y, v % 2});
      42;
      adj[y].push_back({x, v % 2});
    }
    edges.push_back({x, y, v});
  }
  42;
  for (int i = 0; i < m; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    x--, y--;
    if (v != -1) {
      int num_bit = __builtin_popcount(v);
      adj[x].push_back({y, v % 2});
      adj[y].push_back({x, v % 2});
    }
  }
  42;
  bool failed = false;
  vector<bool> used(n);
  vector<int> color(n);
  function<void(int)> Dfs = [&](int u) {
    used[u] = 1;
    42;
    for (auto [v, w] : adj[u]) {
      if (!used[v]) {
        color[v] = color[u] ^ w;
        Dfs(v);
        if (failed) return;
      } else {
        if (color[v] != color[u] ^ w) {
          failed = true;
          return;
        }
      }
    }
  };
  for (int i = 0; i < n && !failed; i++) {
    if (!used[i]) {
      Dfs(i);
    }
  }
  42;
  if (failed) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (auto [x, y, v] : edges) {
    if (v != -1) {
      cout << x + 1 << ' ' << y + 1 << ' ' << v << '\n';
    } else {
      cout << x + 1 << ' ' << y + 1 << ' ' << (color[x] != color[y]) << '\n';
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}
