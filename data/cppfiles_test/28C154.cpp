#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000;
int te, n, m, a[maxn + 5], b[maxn + 5], cnt[maxn + 5];
int nxt[maxn + 5], ans[maxn + 5], ti, vis[maxn + 5];
bool check() {
  for (int i = 1; i <= n; i++) nxt[i] = b[i];
  int cnt = 0;
  ti++;
  for (int i = 1; i <= n; i++)
    if (vis[i] < ti) {
      for (int j = nxt[i]; j != i; j = nxt[j]) vis[j] = ti;
      vis[i] = ti;
      cnt++;
    }
  return n - cnt <= m;
}
int main() {
  for (scanf("%d", &te); te; te--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[(i - a[i] + n) % n]++;
    ans[0] = 0;
    for (int k = 0; k < n; k++)
      if ((n - cnt[k]) / 2 <= m) {
        for (int i = 1, j = k + 1; i <= n; i++, j = j % n + 1) b[i] = a[j];
        if (check()) ans[++ans[0]] = k;
      }
    printf("%d", ans[0]);
    for (int i = 1; i <= ans[0]; i++) printf(" %d", ans[i]);
    puts("");
  }
  return 0;
}
