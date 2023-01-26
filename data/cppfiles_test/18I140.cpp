#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmin(T& _old, T _new) {
  return _old > _new && (_old = _new, true);
}
template <class T>
bool chmax(T& _old, T _new) {
  return _old < _new && (_old = _new, true);
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n << 1);
  for (int i = 1, u, v; i <= k; ++i) {
    cin >> u >> v, --u, --v;
    if (u > v) {
      swap(u, v);
    }
    a[u] = -i, a[v] = i;
  }
  vector<int> state((n - k) << 1);
  iota(state.begin(), state.begin() + n - k, k + 1);
  iota(state.rbegin(), state.rbegin() + n - k, -n);
  vector<int> b(n << 1);
  bitset<128> check;
  int ans = 0;
  for (int t = (n - k) << 1; t--;) {
    rotate(state.begin(), state.begin() + 1, state.end());
    auto it = state.begin();
    b = a;
    for (auto& x : b) {
      if (!x) {
        x = *(it++);
      }
    }
    int s = 0;
    for (int i = 0; i < n; ++i) {
      check.reset();
      for (int j = (i + 1) % (2 * n); abs(b[i]) != abs(b[j]);
           j = (j + 1) % (2 * n)) {
        check.flip(abs(b[j]));
      }
      s += check.count();
    }
    chmax(ans, s);
  }
  cout << ans / 2 << '\n';
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
