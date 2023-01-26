#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
vector<int> d[N + 1];
vector<int> r[N + 1];
unordered_set<int> g[N + 1];
vector<int> p;
vector<int> sz;
int getp(int v) {
  if (p[v] == v) return v;
  p[v] = getp(p[v]);
  return p[v];
}
void merge(int a, int b) {
  a = getp(a), b = getp(b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  p[b] = a;
  sz[a] += sz[b];
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i < N; i++) {
    if ((int)d[i].size() != 0) continue;
    for (int j = i; j < N; j += i) d[j].push_back(i);
  }
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  p = vector<int>(n + 1, 0);
  sz = vector<int>(n + 1, 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[i] = i;
  }
  for (int i = 0; i < n; i++) {
    for (auto x : d[a[i]]) {
      r[x].push_back(i);
    }
  }
  for (int i = 2; i < N; i++) {
    for (int j = 1; j < (int)r[i].size(); j++) merge(r[i][j - 1], r[i][j]);
  }
  for (int i = 0; i < n; i++) {
    for (auto x : d[a[i] + 1]) {
      if ((int)r[x].size() == 0) continue;
      g[getp(i)].insert(getp(r[x][0]));
    }
  }
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (getp(a) == getp(b)) {
      cout << "0\n";
      continue;
    }
    if (g[getp(a)].count(getp(b)) || g[getp(b)].count(getp(a))) {
      cout << "1\n";
      continue;
    }
    cout << "2\n";
  }
}
