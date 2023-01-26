#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 10;
const long long mod = 1e9 + 7;
void solve();
void findDivisors(long long n);
void sieve(long long n);
long long mpow(long long base, long long exp, long long md);
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
long long ncr(long long n, long long r);
long long highestPowerOf2(long long n);
long long count_digit(long long number);
long long sum_digit(long long n);
long long sum_digit(string str);
string dec2bin(long long n);
void solve() {
  long long m;
  cin >> m;
  long long a[m], b[m];
  for (long long i = 0; i < m; ++i) cin >> a[i];
  for (long long i = 0; i < m; ++i) cin >> b[i];
  long long l = 0, r = m - 1;
  long long sum1 = 0, sum2 = 0;
  while (l <= r) {
    if (l == r) break;
    if (sum1 > sum2) {
      sum2 += a[r--];
    } else {
      sum1 += a[l++];
    }
  }
  long long t = 0, t2 = 0;
  for (long long i = 0; i < m - 1; ++i) {
    t += b[i];
    t2 += a[i + 1];
  }
  cout << min(max(sum1, sum2), min(t, t2)) << '\n';
}
int32_t main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long T = 1, cse = 0;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
void findDivisors(long long n) {
  long long div[N];
  memset(div, 0, sizeof div);
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j * i <= n; j++) div[i * j]++;
  }
}
void sieve(long long n) {
  vector<long long> primes;
  bool iscomp[N];
  for (long long i = 2; i <= n; ++i) {
    if (!iscomp[i]) primes.push_back(i);
    for (long long j = 0; j < primes.size() && i * primes[j] <= n; ++j) {
      iscomp[i * primes[j]] = true;
      if (i % primes[j] == 0) break;
    }
  }
}
long long mpow(long long base, long long exp, long long md = mod) {
  long long result = 1;
  base %= md;
  if (base == 0) return 0;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % md;
    base = (base * base) % md;
    exp >>= 1;
  }
  return result;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long ncr(long long n, long long r) {
  vector<long long> fac(N), inv(N);
  return fac[n] * (inv[r] * inv[n - r] % mod) % mod;
  return fac[n] * (mpow(fac[r], mod - 2) * mpow(fac[n - r], mod - 2) % mod) %
         mod;
}
long long highestPowerOf2(long long n) { return (n & (~(n - 1))); }
long long count_digit(long long number) { return int32_t(log10(number) + 1); }
long long sum_digit(long long n) {
  long long sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}
long long sum_digit(string str) {
  long long sum = 0;
  for (long long i = 0; i < str.length(); i++) {
    sum = sum + str[i] - 48;
  }
  return sum;
}
string dec2bin(long long n) {
  const long long size = sizeof(n) * 8;
  string s = "00000000000000000000000000000000";
  for (long long a = 0; a < 32; a++) {
    if (n == 0)
      return s;
    else {
      if (n % 2 != 0) s[31 - a] = '1';
      n /= 2;
    }
  }
  return s;
}
