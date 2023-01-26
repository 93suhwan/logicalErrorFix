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
      int e = 1;
      ans[0] = 0;
      while (s) {
        if (s / e % 10 > 0) {
          s -= e;
          ans[++ans[0]] = e;
        } else
          e *= 10;
      }
      while (ans[0] != n) {
        int ma = n + 1;
        ans[n + 1] = 1000000001;
        for (int i = 1; i <= ans[0]; i++)
          if (ans[ma] > ans[i] && ans[i] != 1) ma = i;
        int a = ans[ma];
        int e = 1;
        while (e * 10 <= ans[ma]) e *= 10;
        e /= 10;
        int tt = 9;
        while (tt-- && ans[0] < n) {
          ans[++ans[0]] = e;
          ans[ma] -= e;
        }
      }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    puts("");
  }
}
