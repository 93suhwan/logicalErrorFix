#include <bits/stdc++.h>
using namespace std;
void test_case() {
  long long l = 0, r = 1e12;
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  auto ok = [&](long long k) {
    vector<long long> tmp(n + 3), extra(n + 3);
    for (long long i = n - 1; i >= 0; i--) {
      tmp[i] = arr[i];
      if (i <= 1) continue;
      long long give = 0;
      if (tmp[i] + extra[i] >= k) {
        give = tmp[i] + extra[i] - k;
        give = min(give, tmp[i]);
      } else
        return false;
      extra[i - 1] += give / 3;
      extra[i - 2] += (give / 3) * 2;
      tmp[i] -= (give / 3) * 3;
    }
    for (long long i = 0; i < n; i++) {
      if (tmp[i] + extra[i] < k) return false;
    }
    return true;
  };
  long long res = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (ok(mid)) {
      res = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << res;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    test_case();
    cout << '\n';
  }
  return 0;
}
