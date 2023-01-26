#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, nxt[N], lst[N], p[N];
int main() {
  scanf("%d%d", &n, &m);
  int K = sqrt(n);
  for (int i = 0; ++i <= n;) {
    scanf("%d", &p[i]);
    nxt[i] = i;
    lst[p[i]] = i;
  }
  for (int i = 1; i <= n; i++)
    for (int k = 1; k <= K; k++) nxt[i] = p[nxt[i]];
  while (m--) {
    int opt, x, y;
    scanf("%d%d%d", &opt, &x, &y);
    if (opt == 2) {
      int ans = x;
      for (int i = 1; i <= y / K; i++) ans = nxt[ans];
      for (int i = y % K; i; i--) ans = p[ans];
      printf("%d\n", ans);
    } else {
      swap(p[x], p[y]);
      lst[p[x]] = x;
      lst[p[y]] = y;
      nxt[x] = x;
      for (int i = 1; i <= K; i++) nxt[x] = p[nxt[x]];
      int now = x;
      for (int i = 1; i <= K; i++) {
        now = lst[now];
        nxt[now] = lst[nxt[p[now]]];
      }
      nxt[y] = y;
      for (int i = 1; i <= K; i++) nxt[y] = p[nxt[y]];
      now = y;
      for (int i = 1; i <= K; i++) {
        now = lst[now];
        nxt[now] = lst[nxt[p[now]]];
      }
    }
  }
}
