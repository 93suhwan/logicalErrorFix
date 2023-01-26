#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 100;
int t, n, m, MAX[N], suc[N], ok[N];
vector<int> tmp[N], a[N], p[N], vi[N];
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
signed main() {
  t = read();
  while (t--) {
    n = read();
    m = read();
    for (int i = 0; i < n; i++) tmp[i].resize(m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) tmp[i][j] = read();
    for (int i = 0; i < m; i++) a[i].resize(n), vi[i].resize(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) a[j][i] = tmp[i][j];
    swap(n, m);
    for (int i = 0; i < n; i++) {
      p[i].clear();
      MAX[i] = *max_element(a[i].begin(), a[i].end());
      for (int j = 0; j < m; j++)
        if (a[i][j] == MAX[i]) p[i].push_back(j);
    }
    suc[n] = -0x3f3f3f3f;
    for (int i = n - 1; i >= 0; i--) {
      vi[i] = vi[i + 1];
      if (MAX[i] > suc[i + 1])
        for (int &j : vi[i]) j = 0;
      for (int j : p[i]) vi[i][j] = 1;
    }
    int pre = -0x3f3f3f3f;
    bool bl = 1;
    for (int j = 0; j < m; j++) ok[j] = 0;
    for (int i = 0; i < n - 1; i++) {
      if (MAX[i] > pre)
        for (int j = 0; j < m; j++) ok[j] = 0;
      for (int j : p[i]) ok[j] = 1;
      bool fd = 1;
      for (int j = 0; j < m; j++)
        if (ok[j] & vi[i + 1][j]) fd = 0;
      if (fd) {
        printf("YES\n");
        for (int j = 0; j < m; j++) {
          if (ok[j])
            printf("R");
          else
            printf("B");
        }
        printf(" %d\n", i + 1);
        bl = 0;
        break;
      }
    }
    if (bl) printf("NO\n");
  }
}
