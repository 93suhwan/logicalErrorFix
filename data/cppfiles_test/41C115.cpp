#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
char s[maxn];
const char ori[6][10] = {"abc", "acb", "bac", "bca", "cab", "cba"};
char a[6][maxn];
int cnt[6][maxn], n, m;
signed main() {
  cin >> n >> m;
  cin >> s + 1;
  for (int k = 0; k <= 5; k++)
    for (int i = 1; i <= n; i++) a[k][i] = ori[k][i % 3];
  for (int k = 0; k <= 5; k++)
    for (int i = 1; i <= n; i++) cnt[k][i] = cnt[k][i - 1] + (s[i] != a[k][i]);
  while (m--) {
    int l, r, ans = 0x7fffffff;
    cin >> l >> r;
    for (int k = 0; k <= 5; k++) ans = min(ans, cnt[k][r] - cnt[k][l - 1]);
    printf("%d\n", ans);
  }
}
