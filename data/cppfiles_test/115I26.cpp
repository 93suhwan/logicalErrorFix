#include <bits/stdc++.h>
using namespace std;
long long T = 1, n, k, mx, mn, i, j, x, sum, MOD = 1e9 + 7;
long long up(long long x, long long y) {
  if (x % y == 0) return x / y;
  return x / y + 1;
}
long long fastestPower(long long x, long long y) {
  if (y == 0) return 1;
  if (y & 1) return x * fastestPower(x, y - 1);
  long long z = fastestPower(x, y / 2);
  return z * z;
}
long long a[200];
long long health;
bool check(long long k) {
  long long me = health;
  for (i = 0; i < n; i++) {
    if (i == n - 1)
      me -= k;
    else {
      long long temp = a[i] + k - 1;
      if (temp < a[i + 1])
        me -= k;
      else {
        me -= a[i + 1] - a[i];
      }
    }
  }
  return (me <= 0);
}
long long bs() {
  long long b = 0, e = 1e18, ans = -1;
  while (b < e) {
    long long mid = (b + e) / 2;
    if (check(mid)) {
      ans = mid;
      e = mid - 1;
    } else
      b = mid + 1;
  }
  if (check(ans - 1)) --ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> health;
    for (i = 0; i < n; i++) cin >> a[i];
    a[n] = + +1e9;
    cout << bs() << "\n";
  }
  return 0;
}
