#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
namespace DSU {
int p[N];
int rank[N];
int get(int v) {
  if (p[v] != v) {
    p[v] = get(p[v]);
  }
  return p[v];
}
void merge(int a, int b) {
  a = get(a);
  b = get(b);
  if (a == b) return;
  if (rank[a] < rank[b]) swap(a, b);
  p[b] = a;
  if (rank[a] == rank[b]) rank[a]++;
}
void init() { iota(p, p + N, 0); }
}  // namespace DSU
int some[N];
void init() {
  fill(some, some + N, -1);
  for (int i = 2; i < N; i++) {
    if (some[i] == -1) {
      for (int j = i; j < N; j += i) {
        some[j] = i;
      }
    }
  }
}
vector<int> get(int x) {
  vector<int> ans;
  while (x > 1) {
    ans.push_back(some[x]);
    x /= some[x];
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  init();
  DSU::init();
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &t : a) {
    cin >> t;
  }
  for (int j = 0; j < n; j++) {
    vector<int> F = get(a[j]);
    for (int i = 0; i + 1 < (int)F.size(); i++) {
      DSU::merge(F[i], F[i + 1]);
    }
  }
  set<pair<int, int>> ccs;
  for (int i = 0; i < n; i++) {
    vector<int> S = get(a[i] + 1);
    S.push_back(some[a[i]]);
    for (auto x : S) {
      for (auto y : S) {
        x = DSU::get(x);
        y = DSU::get(y);
        ccs.insert({x, y});
        ccs.insert({y, x});
      }
    }
  }
  while (q--) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    s = some[a[s]];
    t = some[a[t]];
    if (DSU::get(s) == DSU::get(t)) {
      cout << 0 << '\n';
    } else if (ccs.count({DSU::get(s), DSU::get(t)})) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }
}
