#include <bits/stdc++.h>
using namespace std;
inline void wt(long long x) { cout << x; }
inline void wtl(long long x) { cout << x << '\n'; }
inline void wtb(long long x) { cout << x << ' '; }
inline void wt(char x) { cout << x; }
inline void wtl(char x) { cout << x << '\n'; }
inline void wtb(char x) { cout << x << ' '; }
inline void wt(string x) { cout << x; }
inline void wtl(string x) { cout << x << '\n'; }
inline void wtb(string x) { cout << x << ' '; }
template <typename T>
bool ckmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool ckmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
long long qmi(long long a, long long k, long long p) {
  long long res = 1;
  while (k) {
    if (k & 1) res = (long long)res * a % p;
    a = (long long)a * a % p;
    k >>= 1;
  }
  return res;
}
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res *= a;
    b >>= 1;
    a *= a;
  }
  return res;
}
long long mo(long long x, long long p) { return x = ((x % p) + p) % p; }
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const long long maxn = 1e6 + 7;
const long long mod = 1e9 + 7;
long long dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
long long fact[maxn], infact[maxn];
void jie_init(long long n) {
  fact[0] = 1;
  for (long long i = (1); i <= (n); i++) fact[i] = fact[i - 1] * i % mod;
  infact[n] = qmi(fact[n], mod - 2, mod);
  for (long long i = (n - 1); i >= (0); i--)
    infact[i] = infact[i + 1] * (i + 1) % mod;
}
long long C(long long n, long long m) {
  return fact[n] * infact[m] % mod * infact[n - m] % mod;
}
long long T = 1, N, M, K;
long long A[maxn], B[maxn], dp[maxn], f[maxn];
void solve() {
  cin >> N >> M >> K;
  long long blo = N / M;
  long long up = N % M;
  long long down = M - up;
  long long now = 1;
  for (long long i = (1); i <= (K); i++) {
    for (long long j = (1); j <= (down); j++) {
      wtb(blo);
      for (long long k = (1); k <= (blo); k++) {
        wtb(now);
        now++;
        if (now > N) now = 1;
      }
      cout << '\n';
    }
    long long temp = now;
    for (long long j = (1); j <= (up); j++) {
      wtb(blo + 1);
      for (long long k = (1); k <= (blo + 1); k++) {
        wtb(temp);
        temp++;
        if (temp > N) temp = 1;
      }
      cout << '\n';
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) solve();
  return (0 - 0);
}
