#include <bits/stdc++.h>
using namespace std;
int n, T, a[100005];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int f = 0, x;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      if (x == 1 && f == 0) f = i;
    }
    if (f == 0) {
      for (int i = 1; i <= n + 1; i++) printf("%d ", i);
      puts("");
      continue;
    }
    for (int i = 1; i < f; i++) printf("%d ", i);
    printf("%d ", n + 1);
    for (int i = f; i <= n; i++) printf("%d ", i);
    puts("");
  }
  return 0;
}
