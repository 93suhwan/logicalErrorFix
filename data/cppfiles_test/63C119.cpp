#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;
template <class X, class Y>
bool minimize(X &a, Y b) {
  if (a > b) return a = b, true;
  return false;
}
template <class X, class Y>
bool maximize(X &a, Y b) {
  if (a < b) return a = b, true;
  return false;
}
struct Disjoint_set {
  vector<int> lab;
  Disjoint_set(int n) { lab.assign(n + 1, -1); }
  int root(int u) { return lab[u] < 0 ? u : lab[u] = root(lab[u]); }
  bool join(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
    return true;
  }
};
bool mp1[N][N], mp2[N][N];
int n, m1, m2;
void solve(void) {
  cin >> n >> m1 >> m2;
  Disjoint_set d1(n);
  Disjoint_set d2(n);
  for (int i = 1; i <= m1; i++) {
    int u, v;
    cin >> u >> v;
    mp1[u][v] = mp1[v][u] = 1;
    d1.join(u, v);
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    cin >> u >> v;
    mp1[u][v] = mp1[v][u] = 1;
    d2.join(u, v);
  }
  vector<pair<int, int>> res;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (i == j) continue;
      if (!mp1[i][j]) {
        if (d1.root(i) == d1.root(j)) continue;
        if (d2.root(i) == d2.root(j)) continue;
        d1.join(i, j);
        d2.join(i, j);
        res.push_back(make_pair(i, j));
        mp1[i][j] = mp1[j][i] = 1;
      }
    }
  cout << res.size() << '\n';
  for (pair<int, int> x : res) cout << x.first << " " << x.second << '\n';
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
