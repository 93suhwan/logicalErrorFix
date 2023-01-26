#include <bits/stdc++.h>
using namespace std;
const int dx[9] = {0, 0, -1, 1, -1, -1, 1, 1, 0};
const int dy[9] = {-1, 1, 0, 0, -1, 1, -1, 1, 0};
const long long MOD = 998244353;
const int N = 1e5 + 10;
int n;
string va[N];
long long fac[N];
long long qsm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % MOD;
    x = (x * x) % MOD;
    y >>= 1;
  }
  return res;
}
long long inv(long long x) { return qsm(x, MOD - 2); }
long long C(long long x, long long y) {
  return fac[x] * inv(fac[y]) % MOD * inv(fac[x - y]) % MOD;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = (fac[i - 1] * i) % MOD;
}
void solve() {
  init();
  long long b1 = 0, w2 = 0, q1 = 0, q2 = 0, x = 0, y = 0, z = 0;
  for (int i = 1; i <= n; i++) {
    b1 += va[i][0] == 'B';
    w2 += va[i][1] == 'W';
    q1 += va[i][0] == '?';
    q2 += va[i][1] == '?';
    x += va[i] == "WB" || va[i] == "W?" || va[i] == "?B";
    y += va[i] == "BW" || va[i] == "B?" || va[i] == "?W";
    z += va[i] == "??";
  }
  long long ans = 0;
  for (long long i = 0; i <= q1; i++) {
    long long j = b1 + i - w2;
    if (j >= 0 && j <= q2) {
      ans = (ans + C(q1, i) * C(q2, j) % MOD) % MOD;
    }
  }
  for (long long i = 0; i <= z; i++) {
    if (x + y + z == n && x + i >= 1 && y + z - i >= 1) {
      ans = (ans - C(z, i) + MOD) % MOD;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> va[i];
  solve();
  return 0;
}
