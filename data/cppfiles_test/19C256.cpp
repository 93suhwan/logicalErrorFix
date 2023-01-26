#include <bits/stdc++.h>
using namespace std;
int T, n, a[20], b[20], fl, tmp, top;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] = abs(a[i]);
    fl = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] == 0) fl = 1;
    if (fl) {
      printf("YES\n");
      continue;
    }
    for (int i = 1; i <= n; i++) {
      top = 0;
      for (int j = 1; j <= n; j++)
        if (j != i) b[top++] = a[j];
      for (int _ = 0; _ < (1 << (n - 1)); _++)
        for (int _1 = 0; _1 < (1 << (n - 1)); _1++) {
          tmp = 0;
          for (int j = 0; j < n - 1; j++)
            if (_ & (1 << j)) {
              if (_1 & (1 << j))
                tmp += b[j];
              else
                tmp -= b[j];
            }
          if (tmp == a[i]) fl = 1;
        }
    }
    if (fl)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
