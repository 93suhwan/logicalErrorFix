#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 1e5 + 5, LG = 17, MOD = 1e9 + 7;
const long double PI = acos(-1);
int n, m;
int g[60][60];
int res;
long long edges[N];
vector<int> ans;
void BronKerbosch(int n, long long R, long long P, long long X) {
  if (ans.size() >= 5) return;
  if (P == 0LL && X == 0LL) {
    int t = __builtin_popcountll(R);
    if (ans.size() < 5 && t >= 5) {
      ans.clear();
      for (int i = 0; i < n; i++)
        if (R >> i & 1) {
          ans.push_back(i + 1);
        }
      ans.resize(5);
      for (auto x : ans) cout << x << ' ';
      exit(0);
    }
    return;
  }
  int u = 0;
  while (!((1LL << u) & (P | X))) u++;
  for (int v = 0; v < n; v++) {
    if (((1LL << v) & P) && !((1LL << v) & edges[u])) {
      BronKerbosch(n, R | (1LL << v), P & edges[v], X & edges[v]);
      P -= (1LL << v);
      X |= (1LL << v);
    }
  }
}
int max_clique(int n) {
  res = 0;
  for (int i = 1; i <= n; i++) {
    edges[i - 1] = 0;
    for (int j = 1; j <= n; j++)
      if (g[i][j]) edges[i - 1] |= (1LL << (j - 1));
  }
  BronKerbosch(n, 0, (1LL << n) - 1, 0);
  return res;
}
void doWork() {
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  set<pair<int, int>> st;
  for (int i = 1; i <= n; i++) {
    st.insert({(int)(adj[i]).size(), i});
  }
  vector<int> answer;
  while (st.size()) {
    auto node = st.begin()->second;
    st.erase(st.begin());
    answer.push_back(node);
    for (auto v : adj[node]) st.erase({adj[v].size(), v});
  }
  if (answer.size() >= 5) {
    answer.resize(5);
    for (auto x : answer) cout << x << ' ';
  } else {
    assert(n <= 50);
    ans.clear();
    memset(g, 0, sizeof g);
    for (int i = 1; i <= n; i++)
      for (auto x : adj[i]) g[i][x] = 1;
    int out = max_clique(n);
    if (max_clique(n) > 5) {
      for (auto x : ans) cout << x << ' ';
    } else {
      for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
          if (i != j) g[i][j] ^= 1;
      ans.clear();
      if (max_clique(n) > 5) {
        for (auto x : ans) cout << x << ' ';
      } else {
        cout << "-1\n";
      }
    }
  }
}
int32_t main() {
  int t = 1;
  while (t--) {
    doWork();
    if (t > 0) cout << "\n";
  }
  return 0;
}
