#include <bits/stdc++.h>
using namespace std;
char s1[200010];
char s2[200010];
int vis[200010];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s1);
    scanf("%s", s2);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s2[i] == '0') {
        continue;
      }
      if (s1[i] == '0' && !vis[i]) {
        vis[i] = 1;
        ans++;
      } else {
        if (i >= 1 && s1[i - 1] == '1' && !vis[i - 1]) {
          vis[i - 1] = 1;
          ans++;
        } else {
          if (i + 1 < n && s1[i + 1] == '1' && !vis[i + 1]) {
            vis[i + 1] = 1;
            ans++;
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      vis[i - 1] = 0;
    }
    printf("%d\n", ans);
  }
  return 0;
}
