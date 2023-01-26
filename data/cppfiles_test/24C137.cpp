#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
const long long base = 311;
long long gcd(long long a, long long b) {
  while (b != 0) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long binmul(long long a, long long b) {
  if (b == 0) return 0;
  long long v = binmul(a, b / 2);
  long long res = v + v;
  if (res >= mod) res -= mod;
  if (b % 2) {
    res += a;
    if (res >= mod) res -= mod;
  }
  return res;
}
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long v = binpow(a, b / 2);
  if (b % 2) return v * v % mod * a % mod;
  return v * v % mod;
}
long long bpowmul(long long a, long long b) {
  if (b == 0) return 1;
  long long v = bpowmul(a, b / 2);
  if (b % 2) return binmul(binmul(v, v), a);
  return binmul(v, v);
}
const int MaxN = 2e5 + 4;
long long n;
void solve() {
  cin >> n;
  cout << (n + 1) / 10 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) solve();
  return 0;
}
