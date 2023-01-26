#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
const int N = 105;
int T, n, a[N];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int s = 0, pos;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      s += a[i];
      if (a[i] % 2) pos = i;
    }
    bool flag = false;
    for (int i = 2; i < s; ++i) {
      if (s % i == 0) {
        flag = true;
        break;
      }
    }
    if (flag) {
      printf("%d\n", n);
      for (int i = 1; i <= n; ++i) {
        printf("%d%c", i, i == n ? '\n' : ' ');
      }
    } else {
      printf("%d\n", n - 1);
      int cnt = 0;
      for (int i = 1; i <= n; ++i) {
        if (i == pos) continue;
        printf("%d%c", i, ++cnt == n - 1 ? '\n' : ' ');
      }
    }
  }
  return 0;
}
