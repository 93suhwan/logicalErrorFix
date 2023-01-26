#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const long double eps = 1e-6;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long fact[200001];
int power(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = (res * 1LL * a) % mod;
    a = (a * 1LL * a) % mod;
    b /= 2;
  }
  return res;
}
int C(int n, int r) {
  if (r > n) return 0;
  int res = fact[n];
  res = (res * 1LL * power(fact[r], mod - 2)) % mod;
  res = (res * 1LL * power(fact[n - r], mod - 2)) % mod;
  return res;
}
void solve() {
  long long n;
  cin >> n;
  long long ans = fact[2 * n];
  long long inv = power(2, mod - 2);
  cout << (ans * inv) % mod << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t;
  cin >> t;
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= 200000; i++) {
    fact[i] = (fact[i - 1] * i * 1LL) % mod;
  }
  while (t--) {
    solve();
  }
};
