#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long binpower(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}
long long inv(long long a) { return binpower(a, MOD - 2); }
long long c(int n, int m) {
  long long s = 1;
  for (int i = n; i > n - m; i--) s = s * i % MOD;
  for (int i = 1; i <= m; i++) s = s * inv(i) % MOD;
  return s;
}
long long solve() {
  int n;
  cin >> n;
  long long pre = 1;
  char x[n][2];
  for (int i = 0; i < n; i++) {
    cin >> x[i][0] >> x[i][1];
  }
  for (int i = 0; i < n; i++) {
    if (x[i][0] == x[i][1] && x[i][0] != '?') {
      pre = 0;
      break;
    }
    if (x[i][0] == x[i][1]) pre = pre * 2 % MOD;
  }
  long long prewb = 1;
  for (int i = 0; i < n; i++) {
    if (x[i][0] == 'B' || x[i][1] == 'W') {
      prewb = 0;
      break;
    }
    if (x[i][0] == x[i][1]) prewb = prewb * 2 % MOD;
  }
  long long prebw = 1;
  for (int i = 0; i < n; i++) {
    if (x[i][0] == 'W' || x[i][1] == 'B') {
      prebw = 0;
      break;
    }
    if (x[i][0] == x[i][1]) prebw = prebw * 2 % MOD;
  }
  int cntw = 0, cntb = 0;
  for (int i = 0; i < n; i++) {
    if (x[i][0] == 'W') cntw++;
    if (x[i][1] == 'W') cntw++;
    if (x[i][0] == 'B') cntb++;
    if (x[i][1] == 'B') cntb++;
  }
  if (cntw > n || cntb > n) return 0;
  return (c(2 * n - cntw - cntb, n - cntw) - pre + prewb + prebw + MOD) % MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  int T = 1;
  while (T--) {
    long long ans = solve();
    cout << ans << endl;
  }
}
