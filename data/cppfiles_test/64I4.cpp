#include <bits/stdc++.h>
using namespace std;
bool prime(long long x) {
  if (x % 2 == 0) return 0;
  for (long long i = 3; i * i <= x; i += 2) {
    if (x % i == 0) return 0;
  }
  return 1;
}
long long power(long long x, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
long long n, m, MOD, MOD2;
string s, x;
long long p1[500005], p2[500005], h1[500005], h2[500005], z[700005], x1, x2;
mt19937_64 rng;
pair<long long, long long> get(long long l, long long r) {
  long long res1 = ((h1[r] - h1[l - 1] * p1[r - l + 1]) % MOD + MOD) % MOD;
  long long res2 = ((h2[r] - h2[l - 1] * p2[r - l + 1]) % MOD2 + MOD2) % MOD2;
  return {res1, res2};
}
void check(long long l, long long r, long long L, long long R) {
  auto v1 = get(l, r), v2 = get(L, R);
  if ((v1.first + v2.first) % MOD == x1 &&
      (v1.second + v2.second) % MOD2 == x2) {
    cout << l << " " << r << "\n" << L << " " << R;
    exit(0);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  rng.seed((long long)main ^ time(NULL));
  MOD = rng() % 1500000000 + 1500000000;
  MOD2 = rng() % 1500000000 + 1500000000;
  while (!prime(MOD)) MOD++;
  while (!prime(MOD2)) MOD2++;
  cin >> s >> x;
  n = (long long)s.size();
  m = (long long)x.size();
  x += '$';
  x += s;
  for (long long i = 1, l = 0, r = 0; i < (long long)x.size(); ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < (long long)x.size() && x[z[i]] == x[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  p1[0] = 1;
  p2[0] = 1;
  for (long long i = 1; i <= n; i++) {
    p1[i] = p1[i - 1] * 10 % MOD;
    p2[i] = p2[i - 1] * 10 % MOD2;
  }
  for (long long i = 1; i <= n; i++) {
    h1[i] = (h1[i - 1] * 10 + (s[i - 1] - '0')) % MOD;
    h2[i] = (h2[i - 1] * 10 + (s[i - 1] - '0')) % MOD2;
  }
  for (long long i = 1; i <= m; i++) {
    x1 = (x1 * 10 + (x[i - 1] - '0')) % MOD;
    x2 = (x2 * 10 + (x[i - 1] - '0')) % MOD2;
  }
  for (long long i = 1; i <= n - 2 * (m - 1) + 1; i++)
    check(i, i + m - 2, i + m - 1, i + 2 * m - 3);
  for (long long i = 1; i <= n - m + 1; i++) {
    long long sz = m - z[i + m];
    if (i - sz >= 1) check(i - sz, i - 1, i, i + m - 1);
    sz--;
    if (i - sz >= 1) check(i - sz, i - 1, i, i + m - 1);
    sz++;
    if (i + m - 1 + sz <= n) check(i, i + m - 1, i + m, i + m + sz - 1);
    sz--;
    if (i + m - 1 + sz <= n) check(i, i + m - 1, i + m, i + m + sz - 1);
  }
}
