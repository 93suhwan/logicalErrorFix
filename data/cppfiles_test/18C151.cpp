#include <bits/stdc++.h>
using namespace std;
int n, k, st[205], ed[205], mk[205];
inline bool judge(int x, int y) {
  return (st[x] < st[y] && st[y] < ed[x]) ^ (st[x] < ed[y] && ed[y] < ed[x]);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    memset(mk, 0, sizeof(mk));
    for (int i = 1; i <= k; i++) {
      scanf("%d%d", st + i, ed + i), mk[st[i]] = mk[ed[i]] = 1;
      if (st[i] > ed[i]) swap(st[i], ed[i]);
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
      int tmp = 0;
      for (int j = st[i]; j <= ed[i]; j++) tmp += (!mk[j]);
      ans += min(tmp, n * 2 - k * 2 - tmp);
      for (int j = i + 1; j <= k; j++) ans += judge(i, j);
    }
    printf("%d\n", ans + (n - k) * (n - k - 1) / 2);
  }
  return 0;
}
