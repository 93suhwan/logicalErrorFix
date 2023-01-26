#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 998244353, gn = 3;
const int inf = 2147483647;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10ll + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void up(int& x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int Pow(int x, int y) {
  if (!y) return 1;
  int t = Pow(x, y >> 1);
  t = (long long)t * t % mod;
  if (y & 1) t = (long long)t * x % mod;
  return t;
}
int n, a[N], m = 0, b[N];
struct DP {
  vector<int> f[2][2];
  DP(vector<int> _f[2][2]) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) f[i][j] = _f[i][j];
  }
};
int rev[N << 2], pw[2][N << 2];
void NTT(vector<int>& a, int n, int o) {
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int i = 1; i < n; i <<= 1) {
    int wn;
    if (o == 1)
      wn = pw[0][i];
    else
      wn = pw[1][i];
    for (int j = 0; j < n; j += (i << 1)) {
      int w = 1;
      for (int k = 0; k < i; k++) {
        int t = (long long)w * a[i + j + k] % mod;
        w = (long long)w * wn % mod;
        a[i + j + k] = (a[j + k] - t + mod) % mod;
        a[j + k] = (a[j + k] + t) % mod;
      }
    }
  }
}
vector<int> E[2][2];
int M, INV, len;
vector<int> Mul(vector<int> a, vector<int> b) {
  vector<int> c;
  a.resize(M + 1), b.resize(M + 1), c.resize(M + 1);
  NTT(a, M, 1), NTT(b, M, 1);
  for (int i = 0; i <= M; i++) c[i] = (long long)a[i] * b[i] % mod;
  NTT(c, M, -1);
  for (int i = 0; i <= M; i++) c[i] = (long long)c[i] * INV % mod;
  c[0] = 0;
  while (c.size() > len) c.pop_back();
  return c;
}
DP solve(int l, int r) {
  if (l == r) {
    vector<int> t[2][2];
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) t[i][j].resize(2);
    if (b[l] == 1)
      t[1][1][1] = 1;
    else
      t[0][0][1] = 2;
    return DP(t);
  }
  int mid = l + r >> 1;
  DP L = solve(l, mid), R = solve(mid + 1, r);
  DP res = DP(E);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) res.f[i][j].resize(r - l + 2);
  int L1, R1, L2, R2;
  L1 = (b[l] == 1);
  R1 = (b[mid] == 1);
  L2 = (b[mid + 1] == 1);
  R2 = (b[r] == 1);
  M = 1, len = r - l + 2;
  while (M <= r - l + 1) M <<= 1;
  rev[0] = 0;
  for (int i = 1; i < M; i++)
    rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) * (M >> 1)));
  INV = Pow(M, mod - 2);
  for (int l1 = 0; l1 <= L1; l1++)
    for (int r1 = 0; r1 <= R1; r1++)
      for (int l2 = 0; l2 <= L2; l2++)
        for (int r2 = 0; r2 <= R2; r2++) {
          vector<int> tmp = Mul(L.f[l1][r1], R.f[l2][r2]);
          for (int i = 2; i <= r - l + 1; i++) up(res.f[l1][r2][i], tmp[i]);
          int ll = l1, rr = r2;
          if (l == mid) ll = 0;
          if (mid + 1 == r) rr = 0;
          int v = 1;
          if (!r1 && !l2)
            v = (mod + 1) / 2;
          else if (r1 && l2)
            v = 2;
          for (int i = 1; i <= r - l; i++)
            up(res.f[ll][rr][i], (long long)tmp[i + 1] * v % mod);
        }
  return res;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  int u = 1;
  while (u <= 2 * n) u <<= 1;
  for (int i = 1; i < u; i++) {
    pw[0][i] = Pow(gn, (mod - 1) / (i << 1));
    pw[1][i] = Pow(gn, mod - 1 - (mod - 1) / (i << 1));
  }
  int l = 1, cnt = 0;
  while (l <= n) {
    m++;
    int r = l + a[l] - 1;
    cnt += (l == r);
    b[m] = r - l + 1;
    for (int i = l + 1; i <= r; i++)
      if (a[i] != a[i - 1]) {
        cout << 0 << endl;
        return 0;
      }
    l = r + 1;
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) E[i][j].clear();
  DP res = solve(1, m);
  int ans = 0, fac = 1;
  for (int i = 1; i <= m; i++) {
    int t = 0;
    fac = (long long)fac * i % mod;
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) up(t, res.f[j][k][i]);
    t = (long long)t * fac % mod;
    if ((i & 1) == (m & 1))
      up(ans, t);
    else
      up(ans, mod - t);
  }
  cout << ans;
}
