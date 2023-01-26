#include <bits/stdc++.h>
using namespace std;
int s[200008];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, maxn = -1, ans = 0, pos1 = 0, pos2 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &s[i]);
      if (s[i] >= maxn) {
        if (s[i] > maxn) pos1 = i;
        pos2 = i;
        maxn = s[i];
      }
    }
    int minn = s[n];
    for (int i = n - 1; i >= pos2; i--) {
      if (s[i] > minn) {
        minn = s[i];
        ans++;
      }
    }
    for (int i = pos1; i <= pos2; i++) {
      if (s[i] < s[n]) {
        ans++;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
