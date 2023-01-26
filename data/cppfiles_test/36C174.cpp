#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += a[i];
    bool flag = 0;
    for (int i = 2; i < sum; ++i)
      if (sum % i == 0) flag = 1;
    if (flag) {
      printf("%d\n", n);
      for (int i = 1; i <= n; ++i) printf("%d ", i);
      puts("");
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      if ((sum - a[i]) % 2 == 0) {
        printf("%d\n", n - 1);
        for (int j = 1; j <= n; ++j)
          if (j != i) printf("%d ", j);
        puts("");
        break;
      }
    }
  }
  return 0;
}
