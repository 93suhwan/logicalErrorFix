#include <bits/stdc++.h>
using namespace std;
int ans[10000];
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    int s, n;
    scanf("%d%d", &s, &n);
    int a = s, tot = 0;
    while (a) {
      tot += a % 10;
      a /= 10;
    }
    if (tot >= n) {
      int e = 1;
      ans[0] = 0;
      while (ans[0] + 1 < n) {
        if (s / e % 10 > 0) {
          s -= e;
          ans[++ans[0]] = e;
        } else
          e *= 10;
      }
      ans[n] = s;
    } else {
      for (int i = 1; i < n; i++) ans[i] = 1;
      ans[n] = s - n + 1;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    puts("");
  }
}
