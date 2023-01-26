#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool uax(T &x, T y) {
  return (y > x) ? x = y, true : false;
}
template <typename T>
inline bool uin(T &x, T y) {
  return (y < x) ? x = y, true : false;
}
template <typename T>
void kek(T ans) {
  cout << ans << endl;
  exit(0);
}
using i64 = int64_t;
const int MOD = (int)1e9 + 7;
const i64 INF = (i64)1e18 + 42;
void SolveCase() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> xs(n), ys(m);
  for (int &x : xs) cin >> x;
  for (int &x : ys) cin >> x;
  vector<pair<int, int>> a(k);
  for (auto &[x, y] : a) cin >> x >> y;
  i64 ans = 0;
  a.emplace_back(1e9, 1e9);
  for (int rep = 0; rep < 2; ++rep) {
    sort(begin(a), end(a));
    for (int i = 0, p = 0; i < n - 1; ++i) {
      while (a[p].first <= xs[i]) ++p;
      vector<int> t;
      while (a[p].first < xs[i + 1]) t.push_back(a[p++].second);
      sort(begin(t), end(t));
      int cnt = 0, run = 0, prv = -1;
      for (int x : t) {
        if (x > prv) {
          cnt += run;
          run = 0;
        }
        ++run;
        ans += cnt;
        prv = x;
      }
    }
    swap(n, m);
    swap(xs, ys);
    for (auto &[x, y] : a) swap(x, y);
  }
  cout << ans << '\n';
}
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) SolveCase();
}
