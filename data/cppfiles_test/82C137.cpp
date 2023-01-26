#include <bits/stdc++.h>
const int maxn = 300005;
int n, q, l, r, f[maxn];
char a[maxn];
std::set<int> v[maxn * 4 + 5];
void solve() {
  scanf("%d%d", &n, &q);
  scanf("%s", a + 1);
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] + (a[i] == '+' ? 1 : -1) * (i & 1 ? 1 : -1);
    v[f[i] + f[i - 1] + maxn + maxn].clear();
  }
  for (int i = 1; i <= n; i++) v[f[i] + f[i - 1] + maxn + maxn].insert(i);
  while (q--) {
    scanf("%d%d", &l, &r);
    if (f[r] == f[l - 1]) {
      printf("0\n");
    } else {
      if ((r - l) & 1)
        printf("2\n%d ", l), l++;
      else
        printf("1\n");
      printf("%d\n", *v[f[l - 1] + f[r] + maxn + maxn].lower_bound(l));
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
