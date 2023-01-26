#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> primefactor;
void primefac(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      long long cnt = 0;
      while (n % i == 0) {
        cnt++;
        n /= i;
      }
      pair<long long, long long> p = make_pair(i, cnt);
      primefactor.push_back(p);
    }
  }
  if (n > 1) {
    primefactor.push_back(make_pair(n, 1));
  }
}
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long fexp(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if ((b & 1) != 0) {
      ans = ((ans % m) * (a % m)) % m;
    }
    a = ((a % m) * (a % m)) % m;
    b >>= 1;
  }
  return ans;
}
long long f[200001];
void fac() {
  f[0] = 1;
  for (long long i = 1; i < 200001; i++) f[i] = (i * f[i - 1]) % 1000000007;
}
long long count_max_power_of_2_greaterthan_n(long long n) {
  long long res = 0, ans = 0;
  for (long long i = 1; i <= 50; i++) {
    ans = (1LL) << i;
    if (ans > n) {
      res = i;
      return res;
    }
  }
  return res;
}
long long inverse(long long a, long long p) { return fexp(a, p - 2, p); }
long long ncr(long long n, long long r, long long p) {
  if (r == 0) return 1;
  return (f[n] * inverse(f[r], p) % p * inverse(f[n - r], p) % p) % p;
}
void solve() {
  vector<long long> v(7);
  long long s = 0;
  for (long long i = 0; i < 7; i++) {
    cin >> v[i];
    s += v[i];
  }
  long long a = v[0];
  long long b = v[1];
  long long c = v[6] - a - b;
  cout << a << " " << b << " " << c << endl;
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
