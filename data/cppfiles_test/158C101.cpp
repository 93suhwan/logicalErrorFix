#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkMax(T &x, T y) {
  return (y > x) ? x = y, 1 : 0;
}
template <typename T>
bool chkMin(T &x, T y) {
  return (y < x) ? x = y, 1 : 0;
}
template <typename T>
void inline read(T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
  x *= f;
}
const int N = 10, M = 10000;
int n, m, ans[M];
pair<int, int> c[M];
long long x[N], val;
int s[N][M];
int main() {
  int T;
  read(T);
  while (T--) {
    val = -9e18;
    read(n), read(m);
    for (int i = 0; i < n; i++) read(x[i]);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) scanf("%1d", &s[i][j]);
    for (int i = 0; i < (1 << n); i++) {
      long long ret = 0;
      for (int j = 0; j < m; j++) c[j].first = 0, c[j].second = j;
      for (int j = 0; j < n; j++) {
        int t = (i >> j & 1) ? 1 : -1;
        for (int k = 0; k < m; k++) {
          if (s[j][k]) c[k].first += t;
        }
        if (t == 1)
          ret -= x[j];
        else
          ret += x[j];
      }
      sort(c, c + m);
      for (int j = 0; j < m; j++) ret += c[j].first * (j + 1ll);
      if (chkMax(val, ret)) {
        for (int j = 0; j < m; j++) ans[c[j].second] = j;
      }
    }
    for (int i = 0; i < m; i++) printf("%d ", ans[i] + 1);
    puts("");
  }
  return 0;
}
