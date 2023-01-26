#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e18 + 1;
const int64_t mod = 1e9 + 7;
void solve() {
  int64_t n, k;
  cin >> n >> k;
  vector<int64_t> a, b;
  int64_t mx = 0;
  a.push_back(0);
  b.push_back(0);
  for (int64_t i = 0; i < n; i++) {
    int64_t x;
    cin >> x;
    if (x >= 0) {
      a.push_back(x);
    } else {
      b.push_back(-x);
    }
    mx = max(abs(x), mx);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int64_t ans_a = 0, ans_b = 0;
  for (int64_t i = 0; int64_t(a.size()) - 1 >= k * i; i++) {
    ans_a += a[int64_t(a.size()) - k * i - 1];
  }
  for (int64_t i = 0; int64_t(b.size()) - 1 >= k * i; i++) {
    ans_b += b[int64_t(b.size()) - k * i - 1];
  }
  cout << 2 * (ans_a + ans_b) - mx << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int64_t t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
