#include <bits/stdc++.h>
using namespace std;
int64_t fexp(int64_t a, int64_t b) {
  int64_t res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int64_t> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    a[i] = fexp((int64_t)10, (int64_t)a[i]);
  }
  vector<int64_t> b(n, LLONG_MAX);
  for (int i = 1; i < n; i++) {
    b[i - 1] = a[i] / a[i - 1];
    b[i - 1]--;
    if (b[i - 1] > k) b[i - 1] = k;
  }
  b[n - 1] = k;
  int64_t sum = 0;
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] == LLONG_MAX) {
      int64_t need = (k + 1) - sum;
      ans += need * a[i];
      break;
    }
    if (sum >= k - b[i]) {
      int64_t need = (k + 1) - sum;
      ans += need * a[i];
      break;
    } else {
      sum += b[i];
      ans += b[i] * a[i];
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
