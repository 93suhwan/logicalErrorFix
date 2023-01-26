#include <bits/stdc++.h>
char s[100011], t[100011];
bool vis[100011];
int T, n;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%s%s", &n, s + 1, t + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) vis[i] = 0;
    for (int i = 1; i <= n; ++i) {
      if (s[i] != t[i]) {
        if (i > 1 && !vis[i - 1]) ans += '1' - s[i - 1];
        ans += 2, vis[i] = 1;
      } else {
        if (i > 1 && !vis[i - 1] && (s[i] != s[i - 1])) {
          ans += 2;
          vis[i] = 1;
        } else if (i > 1 && !vis[i - 1]) {
          ans += '1' - s[i - 1];
        }
      }
    }
    if (!vis[n]) ans += '1' - s[n];
    printf("%d\n", ans);
  }
  return 0;
}
