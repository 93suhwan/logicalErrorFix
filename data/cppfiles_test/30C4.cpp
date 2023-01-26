#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
const int N = 1e6 + 1010;
int p[N], sz[N];
int find_set(int v) {
  if (v == p[v]) return v;
  return p[v] = find_set(p[v]);
}
void union_set(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
  }
}
void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < N; i++) p[i] = i, sz[i] = 1;
  vector<vector<int>> divs(N);
  for (int i = 2; i < N; i++)
    if (divs[i].empty())
      for (int j = 2 * i; j < N; j += i) divs[j].push_back(i);
  for (auto to : a)
    for (auto v : divs[to]) union_set(to, v);
  set<pair<int, int>> e;
  for (auto to : a) {
    auto p = divs[to + 1];
    p.push_back(to);
    for (int i = 0; i < int(p.size()); i++)
      for (int j = i + 1; j < int(p.size()); j++) {
        int u = find_set(p[i]);
        int v = find_set(p[j]);
        if (u != v) e.insert({min(u, v), max(u, v)});
      }
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    u = find_set(a[u]);
    v = find_set(a[v]);
    if (u == v)
      cout << 0 << '\n';
    else if (e.count({min(u, v), max(u, v)}))
      cout << 1 << '\n';
    else
      cout << 2 << '\n';
  }
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) solve();
}
