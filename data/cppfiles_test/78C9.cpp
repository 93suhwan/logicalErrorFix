#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5, MAXM = MAXN;
int T, maxx, tot, js[MAXN], n, vis[MAXN];
void clear() {
  memset(js, 0, sizeof js);
  tot = 0;
}
void in() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    for (int j = 30; j >= 0; j--)
      if ((x >> j) & 1) js[j]++;
  }
}
void work() {
  for (int i = 0; i <= 29; i++) {
    if (!js[i]) continue;
    tot++;
    for (int j = 1; j <= sqrt(js[i]); j++) {
      if (js[i] % j) continue;
      vis[js[i] / j]++;
      if (js[i] / j != j) vis[j]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == tot) printf("%d ", i);
    vis[i] = 0;
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    clear();
    in();
    work();
    puts("");
  }
  return 0;
}
