#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long MOD = 1e9 + 7;
int power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long n, k, i, m;
  cin >> k;
  n = power(2, k, MOD) - 1;
  long long res = power(4, n - 1, MOD);
  res = res * 6;
  res %= MOD;
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  long long n, x;
  while (t--) {
    solve();
  }
  return 0;
}
