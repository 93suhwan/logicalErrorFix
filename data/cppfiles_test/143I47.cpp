#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = (ll)1e9 + 7;
const int INF = 1e9 + 1;
const int N = 2e5 + 100;
const double eps = 1e-7;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T>
using PR = pair<T, T>;
template <typename XPAX>
bool ckma(XPAX &x, XPAX y) {
  return (x < y ? x = y, 1 : 0);
}
template <typename XPAX>
bool ckmi(XPAX &x, XPAX y) {
  return (x > y ? x = y, 1 : 0);
}
void solve() {
  int n;
  cin >> n;
  V<int> a(n);
  V<int> cnt(n + 1);
  for (int &c : a) cin >> c, cnt[c]++;
  map<int, int> sp;
  int ret = 0;
  bool bad = 0;
  V<bool> ok(n + 1, false);
  for (int i = 0; i <= n; ++i) {
    while ((int)sp.size() && sp.rbegin()->second <= 1) {
      sp.erase(sp.rbegin()->first);
    }
    if (i == 0) {
      cout << cnt[0] << ' ';
    } else {
      if (bad) {
        cout << -1 << ' ';
        continue;
      }
      if (!ok[i - 1]) {
        if (!(int)sp.size()) {
          bad = 1;
          cout << -1 << ' ';
          continue;
        }
        int x = sp.rbegin()->first;
        sp[x] -= 1;
        ret += i - x - 1;
        ok[i - 1] = 1;
      }
      cout << ret + cnt[i] << ' ';
    }
    if (cnt[i]) ok[i] = 1;
    sp[i] += cnt[i];
  }
  cout << '\n';
}
void test_case() {
  int t;
  cin >> t;
  for (int p = 0; p < (t); ++p) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  test_case();
}
