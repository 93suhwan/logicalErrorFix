#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long updiv(long long a, long long b) {
  if (a % b == 0)
    return (a / b);
  else
    return (a / b) + 1;
}
long long mymod(long long x, long long m) {
  if (x > 0)
    return x % m;
  else
    return ((x) % (m) + (m)) % (m);
}
long long XOR(long long n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
long long G(long long x) {
  long long a = x % 8;
  if (a == 0 || a == 1) return x;
  if (a == 2 || a == 3) return 2;
  if (a == 4 || a == 5) return x + 2;
  if (a == 6 || a == 7) return 0;
  return 0;
}
long long countSetBits(long long n) {
  if (n == 0)
    return 0;
  else
    return 1 + countSetBits(n & (n - 1));
}
long long spf[10000001];
void sieve() {
  spf[1] = 1;
  for (long long i = 2; i < 10000001; i++) spf[i] = i;
  for (long long i = 4; i < 10000001; i += 2) spf[i] = 2;
  for (long long i = 3; i * i < 10000001; i++) {
    if (spf[i] == i) {
      for (long long j = i * i; j < 10000001; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
map<long long, long long> mp;
long long getFactorization(long long x) {
  vector<long long> ret;
  long long ans = 1;
  mp.clear();
  while (x != 1) {
    mp[spf[x]]++;
    x = x / spf[x];
  }
  for (auto P : mp) {
    if (P.second % 2 == 1) ans *= P.first;
  }
  return ans;
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
void solve() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long c2 = n / 3;
  if (n % 3 == 2) {
    c2++;
  }
  long long c1 = n - (2 * c2);
  cout << c1 << " " << c2 << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
