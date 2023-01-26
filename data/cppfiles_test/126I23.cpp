#include <bits/stdc++.h>
long double a0[(1000 * 2 + 1000)], aa[(1000 * 2 + 1000)][(1000 * 2)];
long double z0, zz[(1000 * 2)];
void pivot(int n, int m, int i_) {
  static long double bb[(1000 * 2)];
  long double t, t_ = 1000000000, a, b0;
  int i, j, j_;
  for (j = 0; j < m; j++)
    if ((a = aa[j][i_]) < 0)
      if (t_ > (t = -a0[j] / a)) {
        t_ = t;
        j_ = j;
      }
  a = aa[j_][i_];
  b0 = -a0[j_] / a;
  assert(fabsl(floor(b0) - b0) < 1e-9);
  for (i = 0; i < n; i++) bb[i] = (i == i_ ? 1 : -aa[j_][i]) / a;
  for (j = 0; j < m; j++)
    if (j == j_) {
      a0[j] = b0;
      for (i = 0; i < n; i++) aa[j][i] = bb[i];
    } else {
      a = aa[j][i_];
      aa[j][i_] = 0;
      a0[j] += a * b0;
      for (i = 0; i < n; i++) aa[j][i] += a * bb[i];
    }
  a = zz[i_];
  zz[i_] = 0;
  z0 += a * b0;
  for (i = 0; i < n; i++) zz[i] += a * bb[i];
}
void solve(int n, int m) {
  while (1) {
    int i, cnt;
    cnt = 0;
    for (i = 0; i < n; i++)
      if (zz[i] > 0) cnt++;
    if (cnt == 0) break;
    cnt = rand() % cnt + 1;
    for (i = 0; i < n; i++)
      if (zz[i] > 0)
        if (--cnt == 0) break;
    pivot(n, m, i);
  }
}
int main() {
  static int vv[1000];
  int n, m, m_, i, j;
  srand(time(NULL));
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d", &vv[i]);
  m_ = 0;
  for (i = 0; i < n; i++) {
    a0[m_] = vv[i], aa[m_][i << 1 | 0] = -1, m_++;
    a0[m_] = 1000000000, aa[m_][i << 1 | 1] = -1, m_++;
  }
  while (m--) {
    scanf("%d%d", &i, &j), i--, j--;
    a0[m_] = 0, aa[m_][i << 1 | 0] = -1, aa[m_][i << 1 | 1] = -1,
    aa[m_][j << 1 | 0] = 1, aa[m_][j << 1 | 1] = 1, m_++;
  }
  for (i = 0; i < n; i++) zz[i << 1 | 0] = 1, zz[i << 1 | 1] = -1;
  solve(n * 2, m_);
  z0 = -z0;
  for (i = 0; i < n; i++) z0 += vv[i];
  printf("%lld\n", (long long)round(z0));
  return 0;
}
