#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 100 + 7;
typedef struct {
  int n;
  long long a[N][N];
} Matrix;
Matrix a;
inline long long quick_pow(long long x, long long p, long long mod) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = ans * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return ans;
}
inline void gauss(Matrix &a, int mod) {
  int ni = a.n + 1;
  for (int i = 1; i <= a.n; i++) {
    long long cur_inv;
    if (a.a[i][i] == 0) {
      int t;
      for (int j = i + 1; j <= a.n; j++) {
        if (a.a[j][i] != 0) {
          t = j;
          break;
        }
      }
      for (int j = 1; j <= ni; j++) {
        swap(a.a[i][j], a.a[t][j]);
      }
    }
    cur_inv = quick_pow(a.a[i][i], mod - 2, mod);
    for (int j = i + 1; j <= a.n; j++) {
      long long t = cur_inv * a.a[j][i] % mod;
      for (int k = i; k <= ni; k++) {
        a.a[j][k] = ((a.a[j][k] - t * a.a[i][k] % mod) % mod + mod) % mod;
      }
    }
  }
  for (int i = a.n; i >= 1; i--) {
    for (int j = i + 1; j <= a.n; j++) {
      a.a[i][ni] =
          ((a.a[i][ni] - a.a[i][j] * a.a[j][ni] % mod) % mod + mod) % mod;
    }
    a.a[i][ni] = a.a[i][ni] * quick_pow(a.a[i][i], mod - 2, mod) % mod;
  }
}
using namespace std;
int x[100007], y[100007], pos[107];
map<int, int> mp[100007];
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, m, rb, cb, rd, cd, p, loop = 0;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    for (int i = 1; i <= n; i++) {
      mp[i].clear();
    }
    int dr = 1, dc = 1;
    while (!mp[rb].count(cb)) {
      if (rb + dr < 1 || rb + dr > n) dr = -dr;
      if (cb + dc < 1 || cb + dc > m) dc = -dc;
      loop++;
      x[loop] = rb;
      y[loop] = cb;
      mp[rb][cb] = true;
      rb += dr;
      cb += dc;
    }
    int cnt = 0;
    for (int i = 1; i <= loop; i++) {
      if (x[i] == rd || y[i] == cd) {
        pos[++cnt] = i;
      }
    }
    a.n = cnt;
    memset(a.a, 0, sizeof(a.a));
    long long fuck = mod - p * quick_pow(100, mod - 2, mod) % mod;
    for (int i = 1; i <= cnt; i++) {
      int pre = i == 1 ? cnt : i - 1;
      int dis =
          i == 1 ? (loop - pos[cnt] + 1) + pos[i] - 1 : pos[i] - pos[i - 1];
      a.a[i][pre] = 1;
      a.a[i][i] = mod - fuck;
      a.a[i][cnt + 1] = fuck * dis % mod;
    }
    gauss(a, mod);
    long long ans = 0;
    for (int i = 1; i <= cnt; i++) {
      ans = (ans + a.a[i][cnt + 1]) % mod;
    }
    cout << ans * quick_pow(cnt, mod - 2, mod) % mod << endl;
  }
  return 0;
}
