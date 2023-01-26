#include <bits/stdc++.h>
using namespace std;
int n, m;
array<int, 2> ex(array<int, 2> p, char c) {
  if (c == 'L')
    p[1]--;
  else if (c == 'R')
    p[1]++;
  else if (c == 'U')
    p[0]--;
  else
    p[0]++;
  return p;
}
bool inb(array<int, 2> p) {
  if (p[0] < 0 || p[0] >= n || p[1] < 0 || p[1] >= m) return 0;
  return 1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    static char cc[2000 * 2000 + 1];
    static int dd[2000 * 2000];
    int ans = -1, ansp = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", cc + (i * m));
    memset(dd, 0, n * m * sizeof(int));
    for (int i = 0; i < n * m; i++) {
      int i_, d;
      array<int, 2> k;
      if (dd[i]) continue;
      i_ = i, k = {i_ / m, i_ % m}, d = 0;
      while (inb(k) && dd[i_] == 0) {
        d++, dd[i_] = -1;
        k = ex(k, cc[i_]), i_ = k[0] * m + k[1];
      }
      if (!inb(k))
        ;
      else if (dd[i_] != -1)
        d += dd[i_];
      else {
        int c = 0;
        while (inb(k) && dd[i_] == -1) {
          c++, dd[i_] = -2;
          k = ex(k, cc[i_]), i_ = k[0] * m + k[1];
        }
        while (inb(k) && dd[i_] == -2) {
          dd[i_] = c;
          k = ex(k, cc[i_]), i_ = k[0] * m + k[1];
        }
      }
      i_ = i, k = {i_ / m, i_ % m};
      while (inb(k) && dd[i_] == -1) {
        dd[i_] = d--;
        k = ex(k, cc[i_]), i_ = k[0] * m + k[1];
      }
      if (dd[i] > ans) ans = dd[i], ansp = i;
    }
    array<int, 2> p = {ansp / m, ansp % m};
    printf("%d %d %d\n", 1 + p[0], 1 + p[1], ans);
  }
}
