#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0)
    return b;
  else if (b == 0)
    return a;
  if (a > b)
    return gcd(a % b, b);
  else
    return gcd(b % a, a);
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInv(long long int a, long long int b) {
  return power(a, b - 2, b);
}
long long int add(long long int a, long long int b, long long int MOD) {
  long long int r = a + b;
  if (r >= MOD) r -= MOD;
  if (r < 0) r += MOD;
  return r;
}
long long int mul(long long int a, long long int b, long long int MOD) {
  long long int r = (a % MOD) * (b % MOD);
  r %= MOD;
  if (r < 0) r += MOD;
  return r;
}
long long int Min3(long long int a, long long int b, long long int c) {
  if (a < b)
    return (a < c ? a : c);
  else
    return (b < c ? b : c);
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
void solve() {
  long long int n, c0 = 0, c1 = 0;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] == 0)
      c0++;
    else if (v[i] == 1)
      c1++;
  }
  long long int ans = c1 * (power(2, c0));
  cout << ans << "\n";
}
signed main() {
  clock_t start, end;
  start = clock();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tcs = 1;
  cin >> tcs;
  while (tcs--) solve();
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cerr << time_taken << " sec";
  return 0;
}
