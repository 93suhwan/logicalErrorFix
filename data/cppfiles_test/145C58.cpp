#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t[N];
struct DSU {
  vector<int> p, sz;
  DSU(int n = 0) : p(n + 1), sz(n + 1, 1) {
    for (int i = 1; i <= n; i++) p[i] = i;
  }
  int find(int x) { return (p[x] ^ x) ? (p[x] = find(p[x])) : p[x]; }
  int operator[](int x) { return find(x); }
  int merge(int x, int y) {
    if ((x = find(x)) ^ (y = find(y))) p[x] = y, sz[y] += sz[x];
    return x ^ y;
  }
};
template <typename T>
ostream& operator<<(ostream& os, vector<T> a) {
  for (int i = 0; i < a.size(); ++i) os << (i ? " " : "") << a[i];
  return os;
}
void solve(int tc) {
  int n, k;
  cin >> n >> k;
  map<int, vector<pair<int, int>>> mp_x, mp_y;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y >> t[i];
    mp_x[x].push_back(make_pair(y, i));
    mp_y[y].push_back(make_pair(x, i));
  }
  DSU dsu(n);
  for (auto [x, v] : mp_x) {
    sort(v.begin(), v.end());
    int z = v.size();
    for (int j = 0; j + 1 < z; j++) {
      auto [y1, i1] = v[j];
      auto [y2, i2] = v[j + 1];
      if (y1 + k >= y2) {
        dsu.merge(i1, i2);
      }
    }
  }
  for (auto [x, v] : mp_y) {
    sort(v.begin(), v.end());
    int z = v.size();
    for (int j = 0; j + 1 < z; j++) {
      auto [y1, i1] = v[j];
      auto [y2, i2] = v[j + 1];
      if (y1 + k >= y2) {
        dsu.merge(i1, i2);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    t[dsu[i]] = min(t[dsu[i]], t[i]);
  }
  vector<int> tx;
  for (int i = 1; i <= n; ++i)
    if (dsu[i] == i) {
      tx.push_back(t[i]);
    }
  sort(tx.begin(), tx.end(), greater<int>());
  int ans = min((int)tx.size() - 1, tx[0]);
  for (int i = 0; i + 1 < tx.size(); ++i) {
    ans = min(ans, max(i, tx[i + 1]));
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, tc = 0;
  cin >> t;
  while (t--) solve(++tc);
}
