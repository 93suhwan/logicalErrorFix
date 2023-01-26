#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const long long INF64 = 0x3f3f3f3f3f3f3f3f;
const long long INF32 = 0x3f3f3f3f;
const long long MOD = 1000000007;
void solve() {
  long long n, q;
  cin >> n >> q;
  vector<long long> a(n), sum(n + 1);
  sum[0] = 0;
  for (long long i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '+') {
      if (i % 2 == 0) {
        a[i] = 1;
      } else {
        a[i] = -1;
      }
    } else {
      if (i % 2 == 0) {
        a[i] = -1;
      } else {
        a[i] = 1;
      }
    }
    sum[i + 1] = sum[i] + a[i];
  }
  while (q--) {
    long long l, r;
    cin >> l >> r;
    if ((l - r) % 2 == 0) {
      cout << 1 << '\n';
    } else {
      if (sum[r] - sum[l - 1] == 0) {
        cout << 0 << '\n';
      } else {
        cout << 2 << '\n';
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) solve();
}
