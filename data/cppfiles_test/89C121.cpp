#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int T, n, a[maxn], tot;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    bool ans = 1;
    for (int i = 1; i <= n; i++) {
      int l = 2, r = i + 1;
      bool flag = 0;
      for (int k = l; k <= r; k++) {
        if (a[i] % k != 0) {
          flag = 1;
          break;
        }
      }
      if (!flag) {
        ans = 0;
        break;
      }
    }
    if (ans)
      puts("YES");
    else
      puts("NO");
  }
}
