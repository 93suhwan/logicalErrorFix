#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
const long long mod = 1e9 + 7;
long long mpow(long long a, long long x) {
  if (x == 0) return 1;
  long long t = mpow(a, x >> 1);
  if (x % 2 == 0) return t * t % mod;
  return t * t % mod * a % mod;
}
long long pr[30][1 << 15];
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<long long> f(1 << n, 0), g(1 << n, 0);
  long long p[30][30];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      p[i][j] = a[i] * mpow(a[i] + a[j], mod - 2) % mod;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 1 << n; j++) {
      pr[i][j] = 1;
      for (int k = 0; k < n; k++)
        if (j >> k & 1) {
          pr[i][j] = pr[i][j] * p[i][k] % mod;
        }
    }
  }
  long long ans = 0;
  for (int i = 1; i < 1 << n; i++) {
    g[i] = 1;
    for (int s = i; s > 0; s = i & (s - 1)) {
      if (s == i) continue;
      long long tmp = g[s];
      for (int x = 0; x < n; x++)
        if (s >> x & 1) {
          tmp = tmp * pr[x][s ^ i] % mod;
        }
      g[i] = g[i] - tmp;
      g[i] = (g[i] % mod + mod) % mod;
    }
  }
  for (int s = 1; s < 1 << n; s++) {
    long long tmp = g[s];
    for (int x = 0; x < n; x++)
      if (s >> x & 1) {
        tmp = tmp * pr[x][s ^ ((1 << n) - 1)] % mod;
      }
    int c = 0;
    for (int i = 0; i < n; i++)
      if (s >> i & 1) c++;
    ans = ans + tmp * c % mod;
    ans = (ans % mod + mod) % mod;
  }
  cout << ans << "\n";
}
