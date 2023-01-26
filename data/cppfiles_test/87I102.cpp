#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, x, y, t;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int ans = 0;
    for (i = 1; i <= n; i++) scanf("%d", &x), ans = max(ans, abs(x - i));
    printf("%d\n", ans);
  }
}
