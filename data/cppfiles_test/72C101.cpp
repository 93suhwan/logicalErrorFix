#include <bits/stdc++.h>
using namespace std;
int k, cnt[1024], len, n, ans;
char st[15];
void dfs(bool limit, int pos, int Bit, int x) {
  if (ans != INT_MAX) return;
  if (pos == len + 1) {
    if (x >= n) ans = min(ans, x);
    return;
  }
  int min = INT_MAX;
  for (int i = (limit ? (st[pos] - '0') : 0); i <= 9; ++i) {
    if (cnt[Bit | (1 << i)] <= k)
      dfs(limit & (i == (st[pos] - '0')), pos + 1, Bit | (1 << i), x * 10 + i);
  }
}
int main() {
  int tmp;
  scanf("%d", &tmp);
  cnt[0] = 0;
  for (int i = 1; i < 1024; ++i) cnt[i] = cnt[i - (i & (-i))] + 1;
  while (tmp--) {
    scanf("%s", st + 1);
    len = strlen(st + 1);
    n = 0;
    for (int i = 1; i <= len; ++i) n = n * 10 + (st[i] - '0');
    scanf("%d", &k);
    ans = INT_MAX;
    dfs(1, 1, 0, 0);
    printf("%d\n", ans);
  }
  return 0;
}
