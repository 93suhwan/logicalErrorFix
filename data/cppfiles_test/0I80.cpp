#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, N = 3e6 + 3, bb = 32;
vector<long long> fact(N), rfact(N);
long long binpow(long long a, long long b) {
  if (!b) return 1;
  if (b & 1) return a * binpow(a, b - 1) % mod;
  long long t = binpow(a, b / 2);
  return t * t % mod;
}
long long C(long long n, long long k) {
  if (k > n or k < 0) return 0;
  long long res = fact[n] * rfact[k] % mod;
  return res * rfact[n - k] % mod;
}
vector<long long> divide(vector<long long> p, vector<long long> s) {
  long long n = p.size(), m = s.size();
  vector<long long> res;
  for (long long i = n - 1; i >= m - 1; --i) {
    long long mul = p[i];
    for (long long j = 0; j < m; ++j) {
      p[i - j] -= mul * s[m - 1 - j] % mod;
      p[i - j] = (p[i - j] + mod) % mod;
    }
    res.push_back(mul);
  }
  reverse(res.begin(), res.end());
  return res;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fact[0] = rfact[0] = 1;
  for (long long i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i % mod;
    rfact[i] = binpow(fact[i], mod - 2);
  }
  long long n, q;
  cin >> n >> q;
  vector<long long> p(3 * n + 4), s(4);
  for (long long i = 0; i <= 3 * n + 3; ++i) {
    p[i] = C(3 * n + 3, i) - C(3, i);
  }
  for (long long i = 0; i <= 3; ++i) {
    s[i] = C(3, i) - C(0, i);
  }
  for (auto& x : p) x = (x + mod) % mod;
  for (auto& x : s) x = (x + mod) % mod;
  p = divide(p, s);
  while (q-- > 0) {
    long long x;
    cin >> x;
    cout << p[x] << '\n';
  }
  return 0;
}
