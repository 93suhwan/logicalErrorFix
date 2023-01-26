#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
inline int read() {
  int x = 0;
  int f = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    f |= (ch == '-') ? 1 : 0;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return f ? -x : x;
}
const int maxn = 2e5 + 10;
int n, t, k;
int aa[maxn], vis[maxn], vis1[maxn], id[maxn];
int cmp(int a, int b) { return aa[a] < aa[b]; }
int main() {
  t = read();
  while (t--) {
    n = read();
    k = read();
    for (int i = 1; i <= n; ++i) vis[i] = vis1[i] = 0, id[i] = i;
    for (int i = 1; i <= n; ++i) {
      aa[i] = read();
      ++vis[aa[i]];
    }
    int g = 0;
    for (int i = 1; i <= n; ++i)
      if (vis[i] > k)
        g += k;
      else
        g += vis[i];
    int u = g / k;
    sort(id + 1, id + n + 1, cmp);
    int tmp = 1, tmp1 = 1;
    int o = 1;
    for (int i = 1; i <= n; ++i)
      if (o <= u) {
        if (i == 1 || aa[id[i]] != aa[id[i - 1]])
          tmp = 1;
        else {
          ++tmp;
        }
        if (tmp <= k) {
          vis1[id[i]] = tmp1++;
          if (tmp1 > k) tmp1 = 1, ++o;
        }
      }
    for (int i = 1; i <= n; ++i) {
      if (i != 1) printf(" ");
      printf("%d", vis1[i]);
    }
    printf("\n");
  }
}
