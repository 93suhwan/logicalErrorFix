#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, a[N], b[N], cnt[N], tot[N], s[305][305];
void solve() {
  scanf("%d%d", &n, &m);
  memset(s, 0, sizeof(s));
  for (int i = 1; i <= n * m; i++) scanf("%d", &a[i]), b[i] = a[i];
  sort(b + 1, b + n * m + 1);
  int sz = unique(b + 1, b + n * m + 1) - b - 1;
  int ans = 0;
  for (int i = 1; i <= n * m; i++) cnt[i] = tot[i] = 0;
  for (int i = 1; i <= n * m; i++) {
    int x = lower_bound(b + 1, b + sz + 1, a[i]) - b;
    cnt[x]++;
    a[i] = x;
  }
  for (int i = 1; i <= sz; i++) cnt[i] += cnt[i - 1];
  for (int i = 1; i <= n * m; i++) {
    int l = cnt[a[i] - 1] + 1, r = cnt[a[i]];
    int x = l + tot[a[i]];
    tot[a[i]]++;
    int p = (x - 1) / m + 1;
    for (int j = 1; j < a[i]; j++) ans += s[p][j];
    s[p][a[i]]++;
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
