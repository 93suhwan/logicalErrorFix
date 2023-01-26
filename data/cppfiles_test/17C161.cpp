#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;
template <typename T>
struct Fenwick {
  int n;
  vector<T> a;
  Fenwick(int n) : n(n), a(n) {}
  void add(int x, T v) {
    for (int i = x + 1; i <= n; i += i & -i) {
      a[i - 1] += v;
    }
  }
  T sum(int x) {
    T s = 0;
    for (int i = x + 1; i > 0; i -= i & -i) {
      s += a[i - 1];
    }
    return s;
  }
  T rangeSum(int l, int r) { return sum(r) - sum(l - 1); }
};
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> b(a);
  sort(b.begin(), b.end());
  Fenwick<int> fen(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    int small = fen.sum(pos - 1);
    int big = i - small - fen.rangeSum(pos, pos);
    fen.add(pos, 1);
    ans += min(small, big);
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
