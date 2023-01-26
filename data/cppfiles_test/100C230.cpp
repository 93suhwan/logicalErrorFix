#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
const long long MX = 2e5 + 105;
const long long MOD = 998244353;
inline void normal(long long &a) {
  a %= MOD;
  (a < 0) && (a += MOD);
}
inline long long modMul(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a * b) % MOD;
}
inline long long modAdd(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a + b) % MOD;
}
inline long long modSub(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1LL) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1LL;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, MOD - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
long long fact[MX];
long long ara[MX];
void factorial() {
  fact[0] = 1;
  for (long long i = 1; i < MX; i++) fact[i] = modMul(fact[i - 1], i);
}
long long ncr(long long n, long long r) {
  if (n < r) return 0;
  long long ans = modMul(fact[r], fact[n - r]);
  ans = modDiv(fact[n], ans);
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ara[i];
  }
  sort(ara, ara + n);
  if (ara[n - 2] == ara[n - 1]) {
    cout << fact[n] << endl;
    return;
  }
  if (ara[n - 1] - ara[n - 2] > 1) {
    cout << 0 << endl;
    return;
  }
  long long c = 1;
  for (int i = n - 3; i >= 0; i--) {
    if (ara[i] == ara[i + 1])
      c++;
    else
      break;
  }
  long long ans = ncr(n, c + 1);
  ans = modMul(ans, fact[n - c - 1]);
  ans = modMul(ans, fact[c]);
  ans = modSub(fact[n], ans);
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  factorial();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
