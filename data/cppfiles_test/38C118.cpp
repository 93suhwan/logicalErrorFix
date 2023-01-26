#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool sort2(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
const long long INF = 1e18;
const int mod = 1e9 + 7;
const int mod2 = 998244353;
inline int add(int x, int y) {
  x += y;
  if (x >= mod) return x - mod;
  return x;
}
inline int sub(int x, int y) {
  x -= y;
  if (x < 0) return x + mod;
  return x;
}
inline int mul(int x, int y) { return (x * 1ll * y) % mod; }
inline int power(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = mul(ans, x);
    x = mul(x, x);
    y >>= 1;
  }
  return ans;
}
inline int inv(int x) { return power(x, mod - 2); }
const long long FACTORIAL_SIZE = 1.1e6;
long long fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
void gen_factorial(long long n) {
  fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (long long i = 2; i <= n; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
  ifact[n] = inv(fact[n]);
  for (long long i = n - 1; i >= 2; i--) {
    ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
  }
}
long long nck(long long n, long long k) {
  long long den = (ifact[k] * ifact[n - k]) % mod;
  return (den * fact[n]) % mod;
}
const int N = 2e5 + 5;
void solve() {
  long long n, m;
  cin >> n >> m;
  char c[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> c[i][j];
    }
  }
  long long a[m + 1];
  memset(a, 0, sizeof(a));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (i != 0 && j != 0 && c[i - 1][j] == 'X' && c[i][j - 1] == 'X') {
        a[j + 1] = 1;
      }
    }
  }
  for (long long i = 1; i <= m; i++) {
    a[i] += a[i - 1];
  }
  long long q;
  cin >> q;
  while (q--) {
    long long x1, x2;
    cin >> x1 >> x2;
    cout << ((a[x2] - a[x1] == 0) ? "YES" : "NO") << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tc = 1;
  long long i = 1;
  while (tc--) {
    solve();
    i++;
  }
  return 0;
}
