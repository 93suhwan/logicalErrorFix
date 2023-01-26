#include <bits/stdc++.h>
using namespace std;
int s[100008], t[100008];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, maxn = -1, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      maxn = max(maxn, s[i]);
    }
    while (1) {
      if (s[n] == maxn) {
        break;
      } else {
        queue<int> Q;
        int r = 0;
        for (int i = 1; i <= n; i++) {
          if (s[i] <= s[n]) {
            t[++r] = s[i];
          } else
            Q.push(s[i]);
        }
        while (!Q.empty()) {
          int q = Q.front();
          t[++r] = q;
          Q.pop();
        }
        for (int i = 1; i <= n; i++) s[i] = t[i];
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
