#include <bits/stdc++.h>
using namespace std;
int n, m;
int ex(int pp, char c) {
  array<int, 2> p = {pp / m, pp % m};
  if (c == 'L')
    p[1]--;
  else if (c == 'R')
    p[1]++;
  else if (c == 'U')
    p[0]--;
  else
    p[0]++;
  return p[0] * m + p[1];
}
int inb(int pp) {
  array<int, 2> p = {pp / m, pp % m};
  if (p[0] < 0 || p[0] >= n || p[1] < 0 || p[1] >= m) return 0;
  return 1;
}
vector<int> pr[2000 * 2000];
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
      if (dd[i]) continue;
      i_ = i, d = 0;
      while (inb(i_) && dd[i_] == 0) {
        d++, dd[i_] = -1;
        i_ = ex(i_, cc[i_]);
      }
      if (!inb(i_))
        ;
      else if (dd[i_] != -1)
        d += dd[i_];
      else {
        int c = 0;
        while (inb(i_) && dd[i_] == -1) {
          c++, dd[i_] = -2;
          i_ = ex(i_, cc[i_]);
        }
        while (inb(i_) && dd[i_] == -2) {
          dd[i_] = c;
          i_ = ex(i_, cc[i_]);
        }
      }
      i_ = i;
      while (inb(i_) && dd[i_] == -1) {
        dd[i_] = d--;
        i_ = ex(i_, cc[i_]);
      }
      if (dd[i] > ans) ans = dd[i], ansp = i;
    }
    array<int, 2> p = {ansp / m, ansp % m};
    printf("%d %d %d\n", 1 + p[0], 1 + p[1], ans);
    for (int i = 0; i < n * m; i++) {
      pr[i].clear();
    }
  }
}
