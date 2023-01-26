#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 500 + 7;
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
      if (a.a[j][i] == 0) continue;
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
int x[100007], y[100007], pos[100007];
set<tuple<int, int, int, int> > s;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, m, rb, cb, rd, cd, p, loop = 0;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    int tx = rb, ty = cb;
    int dr = 1, dc = 1;
    s.clear();
    while (true) {
      if (rb + dr < 1 || rb + dr > n) dr = -dr;
      if (cb + dc < 1 || cb + dc > m) dc = -dc;
      loop++;
      x[loop] = rb;
      y[loop] = cb;
      rb += dr;
      cb += dc;
      auto tp = make_tuple(rb, cb, dr, dc);
      if (s.count(tp)) {
        loop--;
        break;
      }
      s.insert(tp);
    }
    int cnt = 0;
    for (int i = 1; i <= loop; i++) {
      if (x[i] == rd || y[i] == cd) pos[++cnt] = i;
    }
    a.n = cnt;
    memset(a.a, 0, sizeof(a.a));
    long long fuck = (100 - p) * quick_pow(100, mod - 2, mod) % mod;
    cout << loop << endl;
    for (int i = 1; i <= cnt; i++) {
      int pre = i == 1 ? cnt : i - 1;
      int dis = i == 1 ? (loop - pos[cnt] + 1) + pos[i] - 1 : pos[i] - pos[pre];
      a.a[i][pre] = 1;
      a.a[i][i] = (a.a[i][i] + mod - fuck) % mod;
      a.a[i][cnt + 1] = fuck * dis % mod;
    }
    gauss(a, mod);
    cout << (a.a[1][cnt + 1] + pos[1] - 1) % mod << endl;
  }
  return 0;
}
