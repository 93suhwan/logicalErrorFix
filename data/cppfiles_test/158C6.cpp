#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10;
const int MAXM = 10000;
char buff[MAXM + 10];
int x[MAXN];
int a[MAXN][MAXM];
int ac[MAXN];
int c[MAXM];
int d[MAXN * 2 + 2];
int p[MAXM];
int pi[MAXM];
int best[MAXM];
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
  fill(ac, ac + n, 0);
  for (int i = 0; i < n; ++i) {
    scanf("\n%s", buff);
    for (int j = 0; j < m; ++j)
      if (buff[j] == '1') {
        a[i][ac[i]] = j;
        ++ac[i];
      }
  }
  long long ans = -(1LL << 62);
  int mask_n = 1 << n;
  for (int mask = 0; mask < mask_n; ++mask) {
    fill(c, c + m, 0);
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        int z = ac[i];
        for (int j = 0; j < z; ++j) c[a[i][j]] -= 1;
      } else {
        int z = ac[i];
        for (int j = 0; j < z; ++j) c[a[i][j]] += 1;
      }
    }
    fill(d, d + (2 * n + 2), 0);
    for (int j = 0; j < m; ++j) ++d[c[j] + n + 1];
    for (int j = 1; j < 2 * n + 2; ++j) d[j] += d[j - 1];
    for (int j = 0; j < m; ++j) {
      int &z = d[c[j] + n];
      pi[z] = j;
      ++z;
    }
    for (int j = 0; j < m; ++j) p[pi[j]] = j + 1;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
      int y = 0;
      int z = ac[i];
      for (int j = 0; j < z; ++j) y += p[a[i][j]];
      res += abs(y - x[i]);
    }
    if (ans < res) {
      ans = res;
      for (int j = 0; j < m; ++j) best[j] = p[j];
    }
  }
  for (int i = 0; i < m; ++i) printf("%d ", best[i]);
  printf("\n");
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) solve();
  return 0;
}
