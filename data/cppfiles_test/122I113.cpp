#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int MAX = 2e3 + 10;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;
const long double PI = acos(-1);
struct DSU {
  int n;
  vector<int> parent, size;
  DSU(int n) {
    this->n = n;
    parent.assign(n + 1, 0);
    size.assign(n + 1, 1);
    for (int i = 0; i <= n; i++) parent[i] = i;
  }
  int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
  }
  void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a, b);
      parent[b] = a;
      size[a] += size[b];
    }
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b, p;
    cin >> n >> m;
    DSU dsu1(n + 1), dsu2(n + 1);
    vector<tuple<int, int, int> > ans(n - 1);
    bool pos = true;
    vector<pair<int, int> > equal, diff;
    vector<tuple<int, int, int> > choose;
    for (int i = 0; i < n - 1; i++) {
      cin >> a >> b >> p;
      if (p == -1)
        choose.push_back({a, b, i});
      else if (__builtin_popcount(p) % 2 == 0) {
        equal.push_back({a, b});
        ans[i] = {a, b, p};
      } else {
        diff.push_back({a, b});
        ans[i] = {a, b, p};
      }
    }
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> p;
      if (p == 0) {
        equal.push_back({a, b});
      } else {
        diff.push_back({a, b});
      }
    }
    for (auto [a, b] : equal) {
      dsu1.join(a, b);
    }
    for (auto [a, b] : diff) {
      if (dsu1.find(a) == dsu1.find(b)) pos = false;
    }
    for (auto [a, b, id] : choose) {
      bool eq = dsu1.find(a) == dsu1.find(b);
      if (eq)
        ans[id] = {a, b, 0};
      else
        ans[id] = {a, b, 1};
    }
    if (!pos) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto [a, b, p] : ans) cout << a << " " << b << " " << p << '\n';
    }
  }
  return 0;
}
