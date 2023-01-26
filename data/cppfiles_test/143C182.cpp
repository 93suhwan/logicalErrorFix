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
  V<int> cnt(n + 1);
  for (int i = 0; i < (n); ++i) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  V<int> v;
  ll res = 0;
  for (int x = 0; x <= n; ++x) {
    if (res == -1) {
      cout << -1 << ' ';
      continue;
    }
    cout << res + cnt[x] << ' ';
    for (int i = 0; i < (cnt[x]); ++i) v.push_back(x);
    if (!(int)v.size())
      res = -1;
    else {
      res += x - v.back();
      v.pop_back();
    }
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
