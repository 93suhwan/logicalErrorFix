#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 123;
signed main() {
  setlocale(LC_ALL, "rus");
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<long long> b(n);
  for (long long i = 0; i < n; ++i) {
    if (i & 1 ^ 1) {
      b[i] = a[i];
    } else {
      b[i] = -a[i];
    }
  }
  vector<long long> pref(n);
  pref[0] = b[0];
  for (long long i = 1; i < n; ++i) {
    pref[i] = pref[i - 1] + b[i];
  }
  auto get = [&](long long l, long long r) {
    if (l > r) {
      return 0ll;
    }
    long long big = pref[r];
    long long small = 0;
    if (l) {
      small = pref[l - 1];
    }
    return big - small;
  };
  long long ans = 0;
  for (long long i = 0; i < n - 1; i += 2) {
    long long mx_open = 0;
    long long mx_close = 0;
    for (long long j = i + 1; j < n; ++j) {
      if (j % 2 == 0) {
        mx_open = max(mx_open, a[j]);
        continue;
      }
      if (a[i] < mx_close) {
        continue;
      }
      if (a[j] < mx_open) {
        continue;
      }
      long long x = a[i], y = a[j];
      long long bal = get(i + 1, j - 1);
      long long val = 0;
      if (bal < 0) {
        val = min(x - abs(bal), y);
      } else if (bal > 0) {
        val = min(x, y - abs(bal));
      } else {
        val = min(x, y);
      }
      ans += max(0ll, val);
      mx_close = max(mx_close, a[j]);
    }
  }
  cout << ans;
}
